#include <pthread.h>
#include <stdio.h>

void *printMessage(void *string)
{
	printf("Message : %s", (char *)string);
}

void main()
{
	pthread_t t1;
	char *string = "My new Message";

	pthread_create(&t1, NULL, printMessage, (void *)string);
	pthread_join(t1, NULL);
}
