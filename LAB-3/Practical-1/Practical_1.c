#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void main() {
	int pid;
	pid = fork();
	
	if(pid == -1) {
		printf("Error \n");
	} else if(pid > 0) {
		wait(NULL);
		printf("Hello from shell-id = %d \n", getppid());
		printf("Hello from parent-id =  %d of child-id = %d \n", getpid(), pid);
	} else {
		printf("Hello from child-id =  %d of parent-id = %d \n", getpid(), getppid());
	}
}
