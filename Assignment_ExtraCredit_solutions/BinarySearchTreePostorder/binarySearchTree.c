/* Copyright SPEL Technologies, Inc.
 * binarySearchTree.c
 * Postorder traversal of a binary search tree (recursive and non-recursive)
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

// postOrder traversal using recursion
void postOrder(TreeNode *bst) {
	if (bst != NULL) {
		postOrder(bst->left);
		postOrder(bst->right);
		printf("%d \n", bst->data.value);

	}
}



// postOrder traversal without recursion
void postOrder_non_recursive(TreeNode *tree){
	Stack *stack = createStack(10);

	push(stack, tree);
	while (!isEmpty(stack)) {
		while(tree->left != NULL && tree->left->displayed == false) {
			tree = tree->left;
			push(stack, tree);
		}

		tree = peek(stack);

		if (tree->right != NULL && tree->right->displayed == false) {
			tree = tree->right;
			push(stack, tree);
		}
		else {
			tree = peek(stack);
			pop(stack);
			tree->displayed = true;  // mark node as displayed
			printf(" %d \n", tree->data.value);
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

	tree = insert_non_recursive(item1, tree);
	tree = insert_non_recursive(item2, tree);
	tree = insert_non_recursive(item3, tree);
	tree = insert_non_recursive(item4, tree);
	tree = insert_non_recursive(item5, tree);
	tree = insert_non_recursive(item6, tree);

	printf("Non recursive postorder function: \n");
	postOrder_non_recursive(tree);
	printf("Recursive postorder function: \n");
	postOrder(tree);


	// Testcase 1
	TreeNode *tree1 = NULL;
	TreeNodeData item7;
	TreeNodeData item8;
	TreeNodeData item9;
	TreeNodeData item10;
	TreeNodeData item11;
	TreeNodeData item12;
	item7.value = 5;
	item8.value = 10;
	item9.value = 3;
	item10.value = 8;
	item11.value = 20;
	item12.value = 1;

	tree1 = insert_non_recursive(item7, tree1);
	tree1 = insert_non_recursive(item8, tree1);
	tree1 = insert_non_recursive(item9, tree1);
	tree1 = insert_non_recursive(item10, tree1);
	tree1 = insert_non_recursive(item11, tree1);
	tree1 = insert_non_recursive(item12, tree1);

	//post_order(tree); //1, 3, 8, 20, 10, 5
	printf("\n\nTest case 1: \n");
	printf("Recursive postorder function : \n");
	postOrder(tree1);
	printf("Non recursive postorder function : \n");
	postOrder_non_recursive(tree1);


	// Testcase 2
	TreeNode *tree2 = NULL;
	item1.value = 7;
	item2.value = 8;
	item3.value = 2;
	item4.value = 8;
	item5.value = 20;
	item6.value = 1;

	tree2 = insert_non_recursive(item1, tree2);
	tree2 = insert_non_recursive(item2, tree2);
	tree2 = insert_non_recursive(item3, tree2);
	tree2 = insert_non_recursive(item4, tree2);
	tree2 = insert_non_recursive(item5, tree2);
	tree2 = insert_non_recursive(item6, tree2);

	//post_order(tree); //1, 2, 8, 20, 8, 7

	printf("\n\nTest case 2: \n");
	printf("Recursive postorder function : \n");
	postOrder(tree2);
	printf("Non recursive postorder function : \n");
	postOrder_non_recursive(tree2);


	// Testcase 3
	TreeNode *tree3 = NULL;
	item1.value = 7;
	item2.value = 8;
	item3.value = 2;
	item4.value = 8;
	item5.value = 20;
	item6.value = 1;
	item7.value = 11;
	item8.value = 15;

	tree3 = insert_non_recursive(item1, tree3);
	tree3 = insert_non_recursive(item2, tree3);
	tree3 = insert_non_recursive(item3, tree3);
	tree3 = insert_non_recursive(item4, tree3);
	tree3 = insert_non_recursive(item5, tree3);
	tree3 = insert_non_recursive(item6, tree3);
	tree3 = insert_non_recursive(item7, tree3);
	tree3 = insert_non_recursive(item8, tree3);

	printf("\n\nTest case 3: \n");
	printf("Recursive postorder function : \n");
	postOrder(tree3);
	printf("Non recursive postorder function : \n");
	postOrder_non_recursive(tree3);

	//post_order(tree); // 1, 2, 8, 15, 11, 20, 8, 7
	return 0;

}
