//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// queue.c
// 
// Object: Queue.
// 

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// getSize() returns the size of the queue.
// @Param:   queue -- pointer to the Queue object.
// @Return:  the size of the queue.
// @Require: none
// @Note:    If the queue is NULL, return -1.
int getQueueSize(Queue *queue) 
{
  if (queue == NULL) return -1;
  return queue->queueSize;
}
/*-----------------------------------------------------------------------------*/

// isEmpty() checks whether the queue is empty.
// @Param:   queue         -- pointer to the queue to check.
// @Return:  a binary flag -- 1 indicates the queue is empty.
//                         -- 0 indicates the queue is not empty.
// @Require: queue is not NULL.
// @Note:    If the queue is NULL, return -1;
int isQueueEmpty(Queue *queue)
{
  if (queue == NULL) return -1;
  if (queue->queueSize == 0) return 1;
  return 0;
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
  // Unacceptable conditions.
  if (queue == NULL) return -1;
  Stack *pushStack = queue->pushStack;
  Stack *popStack = queue->popStack;
  if (isFull(pushStack) && !isEmpty(popStack)) return 1;

  // Pop all items to the popStack if the pushStack is full.
  if (isFull(pushStack) && isEmpty(popStack))
    moveItems(pushStack, popStack);
  // Enqueue the new item.
  push(pushStack, item);
  // Adjust properties.
  queue->queueSize++;

  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// dequeue() removes the first integer in queue.
// @Param:   queue -- pointer to the queue to remove an integer.
// @Return:  queue (update)
// @Return:  the poped item.
// @Require: queue is not NULL.
// @Note:    If queue is empty, operation fails.
int dequeue(Queue *queue)
{
  // Unacceptable conditions.
  if (queue == NULL) {
    printf("Error dequeueing the queue: queue is not initialized!\n");
    return -1;
  } 
  if (isQueueEmpty(queue)) {
    printf("Error dequeueing the queue: queue is empty!\n");
    return -1;
  }

  Stack *pushStack = queue->pushStack;
  Stack *popStack = queue->popStack;
  int currItem;
  // Push all items from the pushStack to the popStack.
  if (isEmpty(popStack)) moveItems(pushStack, popStack);
  // Dequeue the popStack.
  queue->queueSize--;
  return pop(popStack);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions start here.
/*-----------------------------------------------------------------------------*/

// initQueue() initializes properties of the queue.
// @Param:   queue       --  pointer to the Queue object.
// @Param:   capacity    --  the maximum number of integers the queue can store.
// @Return:  queue (update)
//           a code flag --  0 indicates queue is successfully initialized.
//                       --  1 indicates out of memory.
//                       -- -1 indicates queue is NULL.
// @Require: queue is not NULL.
// @Note:    none
int initQueue(Queue *queue, int stackCapacity)
{
  // queue can't be NULL.
  if (queue == NULL) return -1;
  // Initialize stacks.
  queue->pushStack = (Stack *) malloc(sizeof(Stack));
  if (queue->pushStack == NULL) return 1;
  queue->popStack = (Stack *) malloc(sizeof(Stack));
  if (queue->popStack == NULL) { freeStack(queue->pushStack); return 1; }
  initStack(queue->pushStack, stackCapacity);
  initStack(queue->popStack, stackCapacity);
  // Initialize other properties.
  queue->queueSize = 0;
  return 0; // Success.
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
  if (queue->pushStack != NULL) freeStack(queue->pushStack);
  if (queue->popStack != NULL) freeStack(queue->popStack);
  free(queue);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/

// moveItems() moves all items from srcStack to destStack.
// @Param:   srcStack  -- pointer to the source stack.
// @Param:   destStack -- pointer to the destination stack.
// @Return:  srcStack, destStack (update)
// @Require: Both stacks are not NULL.
// @Note:    If destStack is not empty, no moves will be made.
void moveItems(Stack *srcStack, Stack *destStack)
{
  if (srcStack == NULL || destStack == NULL) return;
  int item;
  if (isEmpty(destStack)) {
    while (srcStack->tail >= 0) {
      item = pop(srcStack);
      push(destStack, item);
    }
  }
}
/*-----------------------------------------------------------------------------*/
