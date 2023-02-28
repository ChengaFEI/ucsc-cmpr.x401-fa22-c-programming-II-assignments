//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Problem 3
//
// binary-max-heap.c
// binary-max-heap
// 
// Function: A binary max heap and its functions' implementation.
//

#include "binary-max-heap.h"

#define MAX_SIZE 10000000
/*-----------------------------------------------------------------------------*/

int main() 
{
  printf("\n");

	// Create a binary heap binHeap and insert nodes.
	BinaryHeap *binHeap = createBinaryHeap(100);
	insert(binHeap, 5, 1);
	insert(binHeap, 3, 2);
	insert(binHeap, 43, 3);
	insert(binHeap, 4, 4);
	insert(binHeap, 14, 5);
	insert(binHeap, 24, 6);
	insert(binHeap, 34, 7);
	insert(binHeap, 1, 8);
	printf("(binHeap) ");
	print(binHeap);
  printf("\n");

	// Delete the maximum key.
	Node *maxKey = deleteMax(binHeap);
	printf("Deleting maximum item with distance: %d, value: %d ...\n", maxKey->distance, maxKey->value);
  printf("------------------------------------------------------\n");
  printf("(binheap) ");
	print(binHeap);
	free(maxKey);
	maxKey = NULL;
  printf("\n");

	// Increase key operations.
	printf("%s ", "(binHeap) Increased key at index 2 by 10 ");
	increaseKey(binHeap, 2, 10);
	print(binHeap);
  printf("\n");
	printf("%s ", "(binHeap) Increased key at index 6 by 43 ");
	increaseKey(binHeap, 6, 43);
	print(binHeap);
	printf("\n");
  printf("%s ", "(binHeap) Increased key at index 7 by 100 ");
	increaseKey(binHeap, 7, 100);
	print(binHeap);
  printf("\n");

	// Find elements less than a given value with root at given index
	printf("%s", "(binHeap) Elements less than 20:\n");
	findLessThan(binHeap, 20, 1);
  printf("\n");

	// Create a second binary heap binHeap1 and insert nodes.
	printf("%s", "(binHeap1) ");
	BinaryHeap *binHeap1 = createBinaryHeap(10);
	insert(binHeap1, 5, 9);
	insert(binHeap1, 3, 10);
	insert(binHeap1, 43, 11);
	insert(binHeap1, 4, 12);
	print(binHeap1);
  printf("\n");

  // Merge heap with heap1.
	printf("%s", "After union ");
	heapUnion(binHeap, binHeap1);
	print(binHeap);
  printf("\n");

  // Release dynamic memories occupied.
	deleteBinaryHeap(&binHeap);
	deleteBinaryHeap(&binHeap1);

	return(EXIT_SUCCESS);
}
/*-----------------------------------------------------------------------------*/

// createBinaryHeap() creates a binary heap with max_size number of nodes.
// @Param:   max_size -- the number of nodes of the heap.
// @Return:  pointer to the newly created heap.
// @Require: max_size can't exceeds the MAX_SIZE constraint.
// @Note:    the actual number of nodes the heap can store is max_size-1 because the first node is assigned as the sentinel node.
BinaryHeap *createBinaryHeap(size_t max_size)
{
  // The size of heap can't exceeds the limit.
	if (max_size > MAX_SIZE) {
		fprintf(stderr,"Error: maximum size exceeded");
		exit(EXIT_FAILURE);
	}
  // Allocate memory for the heap.
	BinaryHeap *heap = (BinaryHeap *) calloc(sizeof(BinaryHeap), 1);
	if (heap == NULL) {
			fprintf(stderr,"Error: memory could be allocated to create binary heap");
			exit(EXIT_FAILURE);
	}
  // Initialize heap's properties.
	heap->capacity = max_size;
  heap->size = 0;
  // Allocate memory for the nodes array.
	heap->arr = (Node **) calloc(sizeof(Node *), heap->capacity);
	if (heap->arr == NULL) {
		fprintf(stderr,"Error: memory could be allocated to create binary heap");
		exit(EXIT_FAILURE);
	}
  // Initialize the first node in the array as a sentinel node.
	heap->arr[0] = (Node *) calloc(sizeof(Node), 1);
	if (heap->arr[0] == NULL) {
		fprintf(stderr, "Error: memory could be allocated to create binary heap");
		exit(EXIT_FAILURE);
	}
	heap->arr[0]->distance = INT_MAX; // store a sentinel at index 0

	return heap;
}
/*-----------------------------------------------------------------------------*/

// isFull() checks whether the heap is full.
// @Param:   heap -- pointer to the heap to be checked.
// @Return:  true/false
// @Require: heap is not NULL.
// @Note:    none
bool isFull(BinaryHeap *heap) 
{
	if (heap->size == heap->capacity - 1) return true;
	else return false;
}
/*-----------------------------------------------------------------------------*/

// isEmpty() checks whether the heap is empty.
// @Param:   heap -- pointer to the heap to be checked.
// @Return:  true/false
// @Require: heap is not NULL.
// @Note:    none
bool isEmpty(BinaryHeap *heap) 
{
	if (heap->size == 0) return true;
	else return false;
}
/*-----------------------------------------------------------------------------*/

// insert() inserts the node into the heap maintaining the max heap property.
// @Param:   heap      -- pointer to the heap to accept the node.
// @Param:   _distance -- the distance property of the new node.
// @Param:   _value    -- the value property of the new node.
// @Return:  heap (update)
// @Require: heap is not NULL.
// @Note:    none
void insert(BinaryHeap *heap, int _distance, int _value) 
{
  // Basic variables.
	int i;    // Iterator of nodes in the heap.
  int item; // The distance property of the new node.

  // Create a new node.
	Node *newNode = (Node *) malloc(sizeof(Node));
  if (newNode == NULL) {
    fprintf(stderr,"Error: memory could be allocated to insert a new node");
		exit(EXIT_FAILURE);
  }
	*newNode = (Node) {.distance = _distance, .value = _value};

  // Insert the new node.
	item = newNode->distance;
	if (isFull(heap)) fprintf(stderr, "Error: priority queue is full");
	else {
		i = ++heap->size;
		// The parent has an index of i/2, percolate up to insert new item.
		while (heap->arr[i / 2]->distance < item) {
			heap->arr[i] = heap->arr[i / 2];
			i = i / 2;
		}
		heap->arr[i] = newNode;
	}
}
/*-----------------------------------------------------------------------------*/

// deleteMax() deletes the item at the top of the heap and returns it.
// @Param:   heap -- pointer to the heap to be modified.
// @Return:  heap (update)
// @Require: heap is not NULL.
// @Note:    none
Node *deleteMax(BinaryHeap *heap) 
{
  // Basic variables.
	int i;          // Iterator of nodes in the heap.
  int child;      // Index of the child node.
  Node *maxNode;  // The maximum node in the heap.
  Node *lastNode; // The last node in the heap.

  // If the heap is empty, return the sentinel.
	if (isEmpty(heap)) {
		fprintf(stderr, "Error: Binary heap is empty");
		return heap->arr[0];
	}

  // Remove the first/largest node in the heap.
	maxNode = heap->arr[1];
	lastNode = heap->arr[heap->size];
	heap->size--;

	// Percolate down to fill the heap.
	for (i = 1; i * 2 <= heap->size; i = child) {
		child = i * 2;
    // Choose the larger child of the same parent.
		if (child != heap->size && heap->arr[child + 1]->distance > heap->arr[child]->distance)
			child++;
    // Compare the child's distance property with the last node's.
		if (lastNode->distance < heap->arr[child]->distance) {
			heap->arr[i] = heap->arr[child];
		}
    // If the child's distance property is smaller, we find the position for the last node.
		else break;
	}
	heap->arr[i] = lastNode;

  // Return the largest node in the array.
	return maxNode;
}
/*-----------------------------------------------------------------------------*/

// getSize() returns the size of the heap.
// @Param:   heap -- pointer to the heap.
// @Return:  the size of the heap.
// @Require: heap is not NULL.
// @Note:    none
int getSize(BinaryHeap *heap) 
{
	return heap->size;
}
/*-----------------------------------------------------------------------------*/

// print() displays the value and the distance property of all nodes in the heap.
// @Param:   heap -- pointer to the heap to be displayed.
// @Return:  none
// @Require: heap is not NULL.
// @Note:    none
void print(BinaryHeap *heap) 
{
	printf("The heap is: \n");
	for (int i = 1; i < (heap->size + 1); i++)
		printf( "[ value: %d, distance: %d ]\n", heap->arr[i]->value, heap->arr[i]->distance);
}
/*-----------------------------------------------------------------------------*/

// findMax() finds the maximum node in the heap.
// @Param:   heap -- pointer to the heap to be searched.
// @Return:  the maximum node in the heap.
// @Require: heap is not NULL.
// @Note:    none
Node *findMax(BinaryHeap *heap) 
{
	return heap->arr[1];
}
/*-----------------------------------------------------------------------------*/

// getItem() finds the node of the given index in the heap.
// @Param:   heap -- pointer to the heap to be searched.
// @Param:   x    -- the index of the node.
// @Return:  the node of the given index in the heap.
// @Require: heap is not NULL.
// @Note:    none
Node *getItem(BinaryHeap *heap, int x) 
{
	return heap->arr[x];
}
/*-----------------------------------------------------------------------------*/

// increaseKey() increases the distance property (key) at given position x by amount delta and maintains the max heap features.
// @Param:   heap  -- pointer to the heap to be modified.
// @Param:   x     -- the index of the node to be incremented.
// @Param:   delta -- the amount to increment the distance property.
// @Return:  heap (update)
// @Require: heap is not NULL.
// @Note:    none
void increaseKey(BinaryHeap *heap, int x, int delta) 
{
  // Basic variables.
  Node *tmp;

	// Check that the position is not outside the heap size.
	if (x > heap->size) {
		fprintf(stderr, "Error: invalid index into heap");
		exit(EXIT_FAILURE);
	}

  // Increment key at position x by delta.
	heap->arr[x]->distance += delta; 
	// Percolate up to fill the heap.
  tmp = heap->arr[x];
	while (heap->arr[x / 2]->distance < tmp->distance) {
		heap->arr[x] = heap->arr[x / 2];
		x = x / 2;
	}
	heap->arr[x] = tmp;
}
/*-----------------------------------------------------------------------------*/

// heapUnion() merges two heaps.
// @Param:   heap  -- pointer to the destination heap.
// @Param:   heap2 -- pointer to the source heap.
// @Return:  heap (update)
// @Require: heap and heap2 are not NULL.
// @Note:    none
void heapUnion(BinaryHeap *heap, BinaryHeap *heap2) 
{
	size_t size = getSize(heap2);
	for (int i = 1; i <= size; i++) {
		int distance = getItem(heap2, i)->distance;
		int value = getItem(heap2, i)->value;
		insert(heap, distance, value);
	}
}
/*-----------------------------------------------------------------------------*/

// findLessThan() finds all nodes less than a value x in the tree rooted at the given index and displays their data on the console.
// @Param:   heap  -- pointer to the heap to search.
// @Param:   x     -- the cap value.
// @Param:   index -- the index of the subtree's root. (search the nodes after this index)
// @Return:  none
// @Require: heap is not NULL.
// @Note:    none
void findLessThan(BinaryHeap *heap, int x, int index) 
{
  // The index can't exceeds the heap's size limit.
	if (index > heap->size) return;

	if (heap->arr[index]->distance < x)
		printf("[ value: %d, distance: %d ]\n", heap->arr[index]->value, heap->arr[index]->distance);
	findLessThan(heap, x, 2 * index);
	findLessThan(heap, x, 2 * index + 1);
}
/*-----------------------------------------------------------------------------*/

// deleteBinaryHeap() releases dynamic memories allocated for the heap, excluding the heap itself.
// @Param:   heap -- pointer to the heap's address.
// @Return:  none
// @Require: none
// @Note:    none
void deleteBinaryHeap(BinaryHeap **heap) 
{
  // Release memories allocated for nodes.
	for (int i = 0; i <= (*heap)->size; i++) {
		if ((*heap)->arr[i]) {
			free( (*heap)->arr[i]);
			(*heap)->arr[i] = NULL;
		}
	}
  // Release the memory allocated for the array.
	if ((*heap)->arr) {
		free((*heap)->arr);
		(*heap)->arr = NULL;
	}
}
/*-----------------------------------------------------------------------------*/
