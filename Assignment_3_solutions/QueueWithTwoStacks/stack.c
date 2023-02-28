/* Copyright SPEL Technologies, Inc.
 * stack.c
 * Implements a stack using an array on the heap
 *
 * Assignment 1 solution
 * MIT License
 */
#include "stack.h"

// create an empty stack
Stack*  createStack(int stackSize) {
	Stack *stack = (Stack *) calloc(sizeof(stack), 1);
	if (stackSize <= 0) {
		fprintf(stderr, "ERROR: Stack size must be greater than 0");
		exit(EXIT_FAILURE);
	}

	if (stackSize > MAX_SIZE) {
		fprintf(stderr, "ERROR: Stack size must be less than MAX_SIZE");
		exit(EXIT_FAILURE);
	}
	stack->capacity = stackSize;

	stack->data = (Data *) calloc(sizeof(Data), stack->capacity);
	if (stack->data == NULL) {
		fprintf(stderr, "ERROR: Stack size must be less than MAX_SIZE");
		exit(EXIT_FAILURE);
	}
	stack->topIndex = -1;
	return stack;
}

// push newData on stack
void push(Stack *stack, Data newData) {
	if (stack->topIndex == stack->capacity) {
		fprintf(stderr, "ERROR: Stack is filled to capacity");
		exit(EXIT_FAILURE);
	}

	stack->topIndex++;
	stack->data[stack->topIndex] = newData;
}

// pop stack (decrement stack pointer)
void pop(Stack *stack) {
	if (stack->topIndex == -1) {
		fprintf(stderr, "Stack is empty");
	    exit(EXIT_FAILURE);
	}
	stack->topIndex--;
}

// return topmost item of stack
Data peek(Stack *stack) {
	if (stack->topIndex == -1) {
		fprintf(stderr, "Stack is empty");
	    exit(EXIT_FAILURE);
	}
	return(stack->data[stack->topIndex]);
}

bool isEmpty(Stack *stack) {
	return (stack->topIndex == -1);
}

// delete stack
void deleteStack(Stack *stack) {
	free(stack->data);
	stack->data = NULL;
	free(stack);
	stack = NULL;
}

/*int main(void) {

	Stack *stack = createStack(10);
	Data data1 = {.value = 1};
	Data data2 = {.value = 2};
	Data data3 = {.value = 3};
	Data data4 = {.value = 3};
	Data data5 = {.value = 3};

	push(stack, data1);
	push(stack, data2);
	printf("%d \n", peek(stack).value);
	push(stack, data5);

	pop(stack);
	printf("%d \n", peek(stack).value);
	pop(stack);
	printf("%d \n", peek(stack).value);
	printf("isEmpty:%d \n", isEmpty(stack));
	pop(stack);
	printf("Popped stack again, isEmpty:%d \n", isEmpty(stack));

	deleteStack(stack);

	return(EXIT_SUCCESS);
}*/

