#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    char *buff[2000];
    int fd = open(argv[1], O_RDONLY, 0);

    int len = read(fd, &buff, sizeof(buff));
    write(1, buff, len);

    close(fd);
    return 0;
}