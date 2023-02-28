/* Copyright 2017 SPEL Technologies, Inc.
 * A Queue created using a singly linked list of nodes
 * Each Node stores a value of type Data
 *
 * MIT License
 */

#include "queue.h"

// create a node with specified Data and add it to the end of the queue
void enqueue(Data *newValue, Queue *queue) {

	Node *newNode = (Node *) calloc(sizeof(Node), 1);
	if (newNode == NULL) {
		printf("%s", "Error: memory could not be allocated");
		exit (EXIT_FAILURE);
	} else {
		newNode->value = newValue;
		newNode->next = NULL;

		if (queue->head == NULL) {
			queue->head = newNode;
			queue->tail = newNode;
			queue->tail->next = NULL;
		}
		else {
			queue->tail->next = newNode;
			queue->tail = newNode;
			queue->tail->next = NULL;
		}

		++queue->size;
	}
}

// remove and return the node at the front of the queue
Node *dequeue(Queue *queue) {
	if (queue->head == NULL) {
		printf("%s", "Error:empty queue");
		exit(EXIT_FAILURE);
	}

	Node *tmp = queue->head;
	queue->head = queue->head->next;
	tmp->next = NULL;
	--queue->size;
	return tmp;
}

// return 1 if queue is empty
int isEmpty(Queue *queue) {
	if (queue->size == 0)
		return 1;
	else
		return 0;
}

// print out the queue
void printQueue(Queue *queue) {
	printf("%s", "The queue is:");
	Node *ptr = queue->head;
	while (ptr != NULL) {
		printf("Node id : %d distance: %d predecessor: %d", (ptr->value)->id,   (ptr->value)->distance , (ptr->value)->predecessor);
		ptr = ptr->next;
	}
}

void deleteQueue(Queue *queue) {
	Node *ptr = queue->head;
	while (ptr != NULL) {
		Node *tmp = ptr;
		ptr = ptr->next;
		deleteNode(tmp);

	}
}

// Destructor
void deleteNode(Node *n) {
	if (n->value)
		free(n->value);
	n->value = NULL;
	free(n);
	n = NULL;
}

