//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 4
//
// linked-list-based-deque
// deque.c
// 
// Object: Deque, Node
// 

#include <stdlib.h>
#include <stdio.h>

#include "deque.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// push() adds a new item to the deque from the head-end.
// @Param:   deque       -- pointer to the deque to accept the bew item.
// @Param:   item        -- the item to add.
// @Return:  deque (update)
// @Return:  status flag -- 0 indicates deque successfully adds the item.
//                       -- 1 indicates deque is NULL.
// @Require: none
// @Note:    none
int push(Deque *deque, int item)
{
  if (!dequeExists(deque)) return 1;
  Node *node = (Node *) malloc(sizeof(Node));
  node->item = item;
  node->prev = NULL;
  node->next = deque->head;
  if (isEmpty(deque)) deque->head = deque->tail = node;
  else {
    deque->head->prev = node;
    deque->head = node;
  } 
  deque->size++;
  return 0; // Success.
}
/*-----------------------------------------------------------------------------*/

// pop() removes the head item from the deque from the head-end.
// @Param:   deque -- pointer to the deque to remove items.
// @Return:  deque (update)
// @Return:  status flag -- 0 indicates deque successfully adds the item.
//                       -- 1 indicates deque is NULL/empty.
// @Require: deque is not NULL.
// @Require: deque is not empty.
// @Note:    none
int pop(Deque *deque)
{
  if (!dequeExists(deque) || isEmpty(deque)) {
    printf("Error popping the deque.\n");
    return 1;
  }
  Node *node = getHead(deque);
  if (getSize(deque) == 1) deque->head = deque->tail = NULL;
  else {
    deque->head->next->prev = NULL;
    deque->head = deque->head->next;
  }
  deque->size--;
  free(node);
  return 0;
}
/*-----------------------------------------------------------------------------*/

// inject() adds an item to the deque from the tail-end.
// @Param:   deque       -- pointer to the deque to add an item.
// @Param:   item        -- the item value to add.
// @Return:  deque (update)
// @Return:  status flag -- 0 indicates deque successfully adds the item.
//                       -- 1 indicates deque is NULL.
// @Require: none
// @Note:    none
int inject(Deque *deque, int item)
{
  if (!dequeExists(deque)) return 1;
  Node *node = (Node *) malloc(sizeof(Node));
  node->item = item;
  node->next = NULL;
  node->prev = deque->tail;
  if (!nodeExists(getHead(deque))) deque->head = deque->tail = node;
  else {
    deque->tail->next = node;
    deque->tail = node;
  }
  deque->size++;
  return 0;
}
/*-----------------------------------------------------------------------------*/

// eject() removes the head item from the deque from the tail-end.
// @Param:   deque -- pointer to the deque to remove items.
// @Return:  deque (update)
// @Return:  status flag -- 0 indicates deque successfully adds the item.
//                       -- 1 indicates deque is NULL.
// @Require: deque is not NULL.
// @Require: deque is not empty.
// @Note:    none
int eject(Deque *deque)
{
  if (!dequeExists(deque) || isEmpty(deque)) {
    printf("Error ejecting the deque.\n");
    return 1;
  }
  Node *node = getTail(deque);
  if (getSize(deque) == 1) deque->head = deque->tail = NULL;
  else {
    deque->tail = deque->tail->prev;
    deque->tail->next = NULL;
  }
  deque->size--;
  free(node);
  return 0;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions start here.
/*-----------------------------------------------------------------------------*/

// printDouList() displays all the data stored in the deque.
// @Param:   deque -- pointer to the deque.
// @Return:  none
// @Require: none
// @Note:    none
void printDeque(Deque *deque)
{
  if (!dequeExists(deque)) return;
  printf("The items in the doubly linked list are: ");
  Node *currNode = getHead(deque);
  if (currNode == NULL) printf("(empty)");
  while (nodeExists(currNode)) {
    printf("%d ", getItem(currNode));
    currNode = getNext(currNode);
  }
  printf("\n");
}
/*-----------------------------------------------------------------------------*/

// freeDeque() releases all the dynamic memories occupied by the deque.
// @Param:   deque -- pointer to the Deque object to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeDeque(Deque *deque)
{
  if (deque == NULL) return;
  Node *head = getHead(deque);
  if (nodeExists(head)) freeNode(head);
  free(deque);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/

// freeNode() frees the memory occupied by the Node object.
// @Param:   node -- pointer to the Node object.
// @Return:  none
// @Require: none
// @Note:    none
void freeNode(Node *node)
{
  if (!nodeExists(node)) return;
  freeNode(getNext(node));
  free(node);
}
/*-----------------------------------------------------------------------------*/
