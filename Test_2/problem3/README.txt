Given an array that contains keys and their corresponding values, write a C program to build a binary tree using the following algorithm :

build_tree() algorithm:

1. Remove three keys with the largest values from the array. 

2. Create a new node with each key.

3. Insert the nodes in a tree. The node with the largest key amongst these nodes in the tree is made the parent of the other node(s).

4. Remove two nodes with the largest keys from the array. 

5. Repeat steps 2, 3 and 4 until the number of keys left in array is 0 or 1.

Use a max-heap to store the array.

What is the asymptotic complexity of the algorithm?

Example:

The array has the following values:

key     value

A        5

B        10

C       3

D      15

E       25

Remove B, D and E from the array. E is the root node and B and D are the child nodes.

 

The modified array is:

key     value

A        5

C       3

Next, remove A and C from array. Create new nodes and insert them into the tree. As the node D has the highest key in the tree and does not have any children, A and C are the children of D.