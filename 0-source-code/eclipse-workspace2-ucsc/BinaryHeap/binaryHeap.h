
#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node_t {
	int distance; // node distance
	int value;
} Node;

typedef struct BinaryHeap_t {
	Node **arr; // stores the elements of array
	size_t size; // size of array
	size_t capacity; // capacity of heap
} BinaryHeap;

BinaryHeap* createBinaryHeap(size_t max_size) ;
bool isFull(BinaryHeap *heap);
bool isEmpty(BinaryHeap *heap);
Node* deleteMin(BinaryHeap *heap);
void insert(BinaryHeap *heap, int _distance, int _value);
int getSize(BinaryHeap *heap);
void print(BinaryHeap *heap);
Node* findMin(BinaryHeap *heap);
Node* getItem(BinaryHeap *heap, int x);
void deleteBinaryHeap(BinaryHeap **heap);
void decreaseKey(BinaryHeap *heap, int x, int delta);
void heapUnion(BinaryHeap *heap, BinaryHeap *heap2);
void findLessThan(BinaryHeap *heap, int x, int index);
void deleteBinaryHeap(BinaryHeap **heap);


#endif /* BINARYHEAP_H_ */
