#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

void main() {
	int n = 4;
	int pid = 1;
	
	for(int i = 0; i < n && pid > 0; i++) {
		pid = fork();
		if(pid == -1) {
			printf("Error \n");
		} else if(pid > 0) {
			wait(NULL);
		} else {
			printf("Child %d parent-id = %d \n", i, getppid());
			exit(0);
		} 
	}
}

