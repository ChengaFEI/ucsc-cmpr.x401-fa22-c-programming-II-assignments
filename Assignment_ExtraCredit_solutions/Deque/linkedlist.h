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

enum position {FRONT, END};

struct Data {
	int key;
};

struct Node {
	struct Data data;
	struct Node *prev;
	struct Node *next;
};

typedef struct LinkedList_t {
	struct Node *head;
	struct Node *tail;
	int size;
} LinkedList;

struct Node* listSearch(LinkedList *list, int key);
void listInsert(LinkedList *list, int key);  // insert a new node with given key at front of list
void listInsertAtPosition(LinkedList *list, int key, enum position pos);
void listDelete(LinkedList *list, struct Node *x);  // delete node x
struct Node * listRemove(LinkedList *list, struct Node *x);
void listPrint(LinkedList *list);
void displayDeque();
LinkedList * createList() ;

#endif /* LINKEDLIST_H_ */
