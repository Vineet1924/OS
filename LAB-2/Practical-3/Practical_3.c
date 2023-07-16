#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

char * generatePath(char * path, const char * d_name) {
    char * string = malloc(300 * sizeof(char));

    strcat(path, "\\");
    strcat(path, d_name);
    strcpy(string, path);

    return string;
}

void getSubDirectory(char * path) {
    DIR * subdirectory = opendir(path);
    struct dirent * subdptr;
    char * newPath = malloc(300 * sizeof(char));

    while((subdptr = readdir(subdirectory)) != NULL) {
        printf("    %s \n", subdptr->d_name);

        #ifndef _DIRENT_HAVE_D_TYPE
        if(subdptr->d_type == 4) {
            strcpy(newPath, generatePath(path, subdptr->d_name));
            getSubDirectory(new Path);
        }
        #endif
    }
}

void main(int argc, char *argv[]) {
    DIR * directory = opendir("F:\\B.TECH\\SEM-5\\OS\\LAB-1");
    struct dirent * dptr;
    
    if(directory == NULL) {
        printf("Directory not exist!");
    }

    while((dptr = readdir(directory)) != NULL) {
        printf("- %s \n", dptr->d_name);

        #ifndef _DIRENT_HAVE_D_TYPE
        if(dptr->d_type == DT_DIR) {
            char * newPath = malloc(300 * sizeof(char));
            char path[200];
            getcwd (path, 200);
            strcpy(newPath, generatePath(path, dptr->d_name));
            getSubDirectory(newPath);
        }
        #endif
    }
    closedir(directory);
}