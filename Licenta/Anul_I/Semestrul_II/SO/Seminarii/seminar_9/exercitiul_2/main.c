#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd;
	float val, aux;
	int pid = getpid();
	fd = open("peco.txt", O_RDWR);
	/* lock */
	struct flock lock;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = sizeof(float);

	if(fd == -1){
		fprintf(stderr, "PID : %d - ", pid);
		perror("Nu am putut deschide fisierul \n");
		exit(1);
	};

	/* parcurgem argumentele */
	int i;
	srand(pid);
	for(i = 1; i < argc; i++){	
		sleep( rand() % 3 );

		aux = atof(argv[i]);
		lseek(fd, 0, SEEK_SET);
		lock.l_type = F_WRLCK;					
		if(-1 == fcntl(fd, F_SETLKW, &lock) ){
			fprintf(stderr, "PID : %d - ", pid);
			perror("Nu am putut seta un lock \n");
			exit(2);
		}

		int r = read(fd, &val, sizeof(val) );

		if( r == -1 ){
			fprintf(stderr, "PID : %d - ", pid);
			perror("Nu am putut citit din fisier \n");
			exit(3);
		}
		float inainte = val;
		val = val + aux;	

		/* verificam daca avem destul combustibil */
		if( val < 0 ){
			val = 0;
		}

		printf("PID :  %d - Am avut %f a ramas %f \n", pid, inainte, val);
		
		/* scriere in fisier */
		lseek(fd, 0, SEEK_SET);
		if( sizeof(val) > write(fd, &val, sizeof(val)) ){
			fprintf(stderr, "PID : %d - ", pid);
			perror("Nu am putut scrie in fisier  \n");
			exit(4);
		}
		
		lock.l_type = F_UNLCK;
 		if(-1 == fcntl(fd, F_SETLK, &lock) ){
			fprintf(stderr, "PID : %d - ", pid);
			perror("Nu am putut seta un lock \n");
			exit(2);
		}
		
	}
	close(fd);
	return 0;
}

