
#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <stdbool.h>

typedef struct {
	int value;
} TreeNodeData;

typedef struct TreeNode_t{
	TreeNodeData data;
	struct TreeNode_t *left;
	struct TreeNode_t *right;
	bool displayed;
} TreeNode;

TreeNode * find(TreeNodeData val, TreeNode *bst);
TreeNode * insert(TreeNodeData item, TreeNode *bst);
void postOrder(TreeNode *bst); // recursive
void postOrder_non_recursive(TreeNode *tree); // non-recursive, using a stack

#endif /* BINARYSEARCHTREE_H_ */
