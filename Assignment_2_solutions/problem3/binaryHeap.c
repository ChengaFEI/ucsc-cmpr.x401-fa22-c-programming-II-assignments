/*
 * binaryHeap.c
 * A circular queue created with a linked list
 *
 * Adapted from Data Structures and Algorithm Analysis in C by M. A. Weiss
 */
#include "binaryHeap.h"
#define MAX_SIZE 10000000

BinaryHeap* createBinaryHeap(size_t max_size) {

	if (max_size > MAX_SIZE) {
		fprintf(stderr,"Error: maximum size exceeded");
		exit(EXIT_FAILURE);
	}
	BinaryHeap *heap = (BinaryHeap *) calloc(sizeof(BinaryHeap), 1);
	if (heap == NULL) {
			fprintf(stderr,"Error: memory could be allocated to create binary heap");
			exit(EXIT_FAILURE);
	}
	heap->capacity = max_size;
	heap->arr = (Node **) calloc(sizeof(Node *), heap->capacity);

	if (heap->arr == NULL) {
		fprintf(stderr,"Error: memory could be allocated to create binary heap");
		exit(EXIT_FAILURE);
	}
	heap->size = 0;
	heap->arr[0] = (Node *) calloc(sizeof(Node), 1);
	if (heap->arr[0] == NULL) {
		fprintf(stderr, "Error: memory could be allocated to create binary heap");
		exit(EXIT_FAILURE);
	}
	heap->arr[0]->distance = INT_MAX; // store a sentinel at index 0
	return heap;
}

bool isFull(BinaryHeap *heap) {
	if (heap->size == heap->capacity - 1)
		return true;
	else
		return false;
}

bool isEmpty(BinaryHeap *heap) {
	if (heap->size == 0)
		return true;
	else
		return false;
}

// insert the node into the heap maintaining the min heap property
void insert(BinaryHeap *heap, int _distance, int _value) {
	int i;
	Node *newNode = (Node *) malloc(sizeof(Node));
	*newNode = (Node) {.distance = _distance, .value = _value};

	int item = newNode->distance;
	if (isFull(heap)) {
		fprintf(stderr, "Error: priority queue is full");
	}
	else {
		i = ++heap->size;
		// parent has index i/2, percolate up to insert new item
		while (heap->arr[i / 2]->distance < item) {
			heap->arr[i] = heap->arr[i / 2];
			i = i / 2;
		}
		heap->arr[i] = newNode;
	}
}

// delete the item at the top of the heap and return it
Node* deleteMax(BinaryHeap *heap) {
	int i, child;
	if (isEmpty(heap)) {
		fprintf(stderr, "Error: Binary heap is empty");
		return heap->arr[0]; // return the sentinel
	}
	Node *maxNode = heap->arr[1];
	Node *lastNode = heap->arr[heap->size];
	heap->size--; // decrease the size

	// percolate down
	for (i = 1; i * 2 <= heap->size; i = child) {
		// find smaller child
		child = i * 2;
		if (child != heap->size && heap->arr[child + 1]->distance > heap->arr[child]->distance)
			child++; // this is the larger child
		if (lastNode->distance < heap->arr[child]->distance) {
			heap->arr[i] = heap->arr[child];
		}
		else // found a position where last_item can be inserted
			break;
	}
	heap->arr[i] = lastNode;
	return maxNode; //smallest element in array
}

int getSize(BinaryHeap *heap) {
	return heap->size;
}

void print(BinaryHeap *heap) {
	printf("%s \n", "The heap is: ");
	for (int i = 1; i < (heap->size + 1); i++)
		printf( "[ value:  %d  distance:  %d  ]", heap->arr[i]->value, heap->arr[i]->distance);
}

Node * findMax(BinaryHeap *heap) {
	return heap->arr[1];
}

Node * getItem(BinaryHeap *heap, int x) {
	return heap->arr[x];
}

void deleteBinaryHeap(BinaryHeap **heap) {
	for (int i = 0; i <= (*heap)->size; i++) { // remember to delete the sentinel
		if ((*heap)->arr[i]) {
			free( (*heap)->arr[i]);
			(*heap)->arr[i] = NULL;
		}
	}
	if ((*heap)->arr) {
		free((*heap)->arr);
		(*heap)->arr = NULL;
	}

}


int main() {
	// create a binary heap binHeap
	BinaryHeap *binHeap = createBinaryHeap(100);
	insert(binHeap, 5, 1);
	insert(binHeap, 3, 2);
	insert(binHeap, 43, 3);
	insert(binHeap, 4, 4);
	insert(binHeap, 14, 5);
	insert(binHeap, 24, 6);
	insert(binHeap, 34, 7);
	insert(binHeap, 1, 8);

	printf("%s \n", "binHeap:");
	print(binHeap);

	// delete the maximum key
	Node *minKey = deleteMax(binHeap);
	printf("\n Delete minimum item with distance: %d   value:  %d\n", minKey->distance,  minKey->value);
	print(binHeap);
	free(minKey);
	minKey = NULL;



	deleteBinaryHeap(&binHeap);

	return(EXIT_SUCCESS);
}
