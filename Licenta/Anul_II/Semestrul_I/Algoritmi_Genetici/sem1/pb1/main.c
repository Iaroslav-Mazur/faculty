/* Scrieti un program care simuleaza find in mod recursiv.
 */

/* Program care primeste ca argument nume de fisier sau folder si afiseaza data ultimei modificari si tipul fisierului
*/

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

void search(DIR *dir, char* str, char* path){

// TODO(mmicu): local_dir trebuie sa fie fiecare director dinr `dir`, need to implement that.
// Ai grija la memorie
	char *local_path[1000];
	strcmp(local_path, path);
	if( strcmp( str, local_dir->name) == 0){
		strcat(local_path, dir->name);
		printf("Found %s \n", local_path);
		search(local_dir, str, local_path)
	}
}

int main(int argc, char **argv)
{
    if(argc < 2){
        printf("Need an argument.\n");
        return 1;
    }

    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    printf("Search %s from %s \n", argv[1], cwd);

	DIR *dir;
	if( NULL == (dir = opendir(cwd)) ){
		printf("Errro: Could not open %s \n", cwd);
		return 2;
	}

	search(dir, argv[1]);
    
    return 0;
}
