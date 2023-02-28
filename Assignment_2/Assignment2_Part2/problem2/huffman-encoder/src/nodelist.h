//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 2
//
// nodelist.h
// huffman-encoder
// 
// Object: NodeList, Node.
// 

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

// Node object with the item character and the frequency.
typedef struct Node_t {
  int freq;
  char item;
  struct Node_t *next;  // Link to the next Node in the NodeList.
  struct Node_t *left;  // Link to the left child Node in the HuffmanTree.
  struct Node_t *right; // Link to the right child Node in the HuffmanTree.
} Node;

// NodeList object with the head Node and the size count.
typedef struct NodeList_t {
  Node *head;
  int size;
} NodeList;
/*-----------------------------------------------------------------------------*/

// Major functions:
// Functions in this group perform the major functionality of the NodeList/Node object.
void addNode(NodeList *nodeList, int freq, char item);
void sortNodeList(NodeList *nodeList);
void mergeFirstTwoNodes(NodeList *nodeList, Node *mergedNode);
void replaceFirstTwoNodes(NodeList *nodeList, Node *mergedNode);
/*-----------------------------------------------------------------------------*/

// Minor functions:
// Functions in this group perform auxiliary functionality of the NodeList/Node object.

// Log the data messages.
void printNodeList(NodeList *nodeList);
// Manage the memory.
void freeNodeList(NodeList *nodeList);
/*-----------------------------------------------------------------------------*/

// Helper functions:
// Functions in this group helps with the major/minor functions' implementation.

// Helpers for sortNodeList().
Node *findLastNode(NodeList *nodeList);
void quickSortNodes(Node *firstNode, Node *lastNode);
Node *partition(Node *firstNode, Node *lastNode);
void swapData(Node *nodeOne, Node *nodeTwo);
// Helpers for freeNodeList().
void freeListNodes(Node *node);
/*-----------------------------------------------------------------------------*/
