// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 2
// Problem 2
//
// binary-search-tree
// bstree.h
// 
// Object: TreeNode.

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

typedef struct TreeNode_t {
  char key;
  int value;
  struct TreeNode_t *left;
  struct TreeNode_t *right;
} TreeNode;
/*-----------------------------------------------------------------------------*/

// Major functions.
// Functions in this group perform major functionalities of the DouNode/DouList object.
void insert(TreeNode **root, char key, int value);
int isRoot(TreeNode *root, char key);
int isLeaf(TreeNode *root, char key);
void swap(TreeNode *root, char key1, char key2);
/*-----------------------------------------------------------------------------*/

// Minor functions.
// Functions in this group perform auxiliary functionalities of the DouNode/DouList object.

// Log data.
void inorder(TreeNode *root);
// Manage the memory.
void freeTree(TreeNode *root);
/*-----------------------------------------------------------------------------*/

// Helper functions.
// Functions in this group help with the major/minor functions' implementation.
TreeNode *search(TreeNode *root, char key);
/*-----------------------------------------------------------------------------*/

