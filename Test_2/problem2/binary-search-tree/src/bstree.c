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

#include "bstree.h"
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Major functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Insert a key-value pair into the BST.
/// @param   root  -- pointer to the root node.
/// @param   key   -- the character to be inserted.
/// @param   value -- the value to be inserted.
/// @return  root (updated)
/// @require key has not appeared in the tree.
/// @note    none
void insert(TreeNode **root, char key, int value)
{
  // Create a new TreeNode.
  TreeNode *node = (TreeNode *) malloc(sizeof(TreeNode));
  node->key = key;
  node->value = value;
  // Insert into the tree.
  char tempKey;
  if (*root == NULL) *root = node;
  else {
    tempKey = (*root)->key;
    if (tempKey == key) return;
    else if (tempKey > key) insert(&(*root)->right, key, value);
    else insert(&(*root)->left, key, value);
  }
}
/*-----------------------------------------------------------------------------*/

/// @brief   Check whether the key is in the root node.
/// @param   root -- pointer to the root node of the tree.
/// @param   key  -- the character of the node to search for.
/// @return  1  indicates true,
///          0  indicates false,
///          -1 indicates a NULL tree.
/// @require root is not NULL
/// @note    none
int isRoot(TreeNode *root, char key)
{
  if (root == NULL) return -1;
  return root->key == key;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Check whether the key appears in the leaf node of the tree.
/// @param   root -- pointer to the root node of the tree.
/// @param   key  -- the character of the node to search for.
/// @return  1  indicates true,
///          0  indicates false,
///          -1 indicates a NULL tree.
/// @require root is not NULL
/// @note    none
int isLeaf(TreeNode *root, char key)
{
  if (root == NULL) return -1;
  TreeNode *node = search(root, key);
  if (node == NULL) return 0;
  if (node->left != NULL || node->right != NULL) return 0;
  return 1;
}
/*-----------------------------------------------------------------------------*/

/// @brief   Swap values of two TreeNodes.
/// @param   root -- pointer to the root node of the tree.
/// @param   key1 -- the key character of the first node.
/// @param   key2 -- the key character of the second node.
/// @return  root (updated)
/// @require none
/// @note    none
void swap(TreeNode *root, char key1, char key2)
{
  if (root == NULL) return;
  TreeNode *node1 = search(root, key1);
  TreeNode *node2 = search(root, key2);
  if (node1 == NULL || node2 == NULL) return;
  int tempValue = node1->value;
  node1->value = node2->value;
  node2->value = tempValue;
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Minor functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Perform an inorder traversal to print out the keys and values of each node in non-decreasing order of keys.
/// @param   root -- pointer to the root node of the (sub)tree.
/// @return  none
/// @require none
/// @note    none
void inorder(TreeNode *root)
{
  if (root == NULL) return;
  inorder(root->left);
  printf("%c %d\n", root->key, root->value);
  inorder(root->right);
}
/*-----------------------------------------------------------------------------*/

/// @brief   Release all the dynamic memories used by the TreeNode.
/// @param   root -- pointer to the root node of the BST.
/// @return  none
/// @require none
/// @note    none
void freeTree(TreeNode *root) 
{
  if (root == NULL) return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/

// Helper functions.
/*-----------------------------------------------------------------------------*/

/// @brief   Search the BST for the key character.
/// @param   root -- pointer to the root node of the tree.
/// @param   key  -- the character of the node to search for.
/// @return  pointer to the found TreeNode,
///          NULL if not found.
/// @require root is not NULL
/// @note    none
TreeNode *search(TreeNode *root, char key)
{
  if (root == NULL) return NULL;
  if (root->key == key) return root;
  else if (root->key > key) return search(root->right, key);
  else return search(root->left, key);
}
/*-----------------------------------------------------------------------------*/