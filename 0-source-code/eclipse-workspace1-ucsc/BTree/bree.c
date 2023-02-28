/*
 * This Btree is described in Algorithms in C, 3rd edition
 * by Robert Sedgewick
 *
 * An error has been corrected in this algorithm (line 82)
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// create a new BTree
void STinit() {
	head = newLink();
	height = 0;
	N = 0;
}


link newLink() {
	link x = malloc(sizeof *x);
	x->m = 0;
	return x;
}

// search the B-tree pointed to by h for key v
// return the Item with the given key in a data node
// data nodes have height equal to 0
Item searchR(link h, Key v, int height) {
	int j;

	// if at data node, return the item
	if (height == 0) {
		for (j = 0; j < h->m; j++) {
			if(eq(v, h->b[j].key)) // found key
				return h->b[j].ref.item; // return item
		}
	}

	// if an index node
	if (height != 0) {
		// check all m items in the node
		for (j = 0; j < h->m; j++) {
			// at last item or next item has greater key
			if ( j+1 == h->m || less(v, h->b[j+1].key))
				return searchR(h->b[j].ref.next, v, height - 1);
		}
	}

	return NULLItem;
}

Item STsearch(Key v) {
	return searchR(head, v, height);
}

// insert the new item to the B-tree pointed to by h
link insertR(link h, Item item, int height) {

	int i, j;
	Key v = item.key;
	entry x;
	link t, u;

	x.key = v;
	x.ref.item = item;

	// at data node, search for position where to insert key k
	// remember than key are stored sorted in ascending order
	if (height == 0) {
		for (j = 0; j < h->m; j++)
			// v is less than the key at this position, insert here
			if (less(v, h->b[j].key))
				break;
	}

	// at index node, search for position to insert
	if (height != 0) {
		for (j = 0; j < h->m; j++) {
			// find position j where to insert new item
			if ((j+1 == h->m) || less(v, h->b[j+1].key)) {
				t = h->b[j].ref.next; // t points to the child node at position j
				//j = j+1; // This is an error in the original algorithm, remove it

				// recursively insert to child index node pointed to by t
				u = insertR(t, item, height - 1);

				// if child node was not split, u is NULL
				if (u == NULL)
					return NULL;

				// record the key of the first item in newly split child node and a pointer to it in x
				x.key = u->b[0].key;
				x.ref.next = u;
			}
		}
	}

	// need to insert at index j, shift all the items to the right
	// to make space for new item x and insert it at index j
	for (i = (h->m)++; i > j; i--)
		h->b[i] = h->b[i-1];

	// store new item at index j
	h->b[j] = x;

	// if the node has M items, split it; otherwise, return NULL
	if (h->m < M )
		return NULL;
	else
		return split(h);

}

void STinsert(Item item) {
	link t, u;

	u = insertR(head, item, height);

	if (u == NULL)
		return;

	// otherwise, old root node has been split into a new node u
	// create a new  root node t
	t = newLink();
	t->m = 2; // 2 child nodes

	// pointer at index 0 of t points to the old root head
	t->b[0].key = head->b[0].key;
	t->b[0].ref.next = head;

	// pointer at index 1 of t points to the new node u
	t->b[1].key = u->b[0].key;
	t->b[1].ref.next = u;

	head = t; // update head to this new root node t
	height++;

}

// split a node h in the B-tree
// 1. create a new node t
// 2. Move the larger half of the keys from h to the new node t
// adjust sizes of both nodes
// Code assumes that M is even and uses an extra position in each node for the item that causes the split.
// Assumes that the maximum number of keys in a node is M-1, when a node gets M keys, we split it into two nodes with M/2 keys each

link split(link h) {
	int j;
	link t = newLink(); // new node

	// copy the last M/2 items from h to t
	for (j = 0; j < M/2; j++)
		t->b[j] = h->b[M/2+j];

	// nodes h and t contain M/2 items
	h->m = M/2;
	t->m = M/2;

	return t;
}


// return true if two keys are equal; otherwise, return false.
bool eq(Key v1, Key v2) {
	if (v1 == v2)
		return true;
	else
		return false;
}

// return true if first key is less than the second key; otherwise, return false.
bool less(Key v1, Key v2) {
	if (v1 < v2)
		return true;
	else
		return false;
}



int main(void) {
	STinit();
	Item item1 = {10, 10.5, 10.5};
	Item item2 = {20, 20.5, 20.5};
	Item item3 = {30, 30.5, 30.5};
	Item item4 = {40, 40.5, 40.5};
	Item item5 = {50, 40.5, 40.5};
	Item item6 = {60, 40.5, 40.5};
	Item item7 = {70, 40.5, 40.5};
	Item item8 = {80, 140.5, 140.5};

	// Assumes that items are sorted by increasing key
	STinsert(item1);
	STinsert(item2);
	STinsert(item3);
	STinsert(item4);
	STinsert(item5);
	STinsert(item6);
	STinsert(item7);
	STinsert(item8);


	//STprint(); // complete!
	return 0;
}

