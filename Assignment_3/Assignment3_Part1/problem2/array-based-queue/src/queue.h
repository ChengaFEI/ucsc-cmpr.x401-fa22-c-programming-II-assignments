//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 2
//
// array-based-queue
// queue.h
// 
// Function: An array-based queue.
// 

#include <stdlib.h>
#include <stdio.h>

/*-----------------------------------------------------------------------------*/

typedef struct {
  int *arr;     // The array to store integers in the queue.
  int capacity; // The maximum number of integers the queue can hold.
  int size;     // The actual number of integers in the queue.
  int head;     // First integer's index.
  int tail;     // Last integer's index.
} Queue;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform major functionalities of Queue object.
int size(Queue *queue);
int enqueue(Queue *queue, int item);
int dequeue(Queue *queue);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionalities of Queue object.

// Log data messages.
void printQueue(Queue *queue);

// Manage the memory.
int initQueue(Queue *queue, int capacity);
void freeQueue(Queue *queue);
/*-----------------------------------------------------------------------------*/
