#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    char *buff[2000];

    for(int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY, 0);
        int len = read(fd, &buff, sizeof(buff));
        write(1, buff, len);
    }

    return 0;
}