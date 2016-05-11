#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(){
    return 0;
    int f = open("comunicare.txt", O_RDWR);
    char c = 1;
    write(f, &c, sizeof(c));
    close(f);
    return 0;
}
