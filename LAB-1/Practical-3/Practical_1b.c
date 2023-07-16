#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    char *buff[2000];
    int source = open(argv[1], O_RDONLY);
    int destination = open(argv[2], O_CREAT | O_WRONLY);

    int len = read(source, &buff, sizeof(buff));
    write(destination, buff, len);

    close(source);
    close(destination);
    return 0;
}