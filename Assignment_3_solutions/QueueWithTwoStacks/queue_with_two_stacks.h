/*
 * queue_with_two_stacks.h
 * Copyright SPEL Technologies, Inc.
 *
 *
 */

#ifndef QUEUE_WITH_TWO_STACKS_H_
#define QUEUE_WITH_TWO_STACKS_H_

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct QueueWithTwoStacks_t {
	int capacity;
	Stack *stack1;
	Stack *stack2;
	int size;
} QueueWithTwoStacks;

void enqueue(QueueWithTwoStacks *queue, int data);
#endif /* QUEUE_WITH_TWO_STACKS_H_ */
