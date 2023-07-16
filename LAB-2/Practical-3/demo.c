#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

void listDirectories(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char subPath[1024];
        snprintf(subPath, sizeof(subPath), "%s/%s", path, entry->d_name);

        if (stat(subPath, &info) == 0) {
            if (S_ISDIR(info.st_mode)) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    printf("Directory: %s\n", subPath);
                    listDirectories(subPath);
                }
            }
        }
    }

    closedir(dir);
}

int main() {
    const char *path = "F:\\B.TECH\\SEM-5\\OS\\LAB-1"; // Change this to the desired path

    printf("Directories and subdirectories:\n");
    listDirectories(path);

    return 0;
}
