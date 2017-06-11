#include <stdio.h>
#include <stdlib.h>

#define NO_OF_ELEMENTS 100000

//Creating new structure for elements 
typedef struct el{
	int data;
    struct el *next;
}Element;

// Creating a structure for the stack
typedef struct stack{
	Element* top;
}Stack;

//  creating  a structure for the queue
typedef struct queue{
	Element* front;
	Element* rear;
}Queue;

// Functions of the stack
Stack* CreateStack();
int DeleteStack(Stack* stack);
int StackPush(Stack* stack, int value);
int StackPop(Stack* stack, int* value);
int StackPeek(const Stack* stack, int* value);

// Functions of the queue
Queue* CreateQueue();
int DeleteQueue(Queue* queue);
int QueueEnqueue(Queue* queue, int value);
int QueueDequeue(Queue* queue, int* value);
int QueuePeek(const Queue* queue, int* value);

// Stack implementation

//  Function for creating a stack
Stack* CreateStack() {
	Stack* stack;
	stack=(Stack *)malloc(sizeof(Stack)); // Allocating space for the stack
	stack->top= NULL;
	return stack;
	}

//Function for pushing a value to the stack
int StackPush(Stack* stack, int value) {
	Element* element=(Element *)malloc(sizeof(Element)); // Allocating a space for the element in the stack
	
	// Initializing the structure's values
	element-> data = value;
	element-> next= stack->top; 
	stack->top=element;	
	return 0;
}

// Function for popping the value in the top of the stack
int StackPop(Stack* stack, int* value){
	Element* temp;
	if (stack->top==NULL) {  // If the stack is empty
		return -1;
	} else {
		temp=stack->top;
		*value=temp->data;
		stack->top=temp->next; // Making the next element as Top
		free(temp);
	}
	return 0;
}

// //Function for assigning the value to be popped
int StackPeek(const Stack* stack, int* value) {
	if (stack->top==NULL) {
		return -1;
	} else {
		*value=stack->top->data;
	}
	return 0;
	}

// Deleting the stack
int DeleteStack(Stack* stack) {
	free(stack);
	return 0;
}


// Queue implementation

// Function for creating the queue
Queue* CreateQueue() {
	Queue* queue;
	queue=(Queue *)malloc(sizeof(Queue)); // Allocating space for the queue
	queue->rear= NULL;
	queue->front= NULL;
	return queue;
	}

// Function for enqueue a value to the queue
int QueueEnqueue(Queue* queue, int value) {
	Element* element=(Element *)malloc(sizeof(Element)); // Allocating space for the new element
	element->data = value;
	element->next= queue->rear; 
	queue->rear=element;  // Setting the new element as rear
	if(element->next==NULL) queue->front=element; // Setting the first element as the front
	return 0;
}

// Function for dequeue the value in the front of the queue
int QueueDequeue(Queue* queue, int* value){
	Element* previous;
	Element* qcurrent;
	if(queue->rear==NULL){  // If the queue is empty
		return -1;
	} else if (queue->rear->next==NULL){ // If there is one element in the queue
		*value= queue->rear->data;
		qcurrent=queue->rear;
		free(qcurrent);
		queue->rear=NULL;
		queue->front=NULL;
	} else	{                            // If there are more than one element
		for (qcurrent=queue->rear; qcurrent->next!=NULL ; qcurrent=qcurrent->next) {
			previous= qcurrent;
			}
		*value=qcurrent->data;
		// Setting the secondly added element as first
		previous->next = NULL; 
		queue->front= previous;  
		free(qcurrent); // Removing the first element
	}
	return 0;
}

//Function for assigning the value to be removed
int QueuePeek(const Queue* queue, int* value) {
	Element* qcurrent;
	if(queue->rear==NULL){
		return -1;
	} else if (queue->rear->next==NULL){
		*value= queue->rear->data;
		return 0;
	} else	{
		for (qcurrent=queue->rear; qcurrent->next!=NULL ; qcurrent=qcurrent->next) {
			}
		*value=qcurrent->data;
	return 0;
	}
}

//Deleting the queue
int DeleteQueue(Queue* queue){
	free(queue);
	return 0;
	}
