#include <pthread.h>
#include <stdio.h>

void * printHello1() {
	printf("Hello_World! from first \n");
}

void * printHello2() {
	printf("Hello_World!  from  second \n");
}

void main() {
	pthread_t t1, t2;
	pthread_create(&t1, NULL, printHello1, NULL);
	pthread_create(&t2, NULL, printHello2, NULL);
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);
}
