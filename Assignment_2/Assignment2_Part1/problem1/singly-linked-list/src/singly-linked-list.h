// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Problem 1
//
// singly-linked-list.h
// singly-linked-list
// 
// Function: A singly linked list structure and its functions' prototypes.

struct Data {
	int key;
};
struct Node {
	struct Data data;
	struct Node *next;
};
/*-----------------------------------------------------------------------------*/

struct Node* listSearch(struct Node *head, int key);
void listInsert(struct Node **head, int key);  // insert a new node with given key at front of list
void listDelete(struct Node **head, struct Node *x);  // delete node x
void listPrint(struct Node *head);
void listDeleteAll(struct Node *head);