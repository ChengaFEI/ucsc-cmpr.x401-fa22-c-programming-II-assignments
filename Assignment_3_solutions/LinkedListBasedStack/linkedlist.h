/*
 * linkedlist.h
 *
 *
 *      Author: SPEL Technologies, Inc.
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>


typedef struct node_t {
  int key;
  struct node_t *prev;
  struct node_t *next;
} node;

typedef struct DoublyLinkedList_t {

      node *head;
      node *tail;
      int size;
} DoublyLinkedList;

DoublyLinkedList *createList();
void insertNode(DoublyLinkedList *list, int x, int pos);
node * deleteNode(DoublyLinkedList *list, int pos);
void print(DoublyLinkedList *list);
node *getNode(DoublyLinkedList *list, int pos);

#endif /* LINKEDLIST_H_ */
