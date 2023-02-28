// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 2: Data Structures and Graphs
// Problem 1
//
// singly-linked-list.c
// singly-linked-list
// 
// Function: A singly linked list structure and its operating functions.



Prompt:
Modify the linked list program in the folder eclipse-workspace2-ucsc to change the doubly linked list into a singly linked list in which a list node is declared as follows:
     struct Node {
           struct Data data;
           struct Node *next;
     };
Modify the listInsert, listDelete and listDeleteAll operations. What is the running time for the insertion and deletion operations?

Answer:
The time complexity for the insertion operation: O(1)
The time complexity for the deletion operation: O(n) (worst-case), O(1) (best-case)
The time complexity for the deleteAll operation: O(n)