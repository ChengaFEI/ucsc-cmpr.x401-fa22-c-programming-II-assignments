// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 3: Data Structures and Graphs
// Problem 3
//
// stack-based-queue
// 
// Function: A stack-based queue.



Prompt:

A stack is a LIFO (last in first out) structure, whereas a queue is FIFO (first in first out) structure. Write a program to implement a queue using two stacks.

The operations are described below :
a. enqueue (queue, item) : adds an item to the end of the queue. 
b. dequeue(queue) : removes an item from the front of the queue. 
c. is_empty(queue) : true if there are no items in the queue.
d. get_size(queue) : returns the number of elements in the queue.

The enqueue and dequeue operation works as follows :
enqueue (queue, x) : push x on the first stack 
dequeue (queue) :if the second stack is empty:
pop each element in the first stack and
push it on the second stack; then
pop the top item of the second stack;

Note: check for underflow during the dequeue operation



Usage:

test.c includes a few pre-defined test cases. Run the source code to see the results.