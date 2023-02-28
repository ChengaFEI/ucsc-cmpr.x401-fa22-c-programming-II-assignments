//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 1
//
// stack.h
// linked-list-based-stack
// 
// Object: StackNode, Stack.
// 

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

// StackNode object built based on the linked list.
typedef struct StackNode_t {
  int item;                 // Value stored in the list node.
  struct StackNode_t *next; // pointer to the next StackNode object.
} StackNode;

// Stack object built with StackNode objects.
typedef struct {
  StackNode *head; // The first StackNode in the Stack.
  size_t size;     // The number of all StackNode in the Stack.
} Stack;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform the major functionality of StackNode/Stack object.
void push(Stack *stack, int item);
void pop(Stack *stack);
StackNode *peek(Stack *stack);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionality of StackNode/Stack object.

// Log the data messages.
void printStack(Stack *stack);
// Manage the memory.
void freeStack(Stack *stack);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this group help with the implementation of major/minor functions.
void freeStackNodes(StackNode *node);
/*-----------------------------------------------------------------------------*/
