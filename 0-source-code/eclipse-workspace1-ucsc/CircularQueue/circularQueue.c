/* Copyright SPEL Technologies, Inc.
 * circularQueue.c
 * A circular queue created with a linked list
 *
 *
 */
#include "circularQueue.h"

// create an empty queue
Queue* createQueue() {
	Queue *queue = (Queue *)  calloc(sizeof(Queue), 1);
	if (queue == NULL) {
		fprintf(stderr, "Error: Queue could not be created");
		exit(EXIT_FAILURE);
	}
    *queue = (Queue) {.head = NULL, .tail = NULL, .size = 0};
    return queue;
}

// create a node with specified Data and add it to the end of the queue
void enqueue(Queue *queue, Data newValue) {
	Node *newNode = (Node *) calloc(sizeof(Node), 1);

	if (newNode == NULL) {
		fprintf(stderr, "Error: memory could not be allocated");
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
Node* dequeue(Queue *queue){
	if (queue->head == NULL) {
		printf("%s","empty queue");
		return NULL;
	}
	else {
		Node *tmp = queue->head;
		queue->head = queue->head->next;

		--queue->size;
		return tmp;
	}

}

// return true if queue is empty
bool isEmpty(Queue *queue){
	if (queue->size == 0)
		return true;
	else
		return false;
}

// print out the queue
void print(Queue *queue){
	printf("%s", "The queue is:");
	Node *ptr = queue->head;
	while (ptr != NULL) {
		printf("Node id: %d distance: %d  predecessor: %d \n", (ptr->value).id, (ptr->value).distance, (ptr->value).predecessor);
		ptr = ptr->next;
	}
}

void deleteAll(Queue **queue) {
	/* complete as an exercise */
}

int main(void) {

    Queue *queue = createQueue();
	Data data1 = {10, 100, 20};
	enqueue(queue, data1);

	Data data2 = {20, 200, 40};
	enqueue(queue, data2);

	Data data3 = {30, 300, 60};
	enqueue(queue, data3);

	print(queue);
	dequeue(queue);
	printf("%s \n", "Queue after dequeue:");
	print(queue);

	dequeue(queue);
	printf("%s \n", "Queue after dequeue:");
	print(queue);

	printf("%s", "Is queue empty? ");
	printf("%d\n", isEmpty(queue));

	dequeue(queue);
	printf("%s", "Dequeue again, now is queue empty? ");
	printf("%d\n", isEmpty(queue));

	// deleteAll(&queue); // complete as an exercise
	return EXIT_SUCCESS;
}

