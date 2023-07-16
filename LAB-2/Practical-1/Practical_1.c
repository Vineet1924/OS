#include <stdio.h>
#include <unistd.h>

void main () {
    char path[200];
    getcwd (path, 200);
    printf("%s",path);
}

