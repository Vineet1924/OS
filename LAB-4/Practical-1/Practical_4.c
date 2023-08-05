#include <stdio.h>
#include <ctype.h>
#include <dirent.h>
#include <string.h>

void main(int argc, char *argv[])
{
    DIR *directory = opendir("/proc/");
    struct dirent *dptr;

    if (directory == NULL)
    {
        printf("Directory not exist!");
    }

    printf("PID\tProcess Name\n");
    printf("------------------\n");

    while ((dptr = readdir(directory)) != NULL)
    {
        char filename[255];
        char process_name[256];
        strncpy(filename, dptr->d_name, 254);
        filename[254] = '\0';
        if (isalpha(filename[0]))
        {
            continue;
        }
        else if (filename[0] == '.')
        {
            continue;
        }
        else
        {
            char path[100];
            char *result;
            strcat(path, "/proc/");
            strcat(path, filename);
            strcat(path, "/");
            strcat(path, "comm");

            FILE *file = fopen(path, "r");
            if (file != NULL)
            {
                if (result = fgets(process_name, sizeof(process_name), file) != NULL)
                {
                    process_name[strcspn(process_name, "\n")] = '\0';
                    printf("%s\t%s\n", filename, process_name);
                }
                fclose(file);
            }
            path[0] = '\0';
        }
    }

    closedir(directory);
}