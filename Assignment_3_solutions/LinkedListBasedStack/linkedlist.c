/* Copyright SPEL Technologies, Inc.
 * linkedlist.c
 * A doubly linked list,
 */

#include "linkedlist.h"

DoublyLinkedList * createList() {
	DoublyLinkedList *list = (DoublyLinkedList *) malloc(sizeof(DoublyLinkedList));
	if (list == NULL) {
		printf("Error List could not be created");
		exit(-1);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

// insert a node at the given position
void insertNode(DoublyLinkedList *list, int x, int pos) {

	if (pos > list->size) {
		// throw an exception;
		printf("Error inserting node: position out of range");
		exit(-1);
	}

	node *newnode = (node *) calloc(sizeof(node), 1);
	if (newnode == NULL) {
		printf("Error: memory could not be allocated");
		exit(-1);
	}

	newnode->key = x;

	if (pos == 0) {// insert at head
		newnode->next = list->head;
		if (list->head != NULL)
			list->head->prev = newnode;
		else  // empty list
			list->tail = newnode;
		list->head = newnode;
	}
	else if (pos == list->size) { //insert at tail
		list->tail->next = newnode;
		newnode->prev = list->tail;
		list->tail = newnode;
	}
	else {
		node *ptr = list->head;
		int count = 0;
		while (count != pos) { // find the node at given position
			ptr = ptr->next;
			count++;
		}
		node *prevnode = ptr->prev;
		prevnode->next = newnode;
		newnode->prev = prevnode;
		newnode->next = ptr;
		ptr->prev = newnode;
	}

	++list->size;
}

// get the node at the front of the list
node *getNode(DoublyLinkedList *list, int pos) {
	if (pos >= list->size || pos < 0) {
		// throw an exception
		printf( "Error deleting node: position does not exist");
		exit(-1);
	}
	node *ptr = list->head;
	if (pos == 0) {
		ptr = list->head;
	}
	else if (pos == list->size - 1) {
		ptr = list->tail;
	}
	else {
		int count = 0;
		while (count != pos) {
			count++;
			ptr = ptr->next;
		}
	}
	return ptr;
}
// delete the node at the given position
node * deleteNode(DoublyLinkedList *list, int pos) {
	if (pos >= list->size || pos < 0) {
		// throw an exception
		printf( "Error deleting node: position does not exist");
		exit(-1);
	}
	node *ptr = NULL;
	if (pos == 0) { // first node
		list->head = list->head->next;
		if (list->head != NULL) // more than 1 node in list
			list->head->prev = NULL;
		else              // only 1 node in list
			list->tail = NULL;
	}

	else if (pos == list->size-1) { // last node
		ptr = list->tail;
		list->tail->prev->next = NULL;
		list->tail = list->tail->prev;
	}
	else { // node in the middle
		ptr = list->head;
		int count = 0;
		while (count != pos) { // find the node at given position
			ptr = ptr->next;
			count++;
		}
		node *prevnode = ptr->prev;
		node *nextnode = ptr->next;
		prevnode->next = ptr->next;
		nextnode->prev = ptr->prev;

	}
	list->size--;
	return ptr;
}


// print out the list
void print(DoublyLinkedList *list) {
	node *ptr = list->head;
	while(ptr != NULL) {
		printf("  %d ", ptr->key);
		ptr = ptr->next;
	}
	printf("\n");
}

// delete all the nodes in the list
void listDeleteAll(DoublyLinkedList *list) {
	node *ptr = list->head;

	while (ptr != NULL) {
		list->head = ptr->next;
		ptr->prev = NULL;
		free(ptr);
		ptr = list->head;
	}
	list->size = 0;
}



