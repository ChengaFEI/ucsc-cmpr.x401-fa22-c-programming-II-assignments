//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Part 2
// Problem 2
//
// nodelist.c
// huffman-encoder
// 
// Object: NodeList, Node.
// 

#include "nodelist.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions start here.
/*-----------------------------------------------------------------------------*/

// addNode() adds a new Node object in the nodeList.
// @Param:   nodeList -- pointer to the NodeList object to receive a new Node.
// @Param:   freq     -- the frequency property of the new Node.
// @Param:   item     -- the item property of the new Node.
// @Return:  nodeList (update)
// @Require: nodeList is not NULL.
// @Note:    none
void addNode(NodeList *nodeList, int freq, char item) 
{
  if (nodeList == NULL) printf("Error: NodeList must not be NULL!\n");

  // Create a new Node object.
  Node *node = (Node *) malloc(sizeof(Node));
  if (node == NULL) {
    fprintf(stderr, "Error creating a new node.\n");
    exit(EXIT_FAILURE);
  }
  node->freq = freq;
  node->item = item;

  // Add the new node to the nodeList.
  node->next = nodeList->head;
  nodeList->head = node;

  // Increment the size.
  nodeList->size++;
}
/*-----------------------------------------------------------------------------*/

// sortNodeList() sorts the node list in ascending order.
// @Params:   nodeList -- pointer to the NodeList to sort.
// @Return:   nodeList (update)
// @Require:  nodeList must not be NULL.
// @Note:     none
void sortNodeList(NodeList *nodeList)
{
  if (nodeList == NULL || nodeList->head == NULL) return;
  // Quick sort the node list.
  Node *firstNode = nodeList->head;
  Node *lastNode = findLastNode(nodeList);
  quickSortNodes(firstNode, lastNode);
}
/*-----------------------------------------------------------------------------*/

// mergeFirstTwoNodes() merges the first two nodes in the node list, sums up their frequency, updates mergedNode with the new frequency and '*' item, and links the first two nodes with mergedNode as its child Nodes.
// @Param:   nodeList   -- pointer to the node list with all nodes.
// @Param:   mergedNode -- pointer to the node created by merging properties of the first two nodes in the node list.
// @Return:  mergedNode (update)
// @Require: nodeList must have at least two nodes.
//           mergedNode must occupy a memory.
// @Note:    none
void mergeFirstTwoNodes(NodeList *nodeList, Node *mergedNode)
{
  // Basic variables;
  int freqOne, freqTwo; // Frequency property of first two nodes.

  // nodeList must have at least two nodes.
  if (nodeList->size <= 1) return;
  // mergedNode must occupy a memory.
  if (mergedNode == NULL) return;
  // Retrieve properties from the first two nodes and assign the merged property to mergedNode.
  freqOne = nodeList->head->freq;
  freqTwo = nodeList->head->next->freq;
  mergedNode->freq = freqOne + freqTwo;
  mergedNode->item = '*'; // Default item character for mergedNode.
  // Link first two nodes with mergedNode as child nodes.
  mergedNode->left = nodeList->head;
  mergedNode->right = nodeList->head->next;
}
/*-----------------------------------------------------------------------------*/

// replaceFirstTwoNodes() replaces first two nodes in the node list with mergedNode, and adjusts the size of the node list.
// @Param:   nodeList   -- pointer to the node list with all nodes.
// @Param:   mergedNode -- pointer to the newly created Node.
// @Return:  nodeList (update)
// @Require: nodeList must have at least two nodes initially.
// @Note:    none
void replaceFirstTwoNodes(NodeList *nodeList, Node *mergedNode)
{
  // nodeList must have at least two nodes initially.
  if (nodeList == NULL || nodeList->size <= 1) return;
  // Remove first two nodes.
  Node *firstNode = nodeList->head;
  nodeList->head = nodeList->head->next->next;
  firstNode->next->next = NULL;
  firstNode->next = NULL;
  // Add mergedNode.
  mergedNode->next = nodeList->head;
  nodeList->head = mergedNode;
  // Adjust the size of the node list.
  nodeList->size--;
}
/*-----------------------------------------------------------------------------*/

// printNodeList() displays all the nodes' data on the console.
// @Param:   nodeList -- pointer to the NodeList object to be displayed.
// @Return:  none
// @Require: nodeList is not NULL
// @Note:    none
void printNodeList(NodeList *nodeList)
{
  if (nodeList == NULL) return;
  printf("Items\tFrequency\n");
  Node *currNode = nodeList->head;
  while (currNode != NULL) {
    printf("%c\t%d\n", currNode->item, currNode->freq);
    currNode = currNode->next;
  }
}
/*-----------------------------------------------------------------------------*/

// freeNodeList() releases the dynamically allocated memories of all the Node objects in the nodeList and the nodeList itself.
// @Param:   nodeList -- pointer to the NodeList object to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeNodeList(NodeList *nodeList)
{
  if (nodeList == NULL) return;
  // Free all the Node objects in the nodeList.
  freeListNodes(nodeList->head);
  // Free the nodeList itself.
  free(nodeList);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions start here.
/*-----------------------------------------------------------------------------*/

// findLastNode() finds the last Node object in the node list.
// @Param:   nodeList -- pointer to the NodeList to search.
// @Return:  pointer to the last Node in the node list.
// @Require: nodeList must not be NULL.
// @Note:    If the node list has no Node, return NULL.
Node *findLastNode(NodeList *nodeList)
{
  if (nodeList == NULL) return NULL;
  Node *currNode = nodeList->head;
  while (currNode != NULL && currNode->next != NULL) currNode = currNode->next;
  return currNode;
}
/*-----------------------------------------------------------------------------*/

// quickSortNodes() sorts the node list between the firstNode and the lastNode in ascending order using the quick sort algorithm.
// @Param:   firstNode -- pointer to the first Node.
// @Param:   lastNode  -- pointer to the last Node.
// @Return:  none
// @Require: none
// @Note:    none
void quickSortNodes(Node *firstNode, Node *lastNode)
{
  // Don't need to sort a single Node.
  if (firstNode == lastNode) return;
  // Find the partition Node.
  Node *parNode = partition(firstNode, lastNode);
  // Quick sort each half of the list.
  if (parNode != NULL && parNode->next != NULL) {
    quickSortNodes(parNode->next, lastNode);
  }
  if (parNode != NULL && parNode != firstNode) {
    quickSortNodes(firstNode, parNode);
  }
}
/*-----------------------------------------------------------------------------*/

// partition() partitions the node list between the firstNode and the lastNode, returns the pointer to the partition Node, and ensures all Nodes preceding the partition Node has smaller frequency property, all Nodes after the partition Node has larger frequency property.
// @Param:   firstNode -- pointer to the first Node in the list.
// @Param:   lastNode  -- pointer to the last Node in the list.
// @Return:  pointer to the partition node.
// @Require: none
// @Note:    If the firstNode is after or equal to the lastNode, return NULL.
Node *partition(Node *firstNode, Node *lastNode)
{
  // Basic variables.
  Node *parNode = firstNode;  // The partition Node.
  Node *iterNode = firstNode; // The Node iterator.

  // Take the lastNode's frequency property as comparison.
  while (iterNode != NULL && iterNode != lastNode) {
    // Swap Node with smaller frequency property than the lastNode to the front of the list.
    if (iterNode->freq < lastNode->freq) {
      parNode = firstNode;
      swapData(firstNode, iterNode);
      firstNode = firstNode->next;
    }
    // Move the Node iterator forward.
    iterNode = iterNode->next;
  }
  // Swap data of the lastNode with the data of the partition Node.
  swapData(lastNode, firstNode);

  return parNode; 
}
/*-----------------------------------------------------------------------------*/

// swapData() swaps the data of nodeOne and nodeTwo, all except the next pointer.
// @Param:   nodeOne -- pointer to one of the Node.
// @Param:   nodeTwo -- pointer to the other Node.
// @Return:  nodeOne, nodeTwo (update)
// @Require: both nodeOne and nodeTwo must not be NULL.
// @Note:    none
void swapData(Node *nodeOne, Node *nodeTwo)
{
  if (nodeOne == NULL || nodeTwo == NULL) return;
  // Swap the frequency property.
  int frequency = nodeOne->freq;
  nodeOne->freq = nodeTwo->freq;
  nodeTwo->freq = frequency;
  // Swap the item property.
  char item = nodeOne->item;
  nodeOne->item = nodeTwo->item;
  nodeTwo->item = item;
  // Swap the child Nodes (left/right pointer).
  Node *left = nodeOne->left;
  nodeOne->left = nodeTwo->left;
  nodeTwo->left = left;
  Node *right = nodeOne->right;
  nodeOne->right = nodeTwo->right;
  nodeTwo->right = right;
}
/*-----------------------------------------------------------------------------*/

// freeListNodes() releases the dynamically allocated memories of the node itself and nodes linked after it.
// @Param:   node -- pointer to the node to be freed.
// @Return:  none
// @Require: none
// @Note:    none
void freeListNodes(Node *node)
{
  if (node == NULL) return;
  if (node->next != NULL) freeListNodes(node->next);
  free(node);
}
/*-----------------------------------------------------------------------------*/
