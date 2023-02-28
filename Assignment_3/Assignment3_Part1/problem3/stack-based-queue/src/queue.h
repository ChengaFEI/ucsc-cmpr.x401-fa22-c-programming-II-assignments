//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// queue.h
// 
// Object: Queue.
// 

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
/*-----------------------------------------------------------------------------*/

// Queue object using two stacks to store data.
typedef struct {
  Stack *pushStack;  // Push data to this stack.
  Stack *popStack;   // Pop data from this stack.
  int queueSize;          // The actual number of items in the queue.
} Queue;
/*-----------------------------------------------------------------------------*/

// Major functions:
// Functions in this group perform major functionalities of Queue object.
int getQueueSize(Queue *queue);
int isQueueEmpty(Queue *queue);
int enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
/*-----------------------------------------------------------------------------*/

// Minor functions:
// Functions in this group perform auxiliary functionalities of Queue object.

// Manage the memory.
int initQueue(Queue *queue, int stackCapacity);
void freeQueue(Queue *queue);
/*-----------------------------------------------------------------------------*/

// Helper functions:
// Functions in this group help with major/minor functions' implementation.

// Move items between stacks.
void moveItems(Stack *srcStack, Stack *destStack);
/*-----------------------------------------------------------------------------*/
