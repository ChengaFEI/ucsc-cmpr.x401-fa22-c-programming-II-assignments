//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// stack.h
// 
// Object: Stack.
// 

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

// Stack object using array to store data.
typedef struct {
  int *arr;     // The array to store data.
  int capacity; // The maximum number of integers the Stack can store.
  int size;     // The actual number of integers the Stack stores.
  int tail;     // The last integer's index. 
} Stack;
/*-----------------------------------------------------------------------------*/

// Major functions:
// Functions in this group perform major functionalities of Stack object.
int getSize(Stack *stack);
int isEmpty(Stack *stack);
int isFull(Stack *stack);
int push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
/*-----------------------------------------------------------------------------*/

// Minor functions:
// Functions in this group perform auxiliary functionalities of Stack object.

// Manage the memory.
int initStack(Stack *stack, int capacity);
void freeStack(Stack *stack);
/*-----------------------------------------------------------------------------*/

// Helper functions:
// Functions in this group help with major/minor functions' implementation.

/*-----------------------------------------------------------------------------*/
