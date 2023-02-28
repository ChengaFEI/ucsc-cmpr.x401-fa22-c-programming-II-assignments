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

#include "queue.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// size() returns the size of the queue.
// @Param:   queue -- pointer to the Queue object.
// @Return:  the size of the queue.
// @Require: none
// @Note:    If the queue is NULL, return -1.
int size(Queue *queue) 
{
  if (queue == NULL) return -1;
  return queue->size;
}
/*-----------------------------------------------------------------------------*/

// enqueue() adds a new integer into the queue.
// @Param:   queue       --  pointer to the queue to accept the new integer.
// @Param:   item        --  the new integer.
// @Return:  queue (update)
//           A code flag --  0 indicates queue successfully accepts the integer.
//                       --  1 indicates queue is full.
//                       -- -1 indicates queue is NULL.
// @Require: queue is not NULL.
// @Note:    If queue is full, the new integer can't be accepted.
int enqueue(Queue *queue, int item)
{
  // Queue can't be NULL.
  if (queue == NULL) {
    printf("Queue is not initialized.\n");
    return -1;
  }
  // If queue is full.
  if (queue->size == queue->capacity) {
    printf("Queue is full.\n");
    return 1;
  }
  // Accept the integer.
  int index = queue->tail;
  queue->arr[index] = item;
  queue->tail++;
  if (queue->tail >= queue->capacity) 
    queue->tail = 0;
  queue->size++;
  return 0;
}
/*-----------------------------------------------------------------------------*/

// dequeue() removes the first integer in queue.
// @Param:   queue -- pointer to the queue to remove an integer.
// @Return:  queue (update)
//           A code flag --  0 indicates queue successfully removes the integer.
//                       --  1 indicates queue is empty.
//                       -- -1 indicates queue is NULL.
// @Require: queue is not NULL.
// @Note:    If queue is empty, operation fails.
int dequeue(Queue *queue)
{
  // If queue is NULL.
  if (queue == NULL) {
    fprintf(stderr, "Error dequeueing a Queue: object not initialized.\n");
    return -1;
  }
  // If queue is empty.
  if (queue->size == 0) {
    fprintf(stderr, "Error dequeueing a Queue: empty queue.\n");
    return 1;
  }
  // Remove the first object.
  queue->head++;
  if (queue->head >= queue->capacity)
    queue->head = 0;
  queue->size--;
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions start here.
/*-----------------------------------------------------------------------------*/

// printQueue() displays integers stored in the queue.
// @Param:   queue -- pointer to the queue to be displayed.
// @Return:  none
// @Require: none
// @Note:    none
void printQueue(Queue *queue)
{
  // If queue is NULL.
  if (queue == NULL) return;

  printf("Integers in the queue: ");
  // If queue is not empty.
  if (queue->size != 0) {
    int index = queue->head;
    do {
      printf("%d ", queue->arr[index]);
      index++;
      if (index == queue->capacity) index = 0;
    } while (index != queue->tail);
  }
  printf("\n");
}
/*-----------------------------------------------------------------------------*/

// initQueue() initializes properties of the queue.
// @Param:   queue       --  pointer to the Queue object.
// @Param:   capacity    --  the maximum number of integers the queue will store.
// @Return:  queue (update)
//           a code flag --  0 indicates queue is successfully initialized.
//                       --  1 indicates out of memory.
//                       -- -1 indicates queue is NULL.
// @Require: queue is not NULL.
// @Note:    none
int initQueue(Queue *queue, int capacity)
{
  // queue must not be NULL.
  if (queue == NULL) return -1;

  // Initialize the arr property.
  queue->arr = (int *) calloc(capacity, sizeof(int));
  if (queue->arr == NULL) {
    fprintf(stderr, "Error initializing queue: out of memory!\n");
    return 1;
  }
  // Initialize other properties.
  queue->capacity = capacity;
  queue->size = 0;
  queue->head = 0;
  queue->tail = 0;
  
  // Success initialization.
  return 0;
}
/*-----------------------------------------------------------------------------*/

// freeQueue() releases all the dynamic memories occupied by queue.
// @Param:   queue -- pointer to the Queue object to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeQueue(Queue *queue)
{
  if (queue == NULL) return;
  free(queue->arr);
  free(queue);
}
/*-----------------------------------------------------------------------------*/
