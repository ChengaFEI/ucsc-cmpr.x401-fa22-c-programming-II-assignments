
#include "deque.h"
#include "linkedlist.h"

// Reuse the methods in DoublyLinkedList here
void push(Deque *d, int x) {
	listInsertAtPosition(d->list, x, FRONT);
}

struct Node *pop(Deque *d) {
	return listRemove(d->list, d->list->head);
}

void inject(Deque *d, int x) {
	listInsertAtPosition(d->list, x, END);
}

struct Node *eject(Deque *d) {
	return listRemove(d->list, d->list->tail);
}

Deque * createDeque() {
	Deque *d = (Deque *) calloc(sizeof(Deque), 1);
	if (d == NULL) {
		printf("Error deque is NULL");
		return NULL;
	}
	else  {
		d->list = createList();
		return d;
	}
}

void print(Deque *d) {
	printf("The list is: \n");
	listPrint(d->list);
}

int main(void) {
	Deque *d = createDeque();

	if (d == NULL) {
		printf("Error memory could not be allocated");
		exit (-1);
	}
	LinkedList *list = createList();
	// Test case 1
	/*push(d, 7);
    push(d, 6);
    push(d, 7);
    push(d, 8);
    print(d);
    pop(d);
    pop(d);
    print(d);*/

	// Test case 2
	/*inject(d, 7);
	inject(d, 6);
	inject(d, 7);
	inject(d, 8);
	print(d);	//	7,	6,	7,	8
	pop(d);
	pop(d);
	print(d);	//	7,	8
	eject(d);
	eject(d);
	print(d);	//	List	is	empty */

	// Test case 3
	/*inject(d,	2);
	 inject(d,	6);
	 print(d);	//	2,	6
	 eject(d);
	 eject(d);
	 print(d);	//List	is	empty
	 push(d,	8);
	 push(d,	9);
	 print(d);	//	9,	8
	 pop(d);
	 print(d);	//	8
	 */

	// Testcase 4
	pop(d);	//	Error	message
	eject(d);	//Error	message
	push(d,	2);
	push(d,	3);
	push(d,	4);
	push(d,	5);
	push(d,	6);
	push(d,	7);
	push(d,	8);
	push(d,	9);
	inject(d,	5);
	print(d);	//	9,	8,	7,	6,	5,	4,	3,	2,	5
	pop(d);
	pop(d);
	print(d);	//	7,	6,	5,	4,	3,	2,	5
	eject(d);
	eject(d);
	print(d);	//	7,	6,	5,	4,	3
	return EXIT_SUCCESS;
}
