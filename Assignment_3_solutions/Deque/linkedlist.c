/* Copyright SPEL Technologies, Inc.
 * linkedlist.c
 * A doubly linked list on the heap
 *
 *
 */

#include "linkedlist.h"


// search for Node with given key and return a pointer to it
struct Node* listSearch(LinkedList *list, int key) {
	struct Node *ptr = list->head;

	while (ptr != NULL && ptr->data.key != key) {
		ptr = ptr->next;
	}
	return ptr;
}

// insert a new node with given key at front of list; assume list is not NULL
void listInsert(LinkedList *list, int key) {
	struct Node *newNode = (struct Node *) calloc(sizeof(struct Node), 1);
	if (newNode == NULL) {
		printf("%s", "Error: memory could not be allocated");
		exit (EXIT_FAILURE);
	} else {
		newNode->next = list->head;
		newNode->prev = NULL;
		newNode->data.key = key;

		if (list->head != NULL) {
			list->head->prev = newNode;
		}

		list->head = newNode;
		if (list->tail == NULL)
			list->tail = newNode;

	}
	list->size++;
}

// insert a new node at given position, pos is FRONT or END; assumes list is not NULL
void listInsertAtPosition(LinkedList *list, int key, enum position pos) {
	struct Node *newNode = (struct Node *) calloc(sizeof(struct Node), 1);
	if (newNode == NULL) {
		printf("%s", "Error: memory could not be allocated");
		exit (EXIT_FAILURE);
	} else {

		// insert at front
		if (pos == FRONT) {
			newNode->prev = NULL;

			newNode->next = list->head;
			newNode->data.key = key;

			if (list->head != NULL) {
				list->head->prev = newNode;
			}

			list->head = newNode;
			if (list->tail == NULL)
				list->tail = newNode;

		}
		// insert at end
		else if (pos == END) {
			newNode->next =  NULL;
			newNode->data.key = key;

			if (list->tail != NULL)
				list->tail->next = newNode;

			newNode->prev = list->tail;

			list->tail = newNode;
			if (list->head == NULL)
				list->head = newNode;


		}

	}
	list->size++;
}

// delete the given node x from the list and return it; assumes list is not NULL
void listDelete(LinkedList *list, struct Node *x) {

	if (list == NULL || list->head == NULL) {
		printf("Error: cannot delete from empty list");
	}
	if (x == NULL) {
		printf("Error: cannot delete NULL node");
	}
	// x is the first node
	if (x->prev == NULL) {
		if (x->next != NULL) {
			list->head = x->next;
			x->next->prev = NULL;
		}
		else {
			list->head = NULL;
			list->tail = NULL;
		}
	}
	// x is the last node
	else if (x->next == NULL) {
		list->tail = x->prev;
		x->prev->next = NULL;
	}
	// x is in the middle
	else {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}
	list->size--;
	free(x);
	x = NULL;
}

// remove the given node x from the list and return it; assumes list is not NULL
struct Node * listRemove(LinkedList *list, struct Node *x) {

	if (list == NULL || list->head == NULL) {
		printf("Error: cannot delete from empty list");
		return NULL;
	}
	if (x == NULL) {
		printf("Error: cannot delete NULL node");
		return NULL;
	}
	// x is the first node
	if (x->prev == NULL) {
		if (x->next != NULL) {
			list->head = x->next;
			x->next->prev = NULL;
		}
		else {
			list->head = NULL;
			list->tail = NULL;
		}
	}
	// x is the last node
	else if (x->next == NULL) {
		list->tail = x->prev;
		x->prev->next = NULL;
	}
	// x is in the middle
	else {
		x->prev->next = x->next;
		x->next->prev = x->prev;
	}

	list->size--;
	return x;

}

void listPrint(LinkedList *list) {
	struct Node *ptr = list->head;

	while (ptr != NULL) {
		printf("%d \n", ptr->data.key);
		ptr = ptr->next;
	}
}

void listDeleteAll(LinkedList *list) {
	struct Node *ptr = list->head;

	while (ptr != NULL) {
		list->head = ptr->next;
		ptr->prev = NULL;
		free(ptr);
		ptr = list->head;
	}
	list->size = 0;
}


LinkedList * createList() {
	LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
	if (list == NULL) {
		printf("Error List could not be created");
		exit(-1);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return list;
}

// Exercise: add a function to insert an element at position p, where the first element is at position 0
// Exercise: add a function to remove the element at position p, where the first element is at position 0

// This main function tests the linked list
/*int main(void) {
	LinkedList *list = createList();


	listInsert(list, 10);
	listInsert(list, 20);
	listInsert(list, 5); // list contains nodes 5, 20, 10 in that order

	listDelete(list, list->head); // removes 1st element
	listDelete(list, list->head); // removes 2nd element
	//listDelete(list, list->head); // removes 3rd element
	//listDelete(list, list->head); // displays error

	listInsert(list, 5); // list contains nodes 5, 20, 10 in that order
	listInsert(list, 15); // list contains nodes 5, 20, 10 in that order
	listInsert(list, 25); // list contains nodes 5, 20, 10 in that order
	listInsertAtPosition(list, 250, FRONT); // removes 2nd element
	listInsertAtPosition(list, 2500, FRONT); // removes 2nd element

	listPrint(list);
	listDeleteAll(list);

	return EXIT_SUCCESS;
}*/
