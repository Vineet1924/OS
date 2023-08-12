#include <pthread.h>
#include <stdio.h>

struct myStruct
{
	int x;
	int y;
};

void *printStruct(void *var)
{
	struct myStruct *temp;
	temp = (struct myStruct *)var;
	printf("X = %d \n", temp->x);
	printf("Y = %d \n", temp->y);
}

void main()
{
	struct myStruct var;
	var.x = 10;
	var.y = 20;
	pthread_t t1;
	pthread_create(&t1, NULL, printStruct, (char *)&var);
	pthread_join(t1, NULL);
}
