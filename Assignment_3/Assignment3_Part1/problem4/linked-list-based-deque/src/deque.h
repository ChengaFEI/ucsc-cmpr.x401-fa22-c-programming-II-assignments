//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 4
//
// linked-list-based-deque
// deque.h
// 
// Object: Deque, Node
// 

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

// Node object.
typedef struct Node_t {
  int item;           // The value stored in the current node.
  struct Node_t *next; // pointer to the next list node.
  struct Node_t *prev; // pointer to the previous list node.
} Node;

// Deque object based on the doubly linked list.
typedef struct {
  Node *head; // pointer to the first Node in the list.
  Node *tail; // pointer to the last Node in the list.
  int size;   // The number of all nodes in the doubly linked list.
} Deque;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this groups perform major functionalities of Deque object.
int push(Deque *deque, int item);
int pop(Deque *deque);
int inject(Deque *deque, int item);
int eject(Deque *deque);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this groups perform auxiliary functionalities of Deque object.

// Log data messages.
void printDeque(Deque *deque);
// Manage the memory.
void freeDeque(Deque *deque);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this groups help with major/minor functions' implementation.

// Helpers for freeDouList().
void freeNode(Node *node);
/*-----------------------------------------------------------------------------*/

// Macro functions.
#define nodeExists(node)   ((node)!=NULL)     // node  -- pointer to Node.
#define getItem(node)      ((node)->item)     // node  -- pointer to Node.
#define getNext(node)      ((node)->next)     // node  -- pointer to Node.
#define getPrev(node)      ((node)->prev)     // node  -- pointer to Node.
#define dequeExists(deque) ((deque)!=NULL)    // deque -- pointer to Deque.
#define getHead(deque)     ((deque)->head)    // deque -- pointer to Deque.
#define getTail(deque)     ((deque)->tail)    // deque -- pointer to Deque.
#define getSize(deque)     ((deque)->size)    // deque -- pointer to Deque.
#define isEmpty(deque)     ((deque)->size==0) // deque -- pointer to Deque.
/*-----------------------------------------------------------------------------*/