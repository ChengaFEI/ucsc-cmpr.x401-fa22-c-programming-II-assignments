1. Write a C program to implement a doubly linked list L with a head pointer that points to the start of L and a tail pointer that points to the end of L. 



The list stores integer values that are greater than 0 and supports the following operations:

insert (list, key): inserts a new node with the given key at the head of the list.

delete_tail(list): deletes the node N in the given list pointed to by tail and updates tail so it points to the last node in the modified list or NULL if there are no nodes.

print(list): displays all the elements from the start to the end of the list.

merge(value): replaces two successive nodes in the list with a single node if the sum of their keys is equal to the given value.



Find the running time for each of these functions using the asymptotic notation.

For example, suppose that the list contains the following six nodes:

10, 20, 5, 40, 8, 17

merge(25) will replace the two nodes with keys 20 and 5 with a single node with key 25. It also replaces the last two nodes with keys 8 and 17 as they sum to 25. The resulting list has four nodes:

10, 25, 40, 25



To test your program, create a list with the following ten nodes:

10, 20, 5, 40, 8, 17, 1, 3, 6, 19

Display each list after each of the following operations:

merge(list, 25)

merge(list, 65)

merge(list, 4)

delete_tail(list)

delete_tail(list)