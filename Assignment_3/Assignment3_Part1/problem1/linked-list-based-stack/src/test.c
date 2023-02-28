//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 1
//
// test.c
// linked-list-based-stack
// 
// Function: Implement a linked-list-based stack.
// 

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
/*-----------------------------------------------------------------------------*/

// Test functions:
// Functions in this case provides pre-defined test case.
void runTestOne();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTestOne();
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
  // Create a Stack object.
  Stack *stack = (Stack *) malloc(sizeof(Stack));
  StackNode *peekNode = NULL;
  push(stack, 1);         // s: 1 
  printStack(stack);
  push(stack, 2);         // s: 2,1 
  printStack(stack);
  peekNode = peek(stack); // 2
  printf("The peeked node is: %d\n", peekNode->item);
  push(stack, 5);         // s: 5,2,1 
  printStack(stack);
  push(stack, 3);         // s: 3,5,2,1 
  printStack(stack);
  push(stack, 3);         // s: 3,3,5,2,1 
  printStack(stack);
  push(stack, 4);         // s: 4,3,3,5,2,1 
  printStack(stack);
  push(stack, 5);         // s: 5,4,3,3,5,2,1 
  printStack(stack);
  pop(stack);             // s: 4,3,3,5,2,1 
  printStack(stack);
  pop(stack);             // s: 3,3,5,2,1 
  printStack(stack);
  peekNode = peek(stack); // 3
  printf("The peeked node is: %d\n", peekNode->item);
  pop(stack);             // s: 3,5,2,1 
  printStack(stack);
  pop(stack);             // s: 5,2,1 
  printStack(stack);
  peekNode = peek(stack); // 5
  printf("The peeked node is: %d\n", peekNode->item);
  pop(stack);             // s:2,1
  printStack(stack);
  pop(stack);             // s:1
  printStack(stack);
  pop(stack);             // s: empty 
  printStack(stack);
  pop(stack);             // Error message
  printStack(stack);
  // Free the stack.
  freeStack(stack);
}
/*-----------------------------------------------------------------------------*/
