#include <stdio.h> // printf, fprinf ...
#include <dirent.h> // opendir, readdir ... 
#include <unistd.h>  // getcwd
#include <errno.h> // errno, perrno
// #include <sys/types.h>
#include <string.h> // strcat, strcmp, strcpy ...


void search_dir(char* path, char* string){
    DIR *dir; 
    struct dirent *dp;

    if((dir = opendir(path)) == NULL){
        fprintf(stderr, "We could not open %s \n", path);
        perror(NULL);
        return;
    }

    while( (dp = readdir(dir)) !=NULL ){
        // filter only directoris
        if(dp->d_type != DT_DIR || dp->d_type != DT_REG)
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
        if(strcmp(dp->d_name, string) == 0 && dp->d_type == DT_REG)
            printf("Found match: %s \n", cur_path);

        if(dp->d_type == DT_DIR)
            search_dir(cur_path, string);

    }

    if(closedir(dir) == -1){
        perror("Can't close directory.\n");
    }
}

int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "No argument given.\n");
        return 1;
    }
    printf("Searching for: %s \n", argv[1]);

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) == NULL)
       perror("getcwd() error");


    search_dir(cwd, argv[1]);

    return 0;
}
