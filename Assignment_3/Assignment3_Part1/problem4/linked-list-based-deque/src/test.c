//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 4
//
// linked-list-based-deque
// test.c
// 
// Function: A double-ended queue.
// 

#include <stdlib.h>
#include <stdio.h>

#include "deque.h"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provides pre-defined test cases.
void runTestOne();
void runTestTwo();
void runTestThree();
void runTestFour();
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
  runTestFour();
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
  printf("Test Case 1:\n");
  printf("--------------------------------\n");
  // Initialize a deque.
  Deque *deque = (Deque *) malloc(sizeof(Deque));

  // Operate on the deque.
  push(deque, 7);    // 7
  printDeque(deque);
  push(deque, 6);    // 6, 7
  printDeque(deque);
  push(deque, 7);    // 7, 6, 7
  printDeque(deque);
  push(deque, 8);    // 8, 7, 6, 7 
  printDeque(deque); 
  pop(deque);        // 7, 6, 7
  printDeque(deque);
  pop(deque);        // 6, 7
  printDeque(deque);

  // Free the deque.
  freeDeque(deque);
}
/*-----------------------------------------------------------------------------*/

// runTestTwo() runs the second test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestTwo()
{
  printf("Test Case 2:\n");
  printf("--------------------------------\n");
  // Initialize a deque.
  Deque *deque = (Deque *) malloc(sizeof(Deque));

  // Operate on the deque.
  inject(deque, 7);  // 7
  printDeque(deque); 
  inject(deque, 6);  // 7, 6
  printDeque(deque); 
  inject(deque, 7);  // 7, 6, 7
  printDeque(deque); 
  inject(deque, 8);  // 7, 6, 7, 8 
  printDeque(deque); 
  pop(deque);        // 6, 7, 8
  printDeque(deque); 
  pop(deque);        // 7, 8
  printDeque(deque); 
  eject(deque);      // 7
  printDeque(deque); 
  eject(deque);      // empty
  printDeque(deque); 

  // Free the deque.
  freeDeque(deque);  
}
/*-----------------------------------------------------------------------------*/

// runTestThree() runs the third test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestThree()
{
  printf("Test Case 3:\n");
  printf("--------------------------------\n");
  // Initialize a deque.
  Deque *deque = (Deque *) malloc(sizeof(Deque));

  // Operate on the deque.
  inject(deque, 2);  // 2
  printDeque(deque);
  inject(deque, 6);  // 2, 6
  printDeque(deque);
  eject(deque);      // 2
  printDeque(deque);
  eject(deque);      // empty
  printDeque(deque);
  push(deque, 8);    // 8
  printDeque(deque);
  push(deque, 9);    // 9, 8
  printDeque(deque);
  pop(deque);        // 8
  printDeque(deque);

  // Free the deque.
  freeDeque(deque);  
}
/*-----------------------------------------------------------------------------*/

// runTestFour() runs the fourth test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestFour()
{
  printf("Test Case 4:\n");
  printf("--------------------------------\n");
  // Initialize a deque.
  Deque *deque = (Deque *) malloc(sizeof(Deque));

  // Operate on the deque.
  pop(deque);        // Error message 
  eject(deque);      // Error message 
  push(deque, 2);    // 2
  printDeque(deque); 
  push(deque, 3);    // 3, 2
  printDeque(deque); 
  push(deque, 4);    // 4, 3, 2
  printDeque(deque); 
  push(deque, 5);    // 5, 4, 3, 2
  printDeque(deque); 
  push(deque, 6);    // 6, 5, 4, 3, 2
  printDeque(deque); 
  push(deque, 7);    // 7, 6, 5, 4, 3, 2
  printDeque(deque); 
  push(deque, 8);    // 8, 7, 6, 5, 4, 3, 2
  printDeque(deque); 
  push(deque, 9);    // 9, 8, 7, 6, 5, 4, 3, 2
  printDeque(deque); 
  inject(deque, 5);  // 9, 8, 7, 6, 5, 4, 3, 2, 5
  printDeque(deque); 
  pop(deque);        // 8, 7, 6, 5, 4, 3, 2, 5
  printDeque(deque); 
  pop(deque);        // 7, 6, 5, 4, 3, 2, 5
  printDeque(deque); 
  eject(deque);      // 7, 6, 5, 4, 3, 2
  printDeque(deque); 
  eject(deque);      // 7, 6, 5, 4, 3
  printDeque(deque); 

  // Free the deque.
  freeDeque(deque);  
}
/*-----------------------------------------------------------------------------*/
