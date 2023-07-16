#include<stdio.h>
#include <dirent.h>

void main(int argc, char *argv[]) {
    DIR *directory = opendir(argv[1]);
    struct dirent *dptr;

    if(directory == NULL) {
        printf("Directory not exist!");
    }

    while((dptr = readdir(directory)) != NULL) {
        printf("- %s \n", dptr->d_name);
    }

    closedir(directory);
}