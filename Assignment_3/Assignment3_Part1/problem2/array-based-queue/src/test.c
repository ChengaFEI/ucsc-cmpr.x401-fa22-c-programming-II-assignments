//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 2
//
// array-based-queue
// test.c
// 
// Function: An array-based queue.
// 

#include <stdlib.h>
#include <stdio.h>

#include "queue.h"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provides pre-defined test cases.
void runTestOne();
void runTestTwo();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTestOne();
  printf("\n");
  runTestTwo();
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
  printf("Test case 1:\n");
  printf("-----------------------------------------------------\n");
  // Initialize a queue.
  Queue *queue = (Queue *) malloc(sizeof(Queue));
  if (queue == NULL) {
    fprintf(stderr, "Error initializing a queue: out of memory.\n");
    exit(EXIT_FAILURE);
  }
  initQueue(queue, 10);

  int qSize;
  // Operate on the queue.
  enqueue(queue, 1);   // q: 1 
  printQueue(queue);
  enqueue(queue, 2);   // q: 1, 2 
  printQueue(queue);
  qSize = size(queue); //    2
  printf("The size of the queue: %d\n", qSize);
  enqueue(queue, 5);   // q: 1, 2, 5 
  printQueue(queue);
  enqueue(queue, 3);   // q: 1, 2, 5, 3 
  printQueue(queue);
  enqueue(queue, 3);   // q: 1, 2, 5, 3, 3 
  printQueue(queue);
  enqueue(queue, 4);   // q: 1, 2, 5, 3, 3, 4 
  printQueue(queue);
  enqueue(queue, 5);   // q: 1, 2, 5, 3, 3, 4, 5 
  printQueue(queue);
  qSize = size(queue); //    7
  printf("The size of the queue: %d\n", qSize);
  dequeue(queue);      // q: 2, 5, 3, 3, 4, 5 
  printQueue(queue);
  dequeue(queue);      // q: 5, 3, 3, 4, 5 
  printQueue(queue);
  qSize = size(queue); //    5
  printf("The size of the queue: %d\n", qSize);

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
  printf("Test case 2:\n");
  printf("-----------------------------------------------------\n");
  // Initialize a queue.
  Queue *queue = (Queue *) malloc(sizeof(Queue));
  if (queue == NULL) {
    fprintf(stderr, "Error initializing a queue: out of memory.\n");
    exit(EXIT_FAILURE);
  }
  initQueue(queue, 10);

  int qSize;
  // Operate on the queue.
  enqueue(queue, 1);   // q: 1 
  printQueue(queue);
  enqueue(queue, 2);   // q: 1, 2 
  printQueue(queue);
  qSize = size(queue); //    2
  printf("The size of the queue: %d\n", qSize);
  enqueue(queue, 5);   // q: 1, 2, 5 
  printQueue(queue);
  enqueue(queue, 3);   // q: 1, 2, 5, 3 
  printQueue(queue);
  dequeue(queue);      // q: 2, 5, 3
  printQueue(queue);
  dequeue(queue);      // q: 5, 3
  printQueue(queue);
  dequeue(queue);      // q: 3
  printQueue(queue);
  enqueue(queue, 3);   // q: 3, 3 
  printQueue(queue);
  enqueue(queue, 4);   // q: 3, 3, 4 
  printQueue(queue);
  enqueue(queue, 5);   // q: 3, 3, 4, 5 
  printQueue(queue);
  qSize = size(queue); //    4
  printf("The size of the queue: %d\n", qSize);
  dequeue(queue);      // q: 3, 4, 5 
  printQueue(queue);
  dequeue(queue);      // q: 4, 5 
  printQueue(queue);
  qSize = size(queue); //    2
  printf("The size of the queue: %d\n", qSize);
  enqueue(queue, 5);   // q: 4, 5, 5
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5 
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5, 5 
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5, 5, 5
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5, 5, 5, 5 
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5, 5, 5, 5, 5 
  printQueue(queue);
  enqueue(queue, 5);   // q: 4, 5, 5, 5, 5, 5, 5, 5, 5, 5
  printQueue(queue);
  qSize = size(queue); //    10
  printf("The size of the queue: %d\n", qSize);  

  // Free the queue.
  freeQueue(queue);
}
/*-----------------------------------------------------------------------------*/
