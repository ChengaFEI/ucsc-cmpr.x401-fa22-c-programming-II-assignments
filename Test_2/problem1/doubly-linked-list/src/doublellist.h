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
/*-----------------------------------------------------------------------------*/

// Node object in the doubly-linked-list.
typedef struct DouNode_t {
  int item;
  struct DouNode_t *prev;
  struct DouNode_t *next;
} DouNode;

// Doubly linked list object.
typedef struct {
  DouNode *head;
  DouNode *tail;
} DouList;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform major functionalities of the DouNode/DouList object.
int insert(DouList *douList, int item);
int deleteTail(DouList *douList);
int merge(DouList *douList, int sum);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionalities of the DouNode/DouList object.

// Log data.
void print(DouList *douList);
// Manage the memory.
void freeDouList(DouList *douList);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this group help with the major/minor functions' implementation.

// Helpers for freeDouList().
void freeDouNode(DouNode *douNode);
/*-----------------------------------------------------------------------------*/
