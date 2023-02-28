/*
 * linkedlist.h
 *
 *
 *      Author: SPEL Technologies, Inc.
 *      MIT License
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

struct Data {
	int key;
};

struct Node {
	struct Data data;
	struct Node *next;
};

struct Node* listSearch(struct Node *head, int key);
void listInsert(struct Node **head, int key);  // insert a new node with given key at front of list
void listDelete(struct Node **head, struct Node *x);  // delete node x
void listPrint(struct Node *head);

#endif /* LINKEDLIST_H_ */
