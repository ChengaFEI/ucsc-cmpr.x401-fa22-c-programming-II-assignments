/* Copyright SPEL Technologies, Inc.
 * stack.c
 * Implements a stack using an array
 *
 * MIT License
 */

#ifndef STACK_H_
#define STACK_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarySearchTree.h"

#define MAX_SIZE  100

typedef struct TreeNode_t * Data;

typedef struct Stack_t {
	int topIndex;
	int capacity;
	Data *data;
} Stack;

Stack*  createStack(int stackSize);
void push(Stack *stack, Data newData);
void pop(Stack *stack);
Data peek(Stack *stack);
bool isEmpty(Stack *stack);
void deleteStack(Stack *stack);

#endif /* STACK_H_ */
