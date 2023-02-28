/* Copyright SPEL Technologies, Inc.
 * linkedlist.c
 * A doubly linked list
 *
 * MIT License
 */

#include "linkedlist.h"

// search for Node with given key and return a pointer to it
struct Node* listSearch(struct Node *head, int key) {
	struct Node *ptr = head;

	while (ptr != NULL && ptr->data.key != key) {
		ptr = ptr->next;
	}
	return ptr;
}

// insert a new node with given key at front of list
void listInsert(struct Node **head, int key) {
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

// delete the given node x
void listDelete(struct Node **head, struct Node *x) {

	// x is the first node
	if ( (*head) == x) {
		if (x->next != NULL) {
			(*head) = x->next;
		}
		else *head = NULL;
	}
	// x is the last node
	else if (x->next == NULL) {
		// iterate over the list and set the pointer of the previous node to NULL
		struct Node *ptr = (*head);
		while ( ptr->next != x)
			ptr = ptr->next;

		ptr->next = NULL;
	}
	// x is in the middle
	else {
		// iterate over the list and set the pointer of the previous node to point to the node after x
			struct Node *ptr = (*head);
			while ( ptr->next != x)
				ptr = ptr->next;
			ptr->next = x->next;
	}

	free(x);
	x = NULL;
}

void listPrint(struct Node *head) {
	struct Node *ptr = head;

	while (ptr != NULL) {
		printf("%d \n", ptr->data.key);
		ptr = ptr->next;
	}
}

void listDeleteAll(struct Node *head) {
	struct Node *ptr = head;

	while (ptr != NULL) {
		head = ptr->next;
		free(ptr);
		ptr = head;
	}
}

// Exercise: add a function to insert an element at position p, where the first element is at position 0
// Exercise: add a function to remove the element at position p, where the first element is at position 0

int main(void) {
	struct Node *list = NULL;

	listInsert(&list, 10);
	listInsert(&list, 20);
	listInsert(&list, 5); // list contains nodes 5, 20, 10 in that order
	listDelete(&list, list); // removes the element after 5
	//listDelete(&list, list); // removes the element after 5
	//listDelete(&list, list); // removes the element after 5
	listPrint(list);
	listDeleteAll(list);
	return EXIT_SUCCESS;
}
