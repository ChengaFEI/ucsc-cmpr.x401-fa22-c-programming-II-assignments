//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 2
//
// huffman-encoder.c
// huffman-encoder
// 
// Function: Create a Huffman Encoding for a given list of items.
// 

#include <stdlib.h>
#include <stdio.h>

#include "huffmantree.h"
/*-----------------------------------------------------------------------------*/

// Test case functions:
// Functions in this group runs pre-defined test cases.
void runTest1();
void runTest2();
void runTest3();
void runTest4();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTest1();
  printf("\n");
  runTest2();
  printf("\n"); 
  runTest3();
  printf("\n");
  runTest4();
  printf("\n"); 
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// runTest1() runs the first test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTest1()
{
  printf("Test case 1:\n");
  printf("-----------------------------------------------------------------\n");

  // Generate the nodeList.
  NodeList *list = (NodeList *) malloc(sizeof(NodeList));
  addNode(list, 1, 'a');
  addNode(list, 2, 'b');
  addNode(list, 5, 'c');
  addNode(list, 3, 'd');
  printf("1. Items in the node list:\n");
  printNodeList(list);
  printf("\n");

  // Generate the HuffmanTree.
  HuffmanTree *hTree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
  constructHuffmanTree(hTree, list);
  printf("2. Items in the HuffmanTree:\n");
  printTreeList(hTree);
  printf("\n");
  printf("3. HuffmanCode of each item character:\n");
  printHuffmanCode(hTree, 'a');
  printHuffmanCode(hTree, 'b');
  printHuffmanCode(hTree, 'c');
  printHuffmanCode(hTree, 'd');
  
  // Free the HuffmanTree.
  freeHuffmanTree(hTree);
  // Free the nodeList.
  freeNodeList(list);
  printf("-----------------------------------------------------------------\n");
}
/*-----------------------------------------------------------------------------*/

// runTest2() runs the second test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTest2()
{
  printf("Test case 2:\n");
  printf("-----------------------------------------------------------------\n");

  // Generate the nodeList.
  NodeList *list = (NodeList *) malloc(sizeof(NodeList));
  addNode(list, 5, 'a');
  addNode(list, 9, 'b');
  addNode(list, 12, 'c');
  addNode(list, 13, 'd');
  addNode(list, 16, 'e');
  addNode(list, 45, 'f');
  printf("1. Items in the node list:\n");
  printNodeList(list);
  printf("\n");

  // Generate the HuffmanTree.
  HuffmanTree *hTree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
  constructHuffmanTree(hTree, list);
  printf("2. Items in the HuffmanTree:\n");
  printTreeList(hTree);
  printf("\n");
  printf("3. HuffmanCode of each item character:\n");
  printHuffmanCode(hTree, 'a');
  printHuffmanCode(hTree, 'b');
  printHuffmanCode(hTree, 'c');
  printHuffmanCode(hTree, 'd');
  printHuffmanCode(hTree, 'e');
  printHuffmanCode(hTree, 'f');
  
  // Free the HuffmanTree.
  freeHuffmanTree(hTree);
  // Free the nodeList.
  freeNodeList(list);
  printf("-----------------------------------------------------------------\n");
}
/*-----------------------------------------------------------------------------*/

// runTest3() runs the third test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTest3()
{
  printf("Test case 3:\n");
  printf("-----------------------------------------------------------------\n");

  // Generate the nodeList.
  NodeList *list = (NodeList *) malloc(sizeof(NodeList));
  addNode(list, 50, 'a');
  addNode(list, 9, 'b');
  addNode(list, 10, 'c');
  addNode(list, 10, 'd');
  addNode(list, 6, 'e');
  addNode(list, 5, 'f');
  printf("1. Items in the node list:\n");
  printNodeList(list);
  printf("\n");

  // Generate the HuffmanTree.
  HuffmanTree *hTree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
  constructHuffmanTree(hTree, list);
  printf("2. Items in the HuffmanTree:\n");
  printTreeList(hTree);
  printf("\n");
  printf("3. HuffmanCode of each item character:\n");
  printHuffmanCode(hTree, 'a');
  printHuffmanCode(hTree, 'b');
  printHuffmanCode(hTree, 'c');
  printHuffmanCode(hTree, 'd');
  printHuffmanCode(hTree, 'e');
  printHuffmanCode(hTree, 'f');
  
  // Free the HuffmanTree.
  freeHuffmanTree(hTree);
  // Free the nodeList.
  freeNodeList(list);
  printf("-----------------------------------------------------------------\n");
}
/*-----------------------------------------------------------------------------*/

// runTest4() runs the fourth test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTest4()
{
  printf("Test case 4:\n");
  printf("-----------------------------------------------------------------\n");

  // Generate the nodeList.
  NodeList *list = (NodeList *) malloc(sizeof(NodeList));
  addNode(list, 10, 'a');
  addNode(list, 10, 'b');
  addNode(list, 10, 'c');
  addNode(list, 10, 'd');
  printf("1. Items in the node list:\n");
  printNodeList(list);
  printf("\n");

  // Generate the HuffmanTree.
  HuffmanTree *hTree = (HuffmanTree *) malloc(sizeof(HuffmanTree));
  constructHuffmanTree(hTree, list);
  printf("2. Items in the HuffmanTree:\n");
  printTreeList(hTree);
  printf("\n");
  printf("3. HuffmanCode of each item character:\n");
  printHuffmanCode(hTree, 'a');
  printHuffmanCode(hTree, 'b');
  printHuffmanCode(hTree, 'c');
  printHuffmanCode(hTree, 'd');
  
  // Free the HuffmanTree.
  freeHuffmanTree(hTree);
  // Free the nodeList.
  freeNodeList(list);
  printf("-----------------------------------------------------------------\n");
}
/*-----------------------------------------------------------------------------*/
