/* Copyright SPEL Technologies, Inc.
 * linkedlist.c
 * A stack built using a linked list
 */

#include "linkedlist.h"

typedef DoublyLinkedList Stack;

Stack * createStack() {
	return createList();
}

// insert the node at position 0
void push(Stack *stack, int item) {
	insertNode(stack, item, 0);
}

// remove the item at position 0
void pop(Stack *stack) {
	deleteNode(stack, 0);
}

int *peek(Stack *stack) {
	node *temp = getNode(stack, 0);
	return temp->key;
}

void deleteStack(Stack *stack) {
		listDeleteAll(stack);
}

int main(void) {

	Stack *stack = createStack();
	push(stack, 1);
	push(stack, 2);
	printf("%d \n", peek(stack));
	push(stack, 5);
	push(stack, 3);
	push(stack, 3);
	push(stack, 4);
	push(stack, 5);
	pop(stack);
	pop(stack);
	printf("%d\n", peek(stack));
	pop(stack); // s: 3,5,2,1
	pop(stack); // s: 5,2,1
	printf("%d\n", peek(stack));
	pop(stack); // s:2,1
	pop(stack); // s:1
	pop(stack); // s: empty
	pop(stack); // Error message
	return (EXIT_SUCCESS);
}
