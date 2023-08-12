#include <pthread.h>
#include <stdio.h>

struct myStruct
{
	int x;
	int y;
};

void *addition(void *var)
{
	struct myStruct *temp;
	temp = (struct myStruct *)var;
	int x = (int)temp->x;
	int y = (int)temp->y;

	int sum = x + y;
	int sub = x - y;
	int mul = x * y;
	int div = x / y;

	printf("Addition = %d \n", sum);
	printf("Subtraction = %d \n", sub);
	printf("Multiplication = %d \n", mul);
	
	if (y == 0)
	{
		printf("cannot devide by zero!");
	}
	else
	{
		printf("Division = %d \n", div);
	}
}

void main()
{
	struct myStruct var;
	var.x = 20;
	var.y = 10;
	pthread_t t1;
	pthread_create(&t1, NULL, addition, (char *)&var);
	pthread_join(t1, NULL);
}