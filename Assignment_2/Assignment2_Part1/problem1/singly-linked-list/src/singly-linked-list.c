// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Problem 1
//
// singly-linked-list.c
// singly-linked-list
// 
// Function: A singly linked list structure and its functions' implementation.

#include <stdlib.h>
#include <stdio.h>

#include "singly-linked-list.h"
/*-----------------------------------------------------------------------------*/

int main(void)
{
  struct Node *list = NULL;
	listInsert(&list, 10);
	listInsert(&list, 20);
	listInsert(&list, 5);    // List contains nodes 5, 20, 10 in that order.
	listDelete(&list, list); // Remove the first node in the list.
	listDelete(&list, list); // Remove the first node in the list.
	listPrint(list);
	listDeleteAll(list);
	return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// listSearch() searchs for Node with given key and returns a pointer to it.
// @Param:   head -- pointer to the head node in the list.
// @Param:   key  -- the value to search for in the list.
// @Return:  pointer to the matched node.
//           if no such value exists, return NULL.
// @Require: none
struct Node* listSearch(struct Node *head, int key) 
{
	struct Node *ptr = head;
	while (ptr != NULL && ptr->data.key != key) ptr = ptr->next;
	return ptr;
}
/*-----------------------------------------------------------------------------*/

// listInsert() inserts a new node with given key at the front of list.
// @Param:   head -- pointer to first node's address.
// @Param:   key  -- the value to be inserted at the front of the list.
// @Return:  head (update)
// @Require: none
void listInsert(struct Node **head, int key) 
{
	struct Node *newNode = (struct Node *) calloc(sizeof(struct Node), 1);
	if (newNode == NULL) {
		printf("%s", "Error: memory could not be allocated");
		exit (EXIT_FAILURE);
	} else {
		newNode->next = (*head);
		newNode->data.key = key;
		(*head) = newNode;
	}
}
/*-----------------------------------------------------------------------------*/

// listDelete() deletes the given node x.
// @Param:   head -- pointer to the first node's address.
// @Param:   x    -- pointer to the node to be deleted.
// @Return:  head (update)
// @Require: x must be in the list.
void listDelete(struct Node **head, struct Node *x) 
{
  // Basic variables.
	struct Node *lastNode = *head; // Record the last visited node.
  struct Node *currNode = *head; // Record the current node.

  // If x is the head node.
  if (*head == x) *head = x->next;
  // If x is in the middle or at the end.
  else {
    while (currNode != NULL) {
      if (currNode == x) {
        lastNode->next = currNode->next;
        break;
      }
      lastNode = currNode;
      currNode = currNode->next;
    }
  }

  // Release the dynamic memory and update the pointer.
	free(x);
	x = NULL;
}
/*-----------------------------------------------------------------------------*/

// listPrint() displays all the nodes' data in the list on the console.
// @Param:   head -- pointer to the first node in the list.
// @Return:  none
// @Require: none
void listPrint(struct Node *head) {
	struct Node *ptr = head;
	while (ptr != NULL) {
		printf("%d \n", ptr->data.key);
		ptr = ptr->next;
	}
}
/*-----------------------------------------------------------------------------*/

// listDeleteAll() deletes all the nodes in the list.
// @Param:   head -- pointer to the first node in the list.
// @Return:  head (update)
// @Require: none
void listDeleteAll(struct Node *head) {
	struct Node *ptr = head;
	while (ptr != NULL) {
		head = ptr->next;
		free(ptr);
		ptr = head;
	}
}
/*-----------------------------------------------------------------------------*/