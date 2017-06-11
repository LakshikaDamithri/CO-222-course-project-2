#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "StackAndQueue.h"

#define NO_OF_ELEMENTS 100000

int main()
{
	struct timeval t1, t2;
	double elapsedTime;
	srand(time(NULL));
	int i;
	int r;
	int result; 

	printf("Testing Queue\n");
	// start timer
	gettimeofday(&t1, NULL);
	Queue* queue = CreateQueue();

	for(i = 0; i < NO_OF_ELEMENTS ; i++)
	{
		// Generate a random value and put that to stack
		r = rand();	
		result = QueueEnqueue(queue, r);
		if(result != 0)
		{
			printf("Error in enqueuing queue\n");
		}
	}

	for(i = 0; i < NO_OF_ELEMENTS ; i++)
	{
		result =QueueDequeue(queue, &r);
		if(result != 0)
		{
			printf("Error in dequeuing queue\n");
		}
	}

	DeleteQueue(queue);

	// Time calculation
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	printf("Elapsed time %f\nQueue testing completed...\n", elapsedTime);
	
	printf("\nTesting Stack\n");
	// start timer
	gettimeofday(&t1, NULL);

	Stack* stack = CreateStack();
	for(i = 0; i < NO_OF_ELEMENTS ; i++)
	{
		// Generate a random value and put that to stack
		r = rand();	
		result = StackPush(stack, r);
		if(result != 0)
		{
			printf("Error in pushing to stack");
		}
	}

	for(i = 0; i < NO_OF_ELEMENTS ; i++)
	{
		result = StackPop(stack, &r);
		if(result != 0)
		{
			printf("Error in poping stack");
		}
	}
	
	DeleteStack(stack); 

	// Time calculation
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;

	printf("Elapsed time %f\nStack testing completed...\n", elapsedTime);

	return 0;
}
