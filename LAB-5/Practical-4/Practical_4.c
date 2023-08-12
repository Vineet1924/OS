#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int count = 0;

void *fun()
{
	pthread_mutex_lock(&mutex);
	count++;
	printf("Counter = %d\n", count);
	pthread_mutex_unlock(&mutex);
}

int main()
{
	pthread_t threads[5];

	for (int i = 0; i < 5; i++)
	{
		if (pthread_create(&threads[i], NULL, fun, NULL) != 0)
		{
			printf("Error occurred while creating thread : %d\n", i);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			printf("Error occurred while joining thread : %d\n", i);
		}
	}

	return 0;
}
