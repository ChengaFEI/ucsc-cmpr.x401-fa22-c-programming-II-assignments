/* Author: SPEL Technologies, Inc.
 * circularQueue.h
 *
 * MIT License
 */

#ifndef CIRCULARQUEUE_H_
#define CIRCULARQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// define Data according to requirements
typedef struct Data_t {
	int id;
	int distance;
	int predecessor;
} Data;

// a node in the queue
typedef struct Node_t {
	Data value;
	struct Node_t *next;
} Node;

// queue has a head that points to first node and a tail that points to the last node.
typedef struct Queue_t {
	Node *head;
	Node *tail;
	unsigned int size;
} Queue;

Queue* createQueue();
void enqueue(Queue *queue, Data newValue);
Node* dequeue(Queue *queue); 	// remove and return the node at the front of the queue
bool isEmpty(Queue *queue);      // return true if queue is empty
void print(Queue *queue);        // print out the queue
void deleteAll(Queue **queue);   // delete all nodes in queue
#endif /* CIRCULARQUEUE_H_ */
