#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdbool.h> // true, false _Bool
#include <stdlib.h> // malloc
#include <stdio.h> // fopen, fclose ...
#include <string.h> // strcmp, strcpy ...
#include <dirent.h> // diropen, readdir ...
#include <time.h> // ctime ...
#include <readline/readline.h>
#include <readline/history.h>

#define FIND_BUFF_SIZE 1024
#define BUFF_SIZE 1024
#define RESPONSE_DATA_SIZE 240 // les then a char

#define LOGIN_FILE "usernames.txt"
#define LOGIN "login"
#define QUIT "quit"
#define MYFIND "myfind"
#define MYSTAT "mystat"
#define FIFO_NAME ".fifo_test"

/* ========== Utils ========== */
void removeSubstring(char *s,const char *toremove)
{
  while( s=strstr(s,toremove) )
    memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));
}



/* ========== Protocol Utils ========== */
struct response{
    char length;
    char* data;
};

struct response *parse_response(int fd){
    /* Parse a response.
     *
     * :pram fd: file descriptor from which to read 
     * :return: A pointer to a response structure.
     * :rtype: response pointer
     * */
    /* struct response *ret = malloc(sizeof(response)); */
    struct response *ret = malloc(sizeof *ret);
    ret->data = malloc(RESPONSE_DATA_SIZE + 2); 
    char length = 0;
    switch (read(fd, &length, sizeof(length))) {
        case -1:
            // could not read
            perror("ERROR: reading response!");exit(8);       break;
        case 0:
            // read nothing 
            ret->length = 0;
            ret->data = NULL;
            break;
        case 1:
            // read okay
            ret->length = length;
            char test_length = read(fd, ret->data, length);
            if ((int)length > test_length){
                fprintf(stderr, "Not all data arived. \n");
                // NOTE(mmicu): this is a bad idea, we should read in a buffer and
                //              wait for more data to appear until we have
                //              `legth` bytes
                ret->length = test_length;
            }
    }
    return ret;
}

struct response *create_response(char *st){
    /* Get a string an craft a response.
     * If the information in the response is too big it will get truncated.
     * This might change in the future.
     * :param st: The data we want to send.
     * :type st: char pointer
     *
     * :return: A response structure with everything defined
     * :rtype: response pointer
     */
    
    struct response *ret = malloc(sizeof *ret);
    // NOTE(mmicu): this is bad, we lose data. But the reciver is not smart enough
    // to read in a buffer and recive append new data to an incomplet response.
    // Might be improved in the future!
    /* ret->length = strlen(st) < RESPONSE_DATA_SIZE ? strlen(st) : RESPONSE_DATA_SIZE; */
    if(strlen(st) < RESPONSE_DATA_SIZE){
        ret->length = (int)strlen(st);
    }else{
        ret->length = RESPONSE_DATA_SIZE;
    }
    ret->data = malloc(BUFF_SIZE);
    strncpy(ret->data, st, ret->length);
    // add the null terminator for safety
    ret->data[ret->length] = '\0';
    return ret;
}


void delete_response(struct response *resp){
    /* Delete a response structure.
     * 
     * :param resp: A pointer to a valid resp structure.
     */
    
    free(resp->data);
    free(resp);
}

char* serialize_response(struct response *resp){
    /* Return a pointer to a string containing the serialized
     * string of a response.
     *
     * :param resp: A response
     * :type resp: response pointer
     *
     * :return: The string
     * :rtype: char pointer
     */
    if (resp->length < 0 || resp->data == NULL)
        return NULL;
    char *data = malloc(RESPONSE_DATA_SIZE+1);
    data[0] = resp->length;
    strcpy(data+1, resp->data);
    return data;
}

void send_response(int fd, struct response *resp){
    /* Send a response using the fd.
     *
     * :param fd: what to use to send the response
     * :type fd: file descriptor
     * :param response: what response to send
     * :type response: response pointer
     */
    char *data = serialize_response(resp);
    write(fd, data, strlen(data));
}

char* read_command(int fd){
    /* Read byts from `fd` and retun the string command.
     *
     * :pram fd: file descriptor from which to read 
     * :return: A pointer to a string
     * :rtype: char pointer
     * 
     */
    char *buff = malloc(BUFF_SIZE),
         aux = 0;
    memset(buff, 0, sizeof(buff));
    int i = 0, size = 0;
    for(i = 0; i < BUFF_SIZE && aux != '\n'; i++){
        if((size = read(fd, &aux, sizeof(aux))) < 0 ) {
            perror("ERROR: reading response!");
            exit(7);
        }
        if(size == 0)
            return NULL;
        buff[i] = aux;
    }
    buff[i] = '\0';
    return buff;
}

/* ========== Commands Utils ========== */
_Bool login(char* username){
    /* Check if a username is valid.
     *
     *
     * Read the posible usernames from `usernames.txt` and compare them to the 
     * given username.
     * :param username: Pointer to a array of chars that repesent the username.
     * :return: true or false depeinding if the username was found in the file.
     * :rtype: bool
     */
    FILE *file = fopen(LOGIN_FILE, "r");

    if(! file){
        fprintf(stderr,"[ P1 ] ERROR: opening %s \n", LOGIN_FILE);
        perror(NULL);
        exit(1);
    }
    char test_username[100];
    while(fgets(test_username, 100, file)){
        // eliminate the new line if it's present
        int i;
        for(i=0; test_username[i] != '\0'; i++)
            if(test_username[i] == '\n')
                test_username[i] = '\0';

        for(i=0; username[i] != '\0'; i++)
            if(username[i] == '\n')
                username[i] = '\0';

        // check if the username is valid
        if(strcmp(username, test_username) == 0)
            return true;

    }

    if(fclose(file) == EOF){
        fprintf(stderr,"[ P1 ] ERROR: closing %s \n", LOGIN_FILE);
        perror(NULL);
        exit(2);

    }
    return false;
}


char *mystat(char* path){
    /* Retun a pointer to a formated string with info about the item at the `path`
     *
     * :param path: The file path
     * :type path: chat pointer
     *
     * :return: pointer to a char array
     * :rtype: pointer char
     *
     * We will format a string that will have this format:
     * ```
     * FILE_PATH:<file_type>:<r/w/x/- for the user>:<r/w/x/- for the group>:
     * <r/w/x/- for others>:<owner user id>:<owner group id>:
     * <creation time>:<last acces time>:<last modification time>:<size in KB>
     * ```
     */
    int buff_size = 1534;
    char format[] = "%s:%c:%c%c%c:%c%c%c:%c%c%c:%ld:%ld:%s:%s:%s:%ld",
         *string = (char *)malloc(buff_size * sizeof(char));
    struct stat fileStat;
    if(stat(path, &fileStat) < 0){
        perror("ERROR: geting info about a file.");
        return NULL;
    }
    char file_type, own_r, own_w, own_x, grp_r, grp_w, grp_x,
         oth_r, oth_w, oth_x, crt_time[100], act_time[100], mod_time[100];
    long size = 0, own_id, grp_id;

    // type of file
    switch (fileStat.st_mode & S_IFMT) {
        case S_IFBLK:  file_type = 'b';      break;
        case S_IFCHR:  file_type = 'c';      break;
        case S_IFDIR:  file_type = 'd';      break;
        case S_IFIFO:  file_type = 'p';      break;
        case S_IFLNK:  file_type = 'l';      break;
        case S_IFREG:  file_type = '-';      break;
        case S_IFSOCK: file_type = 's';      break;
        default:       file_type = 'u';      break;
    }

    // rights
    own_r = fileStat.st_mode & S_IRUSR ? 'r' : '-';
    own_w = fileStat.st_mode & S_IWUSR ? 'w' : '-';
    own_x = fileStat.st_mode & S_IXUSR ? 'x' : '-';

    grp_r = fileStat.st_mode & S_IRGRP ? 'r' : '-';
    grp_w = fileStat.st_mode & S_IWGRP ? 'w' : '-';
    grp_x = fileStat.st_mode & S_IXGRP ? 'x' : '-';

    oth_r = fileStat.st_mode & S_IROTH ? 'r' : '-';
    oth_w = fileStat.st_mode & S_IWOTH ? 'w' : '-';
    oth_x = fileStat.st_mode & S_IXOTH ? 'x' : '-';

    own_id = fileStat.st_uid;
    grp_id = fileStat.st_gid;

    strftime(crt_time, 100, "%B %d %Y", localtime(&fileStat.st_ctime));
    strftime(act_time, 100, "%B %d %Y", localtime(&fileStat.st_atime));
    strftime(mod_time, 100, "%B %d %Y", localtime(&fileStat.st_mtime));

    size = (long long)fileStat.st_size / 1024;

    sprintf(string, format, path, file_type, own_r, own_w, own_x, grp_r, grp_w, grp_x,
            oth_r, oth_w, oth_x, own_id, grp_id, crt_time, act_time, mod_time, size);

    return string;
}

int search_dir(char* path, char* string, char** out){
    /* Search a file with name `sting` and print informations about it
     *
     * :param path: The root path from which to start searching.
     * :type path: char pointer
     * :param string: Name of the file we search for.
     * :type string: char pointer
     * :return: number of hits
     * :param out: pointer to an array of pointers that will point to the data
     * :type out: char pointer pointer
     * :rtype: int
     * The function will print to stdout information of every file with 
     * `string` name it can find, each appearance separated by a new line `\n`.
     *
     * NOTE(mmicu): Duplicate stdout to redirect the output to the child
     */
    int hits = 0;
    DIR *dir;
    struct dirent *dp;
    if((dir = opendir(path)) == NULL){
        fprintf(stderr, "We could not open %s \n", path);
        perror(NULL);
        return false;
    }

    while( (dp = readdir(dir)) !=NULL ){
        // filter only directoris and files
        if(dp->d_type != DT_DIR && dp->d_type != DT_REG)
            continue;

        // elimiate `.` and `..`
        if(strcmp(dp->d_name, ".") == 0 ||
           strcmp(dp->d_name, "..") ==0)
            continue;

        // compute directory full path
        char cur_path[2048];
        strcpy(cur_path, path);
        strcat(cur_path, "/");
        strcat(cur_path, dp->d_name);

        // check if the name matches
        if(strcmp(dp->d_name, string) == 0 && dp->d_type == DT_REG){
            hits++; // count a hit
            char *info;
            info = mystat(cur_path);
            // NOTE(mmicu): if the index gets bigged then the array we have
            //              we might get Segmentation Fault! this is why we ignore
            //              the hits that exceed out buffer size.
            int index = 0;
            while(out[index] != NULL)
                index++;
            if(index < FIND_BUFF_SIZE)
                out[index] = info;

        }

        if(dp->d_type == DT_DIR)
            // update the hit number
            hits += search_dir(cur_path, string, out);

    }

    if(closedir(dir) == -1){
        perror("Can't close directory.\n");
    }

    return hits;
}

/* ========== Commands ========== */
char **myfind(char *file_name){
    /* Find a file by name and informations about that file.
     *
     * :param file_name: The file name we need to seach.
     * :type: char pointer
     * :return: Array of pointers to information on every hit.
     * :rtype: char pointer pointer
     * If more files with the same name are present count them.
     *
     */
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
       perror("ERROR: getcwd() error");
       exit(3);
    }
    char** info = (char**)malloc(FIND_BUFF_SIZE);
    memset(info, 0, sizeof(info));
    int hits = search_dir(cwd, file_name, info);
    return info;
}

char *string_myfind(char *file_name){
    /*
     * :param file_name: The file name we need to seach.
     * :type: char pointer
     * :return: All the info with a \n delimitator
     * :rtype: char pointer
     * If more files with the same name are present count them.
     */
    int max_size = FIND_BUFF_SIZE * RESPONSE_DATA_SIZE;
    char *info = malloc(max_size);
    memset(info, 0, sizeof(info));
    int i;
    char **data = myfind(file_name);
    // NOTE(mmicu): a good aproach is to send multiple responses, but the "protocol" can't 
    //              handle that for now. We are just going to fir what we can in the avalible data buffer.
    //
    // NOTE(mmicu): Also this jogging with null pointers is not nice, a structure and methods over that structure
    //              would make more sense.
    for(i = 0; data[i] != NULL; i++) {
        int left_size = max_size - strlen(info) - 1;
        strncpy(info, data[i], left_size);
    }
    info[max_size-1] = '\0';
    return info;
}

/* ========== Child ========== */

void main_child_sockets(int socket){
    /* Main body if the child.
     *
     * :param socket: A socket fd to comunicate with the parent.
     * :type socket: int
     *
     * This child will handle some commands like: myfind and mystat
     */
    _Bool login_state = false; // the login is made in the child processes 
    char *buff = malloc(1);  // we compare this and we need to make sure is not random
    struct response *r;
    buff[0]='\0';
    while(buff != NULL &&strncmp(buff, QUIT, strlen(QUIT)) != 0){
        memset(buff, 0, sizeof(buff));
        buff = read_command(socket);
        if(buff == NULL){
            printf("C1 null \n");
            continue;
        }
        if(strncmp(buff, LOGIN, strlen(LOGIN)) == 0){
            removeSubstring(buff, LOGIN);
            removeSubstring(buff, " ");
            login_state = login(buff);

            if(login_state){
                r = create_response("ok");
            }else{
                r = create_response("bad");
            }
            send_response(socket, r);
            delete_response(r);
            // NOTE(mmicu): bad idea but we have to exclude the command of this form
            //              `login mystat` where mystat is a valid username
            continue;
        }
        if( ! login_state ){
            r = create_response("bad username");
            send_response(socket, r);
            delete_response(r);
            continue;
        }

        if(strncmp(buff, MYSTAT, strlen(MYSTAT)) == 0){
            removeSubstring(buff, MYSTAT);
            removeSubstring(buff, " ");
            removeSubstring(buff, "\n");
            char *info = mystat(buff);
            if(info != NULL){
                r = create_response(info);
            }else{
                r = create_response("err");
            }
            send_response(socket, r);
            delete_response(r);
            continue;
        }

        if(strncmp(buff, QUIT, strlen(QUIT)) == 0){
            // we need to clean up everything
            close(socket);
            continue;
        }


        r = create_response("unknown");
        send_response(socket, r);
        delete_response(r);
    }
}

void main_child_pipes(int pipe, char* fifo_name){
    /* Main body if the child.
     *
     * :param pipe: A pipe fd(read) to get comunicate with the parent.
     * :type pipe: int
     * :param firo: A filename, for writing.
     * :type fifo: char pointer
     *
     * This child will handle some commands like: login
     */
    // NOTE(mmicu): This is not good, we don't need this child, but because we need to use 
    //              pipe's and fifo's we have to force this.
    _Bool login_state = false; // the login is made in the child processes 
    char *buff = malloc(1);
    buff[0] = '\0';

    int fifo = open(fifo_name, O_WRONLY);
    struct response *r;
    // NOTE(mmicu): redundant code, this could be refactored
    while(strncmp(buff, QUIT, strlen(QUIT)) != 0){
        memset(buff, 0, sizeof(buff));
        buff = read_command(pipe);
        if(buff == NULL){
            printf("C1 null");
            continue;
        }

        if(strncmp(buff, LOGIN, strlen(LOGIN)) == 0){
            removeSubstring(buff, LOGIN);
            removeSubstring(buff, " ");
            login_state = login(buff);

            if(login_state){
                r = create_response("ok");
            }else{
                r = create_response("bad");
            }
            send_response(fifo, r);
            delete_response(r);
            // NOTE(mmicu): bad idea but we have to exclude the command of this form
            //              `login mystat` where mystat is a valid username
            continue;
        }
        if( ! login_state ){
            r = create_response("bad username");
            send_response(fifo, r);
            delete_response(r);
            continue;
        }

        if(strncmp(buff, MYFIND, strlen(MYFIND)) == 0){
            removeSubstring(buff, MYFIND);
            removeSubstring(buff, " ");
            removeSubstring(buff, "\n");
            char *stuff = string_myfind(buff);
            if(stuff[0] != '\0' ){
                r = create_response(stuff);
            }else{
                r = create_response("err");
            }
            send_response(fifo, r);
            delete_response(r);
            continue;
        }

        if(strncmp(buff, QUIT, strlen(QUIT)) == 0){
            // we need to clean up everything
            close(fifo);
            close(pipe);
            continue;
        }

        r = create_response("unknown");
        send_response(fifo, r);
        delete_response(r);
    }
}

int main(){
    /* === setup the socket, fifo and pipe and the workers ===*/
    int sockp[2], pfd[2], pid_1, pid_2;
    
    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockp) < 0) { 
        perror("EROARE :socketpair socket \n"); 
        exit(10); 
    }
    if (pipe (pfd) == -1){
        perror("EROARE:pipe creation \n");
        exit(11);
    }
    // ==== child 1 
    pid_1 = fork();
    if(pid_1 == -1){
        perror("ERROARE: Could not make child 1 !\n");
        exit(12);
    }

    if(pid_1 == 0){
        // Close what is not needed;
        close(pfd[0]);
        close(pfd[1]);
        close(sockp[0]); 

        main_child_sockets(sockp[1]);
        exit(0);
    }

    // ==== child 1 
    pid_2 = fork();
    if(pid_2 == -1){
        perror("ERROARE: Could not make child 2 !\n");
        exit(13);
    }

    if(pid_2 == 0){
        // Close what is not needed;
        close(sockp[0]);
        close(sockp[1]);
        close(pfd[1]);
        main_child_pipes(pfd[0], FIFO_NAME);
        exit(0);
    }

    // ==== parent
    close(sockp[1]);
    close(pfd[0]);
    // NOTE(mmicu): We should check if the file is actually a fifo
    if(access(FIFO_NAME, F_OK|R_OK|W_OK) == -1){
        // we need to make the fifo file
        mknod(FIFO_NAME, S_IFIFO | 0666, 0);
    }

    int fifo = open(FIFO_NAME, O_RDONLY);
    int found = false;

    /* char *buff= malloc(BUFF_SIZE); */
    char buff[BUFF_SIZE];
    struct response *resp;
    while(strncmp(buff, QUIT, strlen(QUIT)) != 0){
        found = false;
        printf(">> ");
        memset(buff, 0, sizeof(buff));
        fgets(buff, sizeof(buff), stdin);
        /* readline(buff, sizeof(buff), stdin); */
        /* buff = getline(">> "); */
        if(strlen(buff) == BUFF_SIZE){
            fprintf(stderr, "The command is too long %s ! \n", buff);
            strcpy(buff, "quit");
        }
           

        // parse commands
        if(strncmp(buff, LOGIN, strlen(LOGIN)) == 0 && found == false){
            found = true;
            write(sockp[0], buff, strlen(buff));
            write(pfd[1], buff, strlen(buff));
        }
        if(strncmp(buff, MYFIND, strlen(MYFIND)) == 0 && found == false){
            // C1
            // NOTE(mmicu): Here is where MYFIND is called but because the 
            found = true;
            write(sockp[0], buff, strlen(buff));
            write(pfd[1], buff, strlen(buff));
            continue;
        }
        // ==== 
        if(strncmp(buff, MYSTAT, strlen(MYSTAT)) ==0 &&  found  == false){
            // C2
            found = true;
            write(sockp[0], buff, strlen(buff));
            write(pfd[1], buff, strlen(buff));
        }
        if(strncmp(buff, QUIT, strlen(QUIT)) == 0 && found == false){
            // C1 & C2
            found = true;
            write(sockp[0], buff, strlen(buff));
            write(pfd[1], buff, strlen(buff));
        }
        
        // wait for a response
        // NOTE(mmicu): This is the part that might block if we don't send to every sub-process 
        //              a "request". We could handle the message on every "command" (above if's)
        //              but this will introduce even more duplicat code. Every command should 
        //              keep in memoy what childs calls and we should listen only for there response, a more 
        //              dynamic way ...
        if(found){
            resp = parse_response(sockp[0]);
            if(resp != NULL && strcmp(resp->data, "unknown") != 0)
                printf("Rez :%s \n", resp->data);

            resp = parse_response(fifo);
            if(resp != NULL && strcmp(resp->data, "unknown") != 0)
                printf("Rez :%s \n", resp->data);
        }else{
            if(strlen(buff) > 0)
                printf("unknown command \n");
        }

    }
    return 0;
}
