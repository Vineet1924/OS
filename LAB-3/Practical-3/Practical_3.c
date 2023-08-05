#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    int n;
    scanf("Enter number : %d", &n);

    for (int i = 0; i < n; i++) {
        int pid = fork();

        if (pid > 0) {
            printf("Parent process id = %d", getpid());
            break;
        }
        else {
            printf("Child process id = %d", getpid());
        }
    }
}
