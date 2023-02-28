//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 2
//
// huffmantree.c
// huffman-encoder
// 
// Object: HuffmanTree, HuffmanNode.
// 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "huffmantree.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// constructHuffmanTree() constructs a HuffmanTree using Nodes in the nodeList.
// @Param:   hTree    -- pointer to the HuffmanTree to construct.
// @Param:   nodeList -- pointer to the linked list of nodes.
// @Return:  hTree (update)
// @Require: hTree must not contain nodes.
//           hTree must have a memory.
// @Notes:   If nodeList is NULL or has no Node objects, don't construct HuffmanTree.
void constructHuffmanTree(HuffmanTree *hTree, NodeList *nodeList)
{
  // nodeList must not be NULL and must contain nodes.
  if (nodeList == NULL || nodeList->head == NULL) return;
  // The memory for HuffmanTree must have been allocated.
  if (hTree == NULL) return;
  // Construct HuffmanTree.
  while (nodeList->size > 1) {
    // Step 1: Sort the list in ascending order.
    sortNodeList(nodeList);
    // Step 2: Merge the first two nodes (with smallest frequency) to a new Node.
    Node *mergedNode = (Node *) malloc(sizeof(Node));
    mergeFirstTwoNodes(nodeList, mergedNode);
    // Step 3: Remove the original two nodes, and add the new Node to the node list.
    replaceFirstTwoNodes(nodeList, mergedNode);
  }
  // Step 4: Assign the root of the HuffmanTree as the only Node in the node list.
  hTree->root = nodeList->head;
  nodeList->head = NULL;
  nodeList->size = 0;
}
/*-----------------------------------------------------------------------------*/

// printHuffmanCode() prints the HuffmanCode of the Node with the given item character.
// @Param:   hTree -- pointer to the HuffmanTree to be displayed.
// @Param:   item  -- the item character to search for.
// @Return:  none
// @Require: hTree must not be NULL.
//           the item character must be included in hTree.
// @Note:    none
void printHuffmanCode(HuffmanTree *hTree, char item)
{
  // hTree must not be NULL.
  if (hTree == NULL || hTree->root == NULL) return;
  HuffmanCode hCode = {""};
  concatHuffmanCode(hTree->root, item, hCode);
}
/*-----------------------------------------------------------------------------*/

// printTreeList() displays all the nodes' data on the console.
// @Param:   hTree -- pointer to the HuffmanTree object to be displayed.
// @Return:  none
// @Require: hTree is not NULL
// @Note:    none
void printTreeList(HuffmanTree *hTree)
{
  if (hTree == NULL) return;
  printTreeNodes(hTree->root);
}
/*-----------------------------------------------------------------------------*/

// freeHuffmanTree() releases all the dynamic memories occupied by the HuffmanTree.
void freeHuffmanTree(HuffmanTree *hTree)
{
  if (hTree == NULL || hTree->root == NULL) return;
  // Free all the Node objects in the HuffmanTree.
  freeListNodes(hTree->root);
  // Free the nodeList itself.
  free(hTree);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/

// concatHuffmanCode() recursively concatenates the HuffmanCode until the given item character is found.
// @Param:   node     -- pointer to the current Node.
// @Param:   item     -- the item character to search for.
// @Param:   currCode -- existing HuffmanCode inherited from preceding nodes.
// @Return:  currCode (update)
// @Require: none 
void concatHuffmanCode(Node *node, char item, HuffmanCode hCode)
{
  if (node == NULL) return;
  if (node->item == item) {
    printf("%c: %s\n", item, hCode.code); 
    return;
  }
  HuffmanCode hCodeLeft, hCodeRight;
  strcpy(hCodeLeft.code, hCode.code);
  strcpy(hCodeRight.code, hCode.code);
  strcat(hCodeLeft.code, "0");
  strcat(hCodeRight.code, "1");
  concatHuffmanCode(node->left, item, hCodeLeft);
  concatHuffmanCode(node->right, item, hCodeRight);
}
/*-----------------------------------------------------------------------------*/

// printTreeNodes() recursively print the data of Nodes in the HuffmanTree.
// @Param:   node -- pointer to the starting node to display.
// @Return:  none
// @Require: none
// @Note:    none
void printTreeNodes(Node *node)
{
  if (node == NULL) return;
  printf("Item: %c, Frequency: %d\n", node->item, node->freq);
  if (node->left != NULL) printTreeNodes(node->left);
  if (node->right != NULL) printTreeNodes(node->right);
}
/*-----------------------------------------------------------------------------*/

// freeTreeNodes() releases the dynamically allocated memories of the node itself and its child nodes.
// @Param:   node -- pointer to the node to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeTreeNodes(Node *node)
{
  if (node == NULL) return;
  if (node->left != NULL) freeTreeNodes(node->left);
  if (node->right != NULL) freeTreeNodes(node->right);
  free(node);
}