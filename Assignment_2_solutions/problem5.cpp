// Author: SPEL Technologies, Inc.
// MIT License

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

struct Node {
	int frequency; // node distance
	char id;
	Node *left;
	Node *right;

	Node() {
		right = NULL;
		left = NULL;
		id = 'a';
		frequency = 0;
	}

	Node(int freq, char val) {
		frequency = freq;
		id = val;
		right = NULL;
		left = NULL;
	}

};

typedef struct BinaryHeap_t {
	struct Node **arr;  // stores the elements of array
	int size;   // size of array
	int capacity;   // capacity of heap


	BinaryHeap_t(int max_size) {
		capacity = max_size;
		arr = new Node * [capacity];

		size = 0;
		arr[0] = new Node;
		arr[0]->frequency = INT_MIN; // store a sentinel at index 0
	}
} BinaryHeap;


typedef struct Seq_t {
	char arr[MAX_SIZE];
} Seq;

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
void addNode(BinaryHeap *heap, Node * newNode) {
	int i;
	int item = newNode->frequency;

	if (isFull(heap))
		printf("Error: priority queue is full");
	else {
		i = ++heap->size;

		// parent  has index i/2, percolate up to insert new item
		while (heap->arr[i / 2]->frequency > item) {
			heap->arr[i] = heap->arr[i / 2];
			i = i / 2;
		}
		heap->arr[i] = newNode;

	}
}

// delete the item at the top of the heap and return it
Node * deleteMin(BinaryHeap *heap) {
	int i, child;


	if (isEmpty(heap)) {
		printf("Error: Binary heap is empty");
		return heap->arr[0]; // return the sentinel
	}

	Node *minNode = heap->arr[1];
	Node *lastNode = heap->arr[heap->size];

	heap->size--;           // decrease the size

	// percolate down
	for (i = 1; i * 2 <= heap->size; i = child) {
		// find smaller child
		child = i * 2;

		if (child != heap->size && heap->arr[child + 1]->frequency < heap->arr[child]->frequency)
			child++; // this is the smaller child

		if (lastNode->frequency > heap->arr[child]->frequency) {
			heap->arr[i] = heap->arr[child];
		}
		else            // found a position where last_item can be inserted
			break;
	}

	heap->arr[i] = lastNode;
	//cout << "Returning minimum node " << minNode->value << " " << minNode->distance << endl;
	return minNode;    //smallest element in array
}


int getSize(BinaryHeap *heap) {
	return heap->size;
}

void print(BinaryHeap *heap) {
	for (int i = 1; i < heap->size + 1; i++)
		printf("[ id: %d,  distance: %d   ] ", heap->arr[i]->id, heap->arr[i]->frequency);
	printf("\n");
}

Node * findMin(BinaryHeap *heap) {
	return heap->arr[1];
}

Node * getItem(BinaryHeap *heap, int x) {
	return heap->arr[x];
}


// decrease key lowers the key of key at given position x by amount delta
void decreaseKey(BinaryHeap *heap, int x, int delta) {
	// check that position is not outside the heap size
	if (x > heap->size) {
		printf("Error: invalid index into  heap");
		return;
	}

	heap->arr[x]->frequency -= delta; // decrement key at position x by delta
	Node *tmp = heap->arr[x];

	// percolate up
	while (heap->arr[x / 2]->frequency > tmp->frequency) {
		heap->arr[x] = heap->arr[x / 2];
		x = x / 2;
	}
	heap->arr[x] = tmp;
}


void inorder(BinaryHeap *heap, Node *root, Seq seq) {
	if (root != NULL) {
		printf("id: %c  huffman code: %s \n", root->id, seq.arr);
		Seq seq0, seq1;
		strcpy(seq0.arr, seq.arr);
		strcat(seq0.arr, "0");
		strcpy(seq1.arr, seq.arr);
		strcat(seq1.arr, "1");
		inorder(heap, root->left, seq0);
		//printf("frequency %d , id %c \n", root->frequency, root->id);
		inorder(heap, root->right, seq1);

	}
}

// create the huffman tree
Node  * huffmanEncoding(BinaryHeap *heap) {
	Node *n1, *n2, *newNode;

	while (getSize(heap) > 1) {
		n1 = deleteMin(heap);
		n2 = deleteMin(heap);

		int newFreq = n1->frequency + n2->frequency;

		newNode = new Node(newFreq, '*');
		newNode->left = n1;
		newNode->right = n2;

		addNode(heap, newNode);
		printf("The new heap is:\n");
		print(heap);
	}
	return newNode;
}



int main() {
	BinaryHeap *heap = new BinaryHeap(10);

	Node *n1 = new Node(3, 'A');
	Node *n2 = new Node(17, 'B');
	Node *n3 = new Node(13, 'C');

	addNode(heap, n1);
	addNode(heap, n2);
	addNode(heap, n3);

	Node *root = huffmanEncoding(heap);

	printf("The Huffman tree is:\n");
	//printf("root key %d\n", root->frequency);
	Seq seq;
	strcpy(seq.arr, "");
	strcat(seq.arr, "\n");
	inorder(heap, root, seq);

	Node *n4 = new Node(1, 'a');
	Node *n5 = new Node(2, 'b');
	Node *n6 = new Node(5, 'c');
	Node *n7 = new Node(3, 'd');

	BinaryHeap *heap1 = new BinaryHeap(10);
	addNode(heap1, n4);
	addNode(heap1, n5);
	addNode(heap1, n6);
	addNode(heap1, n7);

	root = huffmanEncoding(heap1);

	printf("The Huffman tree is:\n");
	//printf("root key %d\n", root->frequency);
	strcpy(seq.arr, "");
	strcat(seq.arr, "\n");
	inorder(heap1, root, seq);

	return 0;
}

