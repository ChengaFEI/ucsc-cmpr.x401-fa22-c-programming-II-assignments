//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// test.c
// 
// Function: A stack-based queue.
// 

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provides pre-defined test cases.
void runTestOne();
void runTestTwo();
void runTestThree();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTestOne();
  printf("\n");
  runTestTwo();
  printf("\n");
  runTestThree();
  printf("\n");
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// runTestOne() runs the first test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestOne()
{
  int capacity = 7;
  printf("Test case 1: \n");
  printf("stack's capacity: %d\n", capacity);
  printf("--------------------------------------------\n");
  // Initialize the queue.
  Queue *queue = (Queue *) malloc(sizeof(Queue));
  initQueue(queue, capacity);

  int size, empty;
  // Operate on the queue.
  empty = isQueueEmpty(queue);        //    True 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  enqueue(queue, 1);          // q: 1 
  printf("Enqueue 1...\n");
  enqueue(queue, 2);          // q: 1, 2
  printf("Enqueue 2...\n");
  size = getQueueSize(queue); //    2
  printf("The size of the queue is %d.\n", size);
  enqueue(queue, 5);          // q: 1, 2, 5 
  printf("Enqueue 5...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 4);          // q: 1, 2, 5, 3, 3, 4 
  printf("Enqueue 4...\n");
  enqueue(queue, 5);          // q: 1, 2, 5, 3, 3, 4, 5 
  printf("Enqueue 5...\n");
  size = getQueueSize(queue); //    7
  printf("The size of the queue is %d.\n", size);
  dequeue(queue);             // q: 2, 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  dequeue(queue);             // q: 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  empty = isQueueEmpty(queue);//    False 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  size = getQueueSize(queue); //    5
  printf("The size of the queue is %d.\n", size);
  printf("--------------------------------------------\n");

  // Free the queue.
  freeQueue(queue);
}
/*-----------------------------------------------------------------------------*/

// runTestTwo() runs the second test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestTwo()
{
  int capacity = 4;
  printf("Test case 2: \n");
  printf("stack's capacity: %d\n", capacity);
  printf("--------------------------------------------\n");
  // Initialize the queue.
  Queue *queue = (Queue *) malloc(sizeof(Queue));
  initQueue(queue, capacity);

  int size, empty;
  // Operate on the queue.
  empty = isQueueEmpty(queue);        //    True 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  enqueue(queue, 1);          // q: 1 
  printf("Enqueue 1...\n");
  enqueue(queue, 2);          // q: 1, 2
  printf("Enqueue 2...\n");
  size = getQueueSize(queue); //    2
  printf("The size of the queue is %d.\n", size);
  enqueue(queue, 5);          // q: 1, 2, 5 
  printf("Enqueue 5...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 4);          // q: 1, 2, 5, 3, 3, 4 
  printf("Enqueue 4...\n");
  enqueue(queue, 5);          // q: 1, 2, 5, 3, 3, 4, 5 
  printf("Enqueue 5...\n");
  size = getQueueSize(queue); //    7
  printf("The size of the queue is %d.\n", size);
  dequeue(queue);             // q: 2, 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  dequeue(queue);             // q: 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  empty = isQueueEmpty(queue);//    False 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  size = getQueueSize(queue); //    5
  printf("The size of the queue is %d.\n", size);
  printf("--------------------------------------------\n");

  // Free the queue.
  freeQueue(queue);
}
/*-----------------------------------------------------------------------------*/

// runTestThree() runs the third test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestThree()
{
  int capacity = 3;
  printf("Test case 3: \n");
  printf("stack's capacity: %d\n", capacity);
  printf("--------------------------------------------\n");
  // Initialize the queue.
  Queue *queue = (Queue *) malloc(sizeof(Queue));
  initQueue(queue, capacity);

  int size, empty;
  // Operate on the queue.
  empty = isQueueEmpty(queue);        //    True 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  enqueue(queue, 1);          // q: 1 
  printf("Enqueue 1...\n");
  enqueue(queue, 2);          // q: 1, 2
  printf("Enqueue 2...\n");
  size = getQueueSize(queue); //    2
  printf("The size of the queue is %d.\n", size);
  enqueue(queue, 5);          // q: 1, 2, 5 
  printf("Enqueue 5...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 3);          // q: 1, 2, 5, 3, 3 
  printf("Enqueue 3...\n");
  enqueue(queue, 4);          // q: 1, 2, 5, 3, 3, 4 
  printf("Enqueue 4...\n");
  enqueue(queue, 5);          // q: 1, 2, 5, 3, 3, 4, 5 
  printf("Enqueue 5...\n");
  size = getQueueSize(queue); //    7
  printf("The size of the queue is %d.\n", size);
  dequeue(queue);             // q: 2, 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  dequeue(queue);             // q: 5, 3, 3, 4, 5 
  printf("Dequeue ....\n");
  empty = isQueueEmpty(queue);//    False 
  printf("The queue is %s.\n", empty == 1 ? "empty" : "not empty");
  size = getQueueSize(queue); //    5
  printf("The size of the queue is %d.\n", size);
  printf("--------------------------------------------\n");

  // Free the queue.
  freeQueue(queue);
}
/*-----------------------------------------------------------------------------*/