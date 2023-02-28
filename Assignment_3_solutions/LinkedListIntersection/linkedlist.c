/* Copyright SPEL Technologies, Inc.
 * linkedlist.c
 * Uses doubly linked list,
 *  Finds the
 * intersection and union of two sorted lists
 *
 *
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

// return a new list with the intersection of elements in two sorted lists
DoublyLinkedList *intersection(DoublyLinkedList *list, DoublyLinkedList *list2) {
	DoublyLinkedList *newList = createList();

	node *ptr1 = list->head;
	node *ptr2 = list2->head;

	while(ptr1 != NULL && ptr2 != NULL) {
		// if both lists contain same key, insert it into list2
		if (ptr1->key == ptr2->key) {
			// insert at end of newList
			int size = newList->size;
			insertNode(newList, ptr1->key, size);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		// key of list1 is smaller than key of list2; increment list1's ptr
		else if (ptr1->key < ptr2->key)
			ptr1 = ptr1->next;
		// key of list2 is smaller than key of list1; increment list2's ptr
		else if (ptr2->key < ptr1->key)
			ptr2 = ptr2->next;
	}

	return newList;
}


// return a new list with the union of elements in two sorted lists
DoublyLinkedList * unionOp(DoublyLinkedList *list, DoublyLinkedList *list2) {
	DoublyLinkedList *newList = createList();

	node *ptr1 = list->head;
	node *ptr2 = list2->head;

	while(ptr1 != NULL && ptr2 != NULL) {
		// if both lists contain same key, insert it once  into list2
		if (ptr1->key == ptr2->key) {
			// insert at end of newList
			int size = newList->size;
			insertNode(newList, ptr1->key, size);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		// key of list1 is smaller than key of list2 - insert it into newList and increment ptr1
		else if (ptr1->key < ptr2->key)  {
			// insert at end of newList
			int size = newList->size;
			insertNode(newList, ptr1->key, size);
			ptr1 = ptr1->next;
		}
		// key of list2 is smaller than key of list1 - insert it into newList and increment ptr2
		else if (ptr2->key < ptr1->key) {
			// insert at end of newList
			int size = newList->size;
			insertNode(newList, ptr2->key, size);
			ptr2 = ptr2->next;
		}
	}
	// copy remaining elements of list1 into newList
	while(ptr1 != NULL) {
		// insert at end of newList
		int size = newList->size;
		insertNode(newList, ptr1->key, size);
		ptr1 = ptr1->next;
	}
	// copy remaining elements of list2 into newList
	while(ptr2 != NULL) {
		// insert at end of newList
		int size = newList->size;
		insertNode(newList, ptr2->key, size);
		ptr2 = ptr2->next;
	}
	return newList;
}


int main() {

		DoublyLinkedList *list1 = createList();
		DoublyLinkedList *list2 = createList();
		// create list1
		insertNode(list1, 10, 0);
		insertNode(list1, 20, 1);
		insertNode(list1, 30, 2);
		insertNode(list1, 40, 3);
		insertNode(list1, 80, 4);
		insertNode(list1, 100, 5);
	    insertNode(list1, 140, 6);
	    printf("list1: ");
		print(list1);

		// create list2
		insertNode(list2, 20, 0);
		insertNode(list2, 40, 1);
		insertNode(list2, 60, 2);
		insertNode(list2, 100, 3);
		insertNode(list2, 200, 4);
	    printf("list2: ");
		print(list2);

		DoublyLinkedList *list3 = intersection(list1, list2);
		printf("The result of intersection is \n");
		print(list3);

		DoublyLinkedList *list4 = unionOp(list1, list2);
		printf("The result of union is \n");
		print(list4);

		listDeleteAll(list1);
		listDeleteAll(list2);
		listDeleteAll(list3);
		listDeleteAll(list4);


		// Testcase 1
		//list1 : 1, 3, 4, 8
		//list2 :  2, 5
		insertNode(list1, 1, 0);
		insertNode(list1, 3, 1);
		insertNode(list1, 4, 2);
		insertNode(list1, 8, 3);
		insertNode(list2, 2, 0);
		insertNode(list2, 5, 1);

		printf("\nTest case 1: \n");
		list3 = unionOp(list1, list2);  // 1, 2, 3, 4, 5, 8
		print(list3);
		listDeleteAll(list1);
		listDeleteAll(list2);
		listDeleteAll(list3);

		// Testcase 2
		//list1 : 1, 3, 4, 8
		//list2 :  2, 3, 4, 5
		insertNode(list1, 1, 0);
		insertNode(list1, 3, 1);
		insertNode(list1, 4, 2);
		insertNode(list1, 8, 3);
		insertNode(list2, 2, 0);
		insertNode(list2, 3, 1);
		insertNode(list2, 4, 2);
		insertNode(list2, 5, 3);
		list3 = intersection(list1, list2);  //3, 4
		printf("\nTest case 2: \n");

		print(list3);
		listDeleteAll(list1);
		listDeleteAll(list2);
		listDeleteAll(list3);

		// Testcase 3
		//list1 : 1, 2, 4, 5, 10, 12
		//list2 : 1, 2, 3, 4, 5, 6, 7, 8
		insertNode(list1, 1, 0);
		insertNode(list1, 2, 1);
		insertNode(list1, 4, 2);
		insertNode(list1, 5, 3);
		insertNode(list1, 10, 4);
		insertNode(list1, 12, 5);
		insertNode(list2, 1, 0);
		insertNode(list2, 2, 1);
		insertNode(list2, 3, 2);
		insertNode(list2, 4, 3);
		insertNode(list2, 5, 4);
		insertNode(list2, 6, 5);
		insertNode(list2, 7, 6);
		insertNode(list2, 8, 7);
		list3 = intersection(list1, list2); // 1, 2, 4, 5
		printf("\nTest case 3 intersection: \n");
		print(list3);
		listDeleteAll(list3);

		printf("\nTest case 3 union: \n");
		list3 = unionOp(list1, list2);  // 1, 2, 3, 4, 5, 6, 7, 8, 10, 12
		print(list3);

		listDeleteAll(list1);
		listDeleteAll(list2);
		listDeleteAll(list3);


}

