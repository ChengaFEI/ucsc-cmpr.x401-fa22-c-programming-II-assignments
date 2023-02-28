//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// stack.c
// 
// Object: Stack.
// 

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// getSize() returns the size of the stack.
// @Param:   stack -- pointer to the Stack object.
// @Return:  the size of the stack.
// @Require: none
// @Note:    If the stack is NULL, return -1.
int getSize(Stack *stack) 
{
  if (stack == NULL) return -1;
  return stack->size;
}
/*-----------------------------------------------------------------------------*/

// isEmpty() checks whether the stack is empty.
// @Param:   stack         -- pointer to the stack to check.
// @Return:  a binary flag -- 1 indicates the stack is empty.
//                         -- 0 indicates the stack is not empty.
// @Require: stack is not NULL.
// @Note:    If the stack is NULL, return -1;
int isEmpty(Stack *stack)
{
  if (stack == NULL) return -1;
  if (stack->size == 0) return 1;
  return 0;
}
/*-----------------------------------------------------------------------------*/

// isFull() checks whether the stack is full.
// @Param:   stack         -- pointer to the stack to check.
// @Return:  a binary flag -- 1 indicates the stack is full.
//                         -- 0 indicates the stack is not full.
// @Require: stack is not NULL.
// @Note:    If the stack is NULL, return -1;
int isFull(Stack *stack)
{
  if (stack == NULL) return -1;
  if (stack->size == stack->capacity) return 1;
  return 0;
}
/*-----------------------------------------------------------------------------*/

// push() adds a new item to the stack.
// @Param:   stack       --  pointer to the stack to add a new item.
// @Param:   item        --  the new item.
// @Return:  stack (update)
//           status flag --  0 indicates the stack successfully adds the new item.
//                       --  1 indicates the stack is full.
//                       -- -1 indicates the stack is NULL.
// @Require: none
// @Note:    none
int push(Stack *stack, int item)
{
  if (stack == NULL) return -1;
  if (isFull(stack)) return 1;
  int index = ++stack->tail;
  stack->arr[index] = item;
  stack->size++;
  return 0;
}
/*-----------------------------------------------------------------------------*/

// pop() removes the last item on the stack.
// @Param:   stack       --  pointer to the stack to remove an item.
// @Return:  stack (update)
// @Return:  the poped item.
// @Require: none
// @Note:    none
int pop(Stack *stack)
{
  if (stack == NULL) {
    printf("Error popping the stack: stack is not initialized!\n");
    return -1;
  }
  if (isEmpty(stack)) {
    printf("Error popping the stack: stack is empty!\n");
    return -1;
  }
  int item = stack->arr[stack->tail--];
  stack->size--;
  return item;
}
/*-----------------------------------------------------------------------------*/

// peek() reads the last item on the stack.
// @Param:   stack -- pointer to the stack to read an item.
// @Return:  the last item on the stack.
// @Require: stack is not NULL/empty.
// @Note:    none 
int peek(Stack *stack)
{
  if (stack == NULL) {
    printf("Stack is not initialized!\n");
    return -1;
  }
  if (isEmpty(stack)) {
    printf("Stack is empty!\n");
    return -1;
  }
  int index = stack->tail;
  return stack->arr[index];
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions start here.
/*-----------------------------------------------------------------------------*/

// initStack() initializes properties of the stack.
// @Param:   stack       --  pointer to the Stack object.
// @Param:   capacity    --  the maximum number of integers the stack can store.
// @Return:  stack (update)
//           a code flag --  0 indicates stack is successfully initialized.
//                       --  1 indicates out of memory.
//                       -- -1 indicates stack is NULL.
// @Require: stack is not NULL.
// @Note:    none
int initStack(Stack *stack, int capacity)
{
  // queue must not be NULL.
  if (stack == NULL) return -1;

  // Initialize the arr property.
  stack->arr = (int *) calloc(capacity, sizeof(int));
  if (stack->arr == NULL) {
    fprintf(stderr, "Error initializing stack: out of memory!\n");
    return 1;
  }
  // Initialize other properties.
  stack->capacity = capacity;
  stack->size = 0;
  stack->tail = -1;
  
  // Success initialization.
  return 0;
}
/*-----------------------------------------------------------------------------*/

// freeStack() releases all the dynamic memories occupied by stack.
// @Param:   stack -- pointer to the Stack object to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeStack(Stack *stack)
{
  if (stack == NULL) return;
  if (stack->arr != NULL) free(stack->arr);
  free(stack);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/
