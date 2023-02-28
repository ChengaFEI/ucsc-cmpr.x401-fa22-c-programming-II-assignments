/* Copyright SPEL Technologies, Inc.
 * binarySearchTree.c
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"
#include "stack.h"


TreeNode * find(TreeNodeData item, TreeNode *bst) {
	if (bst == NULL)
		return NULL;
	else if (bst->data.value == item.value)
		return bst;
	else {
		if (bst->data.value < item.value)
			return find(item, bst->right);
		else
			return find(item, bst->left);
	}
}

// inorder traversal using recursion
void inOrder(TreeNode *bst) {

	if (bst != NULL) {
		inOrder(bst->left);
		printf("%d \n", bst->data.value);
		inOrder(bst->right);
	}
}



// inorder traversal without recursion
void inOrder_non_recursive(TreeNode *tree) {
	Stack *stack = createStack(10);
	push(stack, tree);
	while (!isEmpty(stack)) {
		while(tree->left != NULL && tree->left->displayed == false) {
			tree = tree->left;
			push(stack, tree);
		}

		tree = peek(stack);
		pop(stack);
		printf("Popped stack %d \n", tree->data.value);
		tree->displayed = true;  // mark node as displayed

		if (tree->right != NULL && tree->right->displayed == false) {
			tree = tree->right;
			push(stack, tree);
		}

	}
}

// recursive function to insert the given data item into the tree
TreeNode * insert(TreeNodeData item, TreeNode *bst) {
	if (bst == NULL) {

		TreeNode *newNode = (TreeNode *) calloc(sizeof(TreeNode), 1);
		if (newNode == NULL) {
			printf("Error, node could not be allocated");
			exit (EXIT_FAILURE);
		}
		newNode->data = item;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->displayed = false;
		return newNode;
	}

	if (bst->data.value < item.value)
		bst->right = insert(item, bst->right);
	else
		bst->left = insert(item, bst->left);

	return bst;
}


TreeNode * insert_non_recursive(TreeNodeData item, TreeNode *bst) {

	TreeNode *temp = bst;
	TreeNode *ptr = bst;
	while (ptr != NULL) {
		temp = ptr;
		if (ptr->data.value < item.value)
			ptr = ptr->right;
		else
			ptr = ptr->left;
	}

	TreeNode *newNode = (TreeNode *) calloc(sizeof(TreeNode), 1);

	if (newNode == NULL) {
		printf("Error, node could not be allocated");
		exit (EXIT_FAILURE);
	}

	newNode->data = item;
	newNode->left = NULL;
	newNode->right = NULL;
	if ( temp == NULL) // bst is NULL
		bst = newNode;
	// temp points to position to insert
	else if (temp->data.value < item.value)
		temp->right = newNode;
	else
		temp->left = newNode;

	return bst;
}

int main(void) {
	TreeNode *tree = NULL;
	TreeNodeData item1;
	item1.value = 8;
	TreeNodeData item2;
	item2.value = 10;
	TreeNodeData item3;
	item3.value = 7;
	TreeNodeData item4;
	item4.value = 5;
	TreeNodeData item5;
	item5.value = 6;
	TreeNodeData item6;
	item6.value = 4;
	/*TreeNodeData item7;
	item7.value = 10;
	TreeNodeData item8;
	item8.value = 7;*/


	tree = insert_non_recursive(item1, tree);
	tree = insert_non_recursive(item2, tree);
	tree = insert_non_recursive(item3, tree);
	tree = insert_non_recursive(item4, tree);
	tree = insert_non_recursive(item5, tree);
	tree = insert_non_recursive(item6, tree);


	inOrder_non_recursive(tree);

	return 0;

}
