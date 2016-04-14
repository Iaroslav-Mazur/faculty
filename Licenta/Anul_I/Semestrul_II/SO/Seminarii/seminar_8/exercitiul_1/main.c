#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char *argv[]){
	int freg[256];
	int i;
	for(i = 0; i < 256; i++){
		freg[i] = 0;
	}

	if(argc <= 1){
		printf("Nu am primit nici un parametru ");
		return 1;
	}else{
		int f;
		f = open(argv[1], O_RDONLY);
		
		if(f == -1){
			perror("Nu am putut deschide fisierul");
			return 2;
		}

		char buf;
		while(1){
			int r = read(f, &buf, sizeof(buf));

			if(r > 0){
				freg[buf] = freg[buf] + 1;
			}

			if(r == -1){
				close(f);
				perror("Nu am putut citi !");
				return 3;
			}

			if(r == 0){
				break;	
			}
		}

		close(f);
	}

	for(i = 0; i < 256; i++){
		if(freg[i] > 0){
			printf("%c - %d ( %d ) \n", i, freg[i], i);
		}
	}
	return 0;
}

