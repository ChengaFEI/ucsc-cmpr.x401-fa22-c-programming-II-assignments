
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>

typedef struct Data_t {
	int id;
	int distance;
	int predecessor;
} Data;

// a node in the queue
typedef struct Node_t {
	Data *value;
	struct Node_t *next;   // pointer to next node in the queue
} Node;


// queue has a head that points to first node and a tail that points to the last node.
typedef struct Queue_t {
	Node *head;
	Node *tail;
	int size;
} Queue;

void enqueue(Data *newValue, Queue *queue) ;
Node *dequeue(Queue *queue);
int isEmpty(Queue *queue);
void printQueue(Queue *queue);
void deleteQueue(Queue *queue);
void deleteNode(Node *n);

#endif /* QUEUE_H_ */
