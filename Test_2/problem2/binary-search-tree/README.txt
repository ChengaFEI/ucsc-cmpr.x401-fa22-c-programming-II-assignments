A binary search tree is used to store a character at each node and it has the following property:

The key in any node N is larger than the keys in all nodes in N's right subtree and smaller than the keys in all nodes in the left subtree.

For example, suppose that the root node contains the key 'K'. If the node with key 'A' is inserted into the tree, it will be placed in the right subtree as the ascii value of 'A' is less than the ascii value of 'K'. A node with the key 'P' will be placed in the left subtree.

Write a C program to create a binary search tree in which each node has a key-value pair of the following type:

key is an uppercase letter of type char
a value of type int. 
insert(root, key): inserts the given key into the binary search tree with the given root node.

isRoot(root, key): returns true if the given key is in a root node.

inorder(root):performs an inorder traversal to print out the keys and values of each node in non-decreasing order of keys.

isLeaf(root, key): returns true if the given key is in a leaf node. (A leaf node does not have any child nodes)

swap(root, key1, key2): swaps the values of the two keys (key1 and key2), but leaves the positions of their nodes unchanged in the tree.

For example:

Before the swap:

key1 = ('A', 10)

key2 = ('Z', 50)

After the swap:

key1 = ('A', 50)

key2 = ('Z', 10)

 

Also find the running time for each of these functions using the asymptotic notation.

Build a tree with the following 10 key-value pairs where M is the root node:

M 50

P 80

T 100

Z 50

R 30

A 10

B 20

C 30

D 40

E 70

Then test your program with the following commands:

isRoot(root, A)

isRoot(root, Q)

isRoot(root, M)

isLeaf(root, A)

isLeaf(root, Z)

isLeaf(root, Y)

swap(root, A, Z)

swap(root, R, M)

inorder(root)