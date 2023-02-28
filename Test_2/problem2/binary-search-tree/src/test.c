// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 2
// Problem 2
//
// binary-search-tree
// test.c
// 
// Function: Test the binary-search-tree object.

#include <stdlib.h>
#include <stdio.h>

#include "bstree.h"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provide pre-defined test cases.
void runTestOne();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTestOne();
  printf("\n");
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// @Brief:   Run the first test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestOne()
{
  TreeNode *root = NULL;
  int isRootNode, isLeafNode;
  insert(&root, 'M', 50);
  insert(&root, 'P', 80);
  insert(&root, 'T', 100);
  insert(&root, 'Z', 50);
  insert(&root, 'R', 30);
  insert(&root, 'A', 10);
  insert(&root, 'B', 20);
  insert(&root, 'C', 30);
  insert(&root, 'D', 40);
  insert(&root, 'E', 70);
  inorder(root);
  printf("\n");

  isRootNode = isRoot(root, 'A');
  printf("A is root: %s\n", isRootNode ? "yes" : "no");
  isRootNode = isRoot(root, 'Q');
  printf("Q is root: %s\n", isRootNode ? "yes" : "no");
  isRootNode = isRoot(root, 'M');
  printf("M is root: %s\n", isRootNode ? "yes" : "no");
  isLeafNode = isLeaf(root, 'A');
  printf("A is leaf: %s\n", isLeafNode ? "yes" : "no");
  isLeafNode = isLeaf(root, 'Z');
  printf("Z is leaf: %s\n", isLeafNode ? "yes" : "no");
  isLeafNode = isLeaf(root, 'Y');
  printf("Y is leaf: %s\n", isLeafNode ? "yes" : "no");
  printf("\n");

  swap(root, 'A', 'Z');
  swap(root, 'R', 'M');
  inorder(root);
  freeTree(root);
}
/*-----------------------------------------------------------------------------*/
