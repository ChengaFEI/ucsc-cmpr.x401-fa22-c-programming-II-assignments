//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 2
//
// huffmantree.h
// huffman-encoder
// 
// Object: HuffmanTree, HuffmanNode.
// 

#include <stdlib.h>
#include <stdio.h>

#include "nodelist.h"

#define MAX_HUFFMANCODE_SIZE 100
/*-----------------------------------------------------------------------------*/

// HuffmanTree object with the root HuffmanNode and the total size.
typedef struct HuffmanTree_t {
  Node *root;
  int size;
} HuffmanTree;

// HuffmanCode object with the code string.
typedef struct {
  char code[MAX_HUFFMANCODE_SIZE];
} HuffmanCode;
/*-----------------------------------------------------------------------------*/

// Major functions:
// Functions in this group perform the major functionality of the HuffmanTree object.
void constructHuffmanTree(HuffmanTree *hTree, NodeList *nodeList);
void printHuffmanCode(HuffmanTree *hTree, char item);
/*-----------------------------------------------------------------------------*/

// Minor functions:
// Functions in this group perform auxiliary functionality of the NodeList/Node object.

// Log the data messages.
void printTreeList(HuffmanTree *hTree);
// Manage the memory.
void freeHuffmanTree(HuffmanTree *hTree);
/*-----------------------------------------------------------------------------*/

// Helper functions:
// Functions in this group helps with the major/minor functions' implementation.

// Helpers for printHuffmanCode().
void concatHuffmanCode(Node *node, char item, HuffmanCode hCode);
// Helpers for printTreeList().
void printTreeNodes(Node *node);
// Helpers for freeHuffmanTree().
void freeTreeNodes(Node *node);
/*-----------------------------------------------------------------------------*/
