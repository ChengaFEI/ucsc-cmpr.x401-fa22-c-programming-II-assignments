// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 2
// Problem 1
//
// doubly-linked-list
// doublellist.h
// 
// Object: DouList, DouNode.

#include <stdlib.h>
#include <stdio.h>

#include "doublellist.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions.
/*-----------------------------------------------------------------------------*/

// insert() adds a new item at the front of the list.
// @Param:   douList     -- pointer to the doubly-linked-list.
// @Param:   item        -- the new item.
// @Return:  douList (update)
// @Return:  status flag -- 0 indicates the successful insertion.
//                          1 indicates the douList is NULL.
// @Require: none
// @Note:    none
int insert(DouList *douList, int item)
{
  if (douList == NULL) return 1;
  // Create a new DouNode.
  DouNode *douNode = (DouNode *) malloc(sizeof(DouNode));
  douNode->item = item;
  douNode->prev = NULL;
  douNode->next = douList->head;
  if (douList->head == NULL) douList->head = douList->tail = douNode;
  else {
    douList->head->prev = douNode;
    douList->head = douNode;
  }
  return 0;
}
/*-----------------------------------------------------------------------------*/

// deleteTail() removes the tail node in the list.
// @Param:   douList     --  pointer to the doubly-linked-list.
// @Return:  douList (update)
// @Return:  status flag --  0 indicates the successful deletion.
//                       --  1 indicates an empty list.
//                       -- -1 indicates a NULL list.
// @Require: none
// @Note:    none
int deleteTail(DouList *douList)
{
  if (douList == NULL) return -1;
  // Empty list.
  if (douList->head == NULL) return 1;
  // Create a new Node.
  DouNode *douNode = douList->tail;
  if (douList->head == douList->tail) douList->head = douList->tail = NULL;
  else {
    douList->tail = douList->tail->prev;
    douList->tail->next = NULL;
  }
  free(douNode);
  return 0;
}
/*-----------------------------------------------------------------------------*/

// merge() merges two adjacent nodes in the list whose sum equals the given sum.
// @Param:   douList     -- pointer to the doubly-linked-list.
// @Param:   sum         -- the sum value.
// @Return:  douList (update)
// @Return:  status flag --  0 indicates the successful merge.
//                       --  1 indicates an empty list.
//                       -- -1 indicates a NULL list.
// @Require: none
// @Note:    none
int merge(DouList *douList, int sum)
{
  if (douList == NULL) return -1;
  DouNode *douNode = douList->head;
  if (douNode == NULL) return 1;

  int item1, item2;
  while (douNode != NULL && douNode->next != NULL) {
    item1 = douNode->item;
    item2 = douNode->next->item;
    if (item1 + item2 == sum) {
      DouNode *newNode = (DouNode *) malloc(sizeof(DouNode));
      newNode->item = sum;
      newNode->prev = douNode->prev;
      newNode->next = douNode->next->next;
      if (douNode == douList->head) douList->head = newNode;
      else douNode->prev->next = newNode;
      if (douNode->next == douList->tail) douList->tail = newNode;
      else douNode->next->next->prev = newNode;
      // Free original two nodes.
      free(douNode->next);
      free(douNode);
      douNode = newNode;
    }
    douNode = douNode->next;
  }
  return 0;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions.
/*-----------------------------------------------------------------------------*/

// print() displays all the nodes in the list on the console.
// @Param:   douList -- pointer to the doubly-linked-list to be displayed.
// @Return:  none
// @Require: none
// @Note:    none
void print(DouList *douList)
{
  if (douList == NULL) return;
  printf("Nodes in the list: ");
  DouNode *douNode = douList->head;
  if (douNode == NULL) printf("NULL");
  else {
    while (douNode != NULL) {
      printf("%d ", douNode->item);
      douNode = douNode->next;
    }
  }
  printf("\n");
}
/*-----------------------------------------------------------------------------*/

// freeDouList() releases memories occupied by the douList.
// @Param:   douList -- pointer to the douList to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeDouList(DouList *douList)
{
  if (douList == NULL) return;
  if (douList->head != NULL) freeDouNode(douList->head);
  free(douList);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions.
/*-----------------------------------------------------------------------------*/

// freeDouNode() releases memories occupied by the douNode.
// @Param:   douNode -- pointer to the douNode to be freed.
// @Return:  none
// @Require: none
// @note:    none
void freeDouNode(DouNode *douNode) 
{
  if (douNode == NULL) return;
  freeDouNode(douNode->next);
  free(douNode);
}
/*-----------------------------------------------------------------------------*/
