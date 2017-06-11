#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ELEMENTS 100000

//creating a new structure for the stack
typedef struct st{
	int stackArray[NO_OF_ELEMENTS];
    int top;
    int maxsize;
}Stack;

//creating a new structure for the queue
typedef struct qu{
        int capacity;
        int size;
        int front;
        int rear;
        int queueArray[NO_OF_ELEMENTS];
}Queue;

//Functions for stack
Stack* CreateStack();
int DeleteStack(Stack* stack);
int StackPush(Stack* stack, int value);
int StackPop(Stack* stack, int* value);
int StackPeek(const Stack* stack, int* value);

//Functions for queue
Queue* CreateQueue();
int DeleteQueue(Queue* queue);
int QueueEnqueue(Queue* queue, int value);
int QueueDequeue(Queue* queue, int* value);
int QueuePeek(const Queue* queue, int* value);

// Stack implementation

// Function for creating the stack
Stack* CreateStack(){
	Stack* s;
	s=(Stack *)malloc(sizeof(Stack));
	s->top=-1;
	s->maxsize= NO_OF_ELEMENTS-1;
	return s;
	}

// Function for pushing a value to the stack
int StackPush(Stack* stack, int value) {
    if (stack->top == stack->maxsize) {   // If the stack is full
        return -1;
    }
    else {                                // otherwise the value is added as the top element
        stack->top = stack->top + 1;
        stack->stackArray[stack->top] = value;
    }
    return 0;
}

// Function for popping the value in the top of the stack
int StackPop(Stack* stack, int* value){
	if (stack->top < 0) {               // If the stack is empty
       return -1;
    } else {                            
		*value=stack->stackArray[stack->top] ;
		 stack->top = stack->top - 1;
		}
	return 0;
	}

//Function for assigning the value to be popped
int StackPeek(const Stack* stack, int* value){
	if (stack->top <= 0) {
       return -1;
	} else {
		*value=stack->stackArray[stack->top] ;
		}
	return 0;	
}

// Deleting the stack
int DeleteStack(Stack* stack){
	free(stack);
	return 0;
	}

// Queue implementation

// Function for creating the queue
Queue* CreateQueue() {
	Queue* q;
	q= (Queue *)malloc(sizeof(Queue));
	q->capacity= NO_OF_ELEMENTS;
	q->size= 0;
	q->front= 0;
	q->rear= -1;
	return q;
}

// Function for enqueue a value to the queue
int QueueEnqueue(Queue* queue, int value){
	if (queue->size >= queue->capacity) {    // If the queue is full 
        return -1;
    } else {
		queue->size++;
		queue->rear = queue->rear + 1;
        queue->queueArray[queue->rear] = value;
	}
	return 0;
}

// Function for dequeue the value in the front of the queue
int QueueDequeue(Queue* queue, int* value){
	int i;
	if (queue->size <= 0) {              // If the queue is empty
       return -1;
    } else {
		 queue->size--;
		*value=queue->queueArray[queue->front] ;
		 
		 // Shifting the elements in the array to make the index to be increased by one and to remove the first element
		 for(i=0;i<queue->size;i++){                      
			 queue->queueArray[i]= queue->queueArray[i+1] ;
			 }
		 queue->rear = queue->rear - 1;
		}
	return 0;
	}

//Function for assigning the value to be removed
int QueuePeek(const Queue* queue, int* value){
	if (queue->size <= 0) {
       return -1;
    } else {
		*value=queue->queueArray[queue->rear] ;
	}
	return 0;
	}

//Deleting the queue
int DeleteQueue(Queue* queue) {
	free(queue);
	return 0;
}


