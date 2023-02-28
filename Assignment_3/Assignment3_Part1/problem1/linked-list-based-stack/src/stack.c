//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 1
//
// stack.c
// linked-list-based-stack
// 
// Object: StackNode, Stack.
// 

#include <stdlib.h>
#include <stdio.h>

#include "stack.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// push() adds a new Node to the stack.
// @Param:   stack -- pointer to the stack to accept the new Node.
// @Param:   item  -- the value of the new Node to insert.
// @Return:  stack (update)
// @Require: stack must have a memory.
// @Note:    none.
void push(Stack *stack, int item)
{
  // stack must have a memory.
  if (stack == NULL) return;
  // Create a new StackNode with the item value.
  StackNode *node = (StackNode *) malloc(sizeof(StackNode));
  if (node == NULL) {
    fprintf(stderr, "Error pushing a new StackNode.\n");
    exit(EXIT_FAILURE);
  } 
  node->item = item;
  // Push the new StackNode to the stack.
  node->next = stack->head;
  stack->head = node;
  stack->size++;
}
/*-----------------------------------------------------------------------------*/

// pop() removes the last Node in the stack.
// @Param:   stack -- pointer to the stack to remove a Node.
// @Return:  stack (update)
// @Require: stack must have a memory.
// @Note:    none
void pop(Stack *stack)
{
  // Stack must have a memory.
  if (stack == NULL) return;
  if (stack->head == NULL) printf("The stack is empty!\n");
  else {
    StackNode *rmNode = stack->head;
    stack->head = stack->head->next;
    rmNode->next = NULL;
    free(rmNode);
    stack->size--;
  }
}
/*-----------------------------------------------------------------------------*/

// peek() returns the last Node in the stack.
// @Param:   stack -- pointer to the stack.
// @Return:  none
// @Require: stack must have a memory.
// @Note:    none
StackNode *peek(Stack *stack)
{
  // stack must have a memory.
  if (stack == NULL) return NULL;
  StackNode *node = stack->head;
  return node;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions start here.
/*-----------------------------------------------------------------------------*/

// printStack() prints all StackNodes in the stack.
// @Param:   stack -- pointer to the Stack object to be displayed.
// @Return:  none
// @Require: none
// @Note:    none
void printStack(Stack *stack) 
{
  if (stack == NULL) return;
  StackNode *currNode = stack->head;
  printf("The stack contains: ");
  while (currNode != NULL) {
    printf("%d ", currNode->item);
    currNode = currNode->next;
  }
  printf("\n");
}
/*-----------------------------------------------------------------------------*/

// freeStack() releases all memeories occupied by the stack.
// @Param:   stack -- pointer to the stack to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeStack(Stack *stack)
{
  if (stack == NULL) return;
  freeStackNodes(stack->head);
  free(stack);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/

// freeStackNodes() recursively releases the memory occupied by the given StackNode and all nodes after it.
// @Param:   node -- pointer to the node to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeStackNodes(StackNode *node)
{
  if (node == NULL) return;
  freeStackNodes(node->next);
  free(node);
}
/*-----------------------------------------------------------------------------*/
