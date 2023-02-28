// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 2
// Problem 1
//
// doubly-linked-list
// test.c
// 
// Function: Test the doubly-linked-list object.

#include <stdlib.h>
#include <stdio.h>

#include "doublellist.h"
/*-----------------------------------------------------------------------------*/

// Test functions.
// Functions in this group provide pre-defined test cases.
void runTestOne();
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");
  runTestOne();
  printf("\n");
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// runTestOne() runs the first test case.
// @Param:   none
// @Return:  none
// @Require: none
// @Note:    none
void runTestOne()
{
  // Initialize a DouList.
  DouList *douList = (DouList *) malloc(sizeof(DouList));

  // Operate on the DouList.
  insert(douList, 19); // list: 19
  print(douList);
  insert(douList, 6);  // list: 6, 19
  print(douList);
  insert(douList, 3);  // list: 3, 6, 19
  print(douList);
  insert(douList, 1);  // list: 1, 3, 6, 19
  print(douList);
  insert(douList, 17); // list: 17, 1, 3, 6, 19
  print(douList);
  insert(douList, 8);  // list: 8, 17, 1, 3, 6, 19
  print(douList);
  insert(douList, 40); // list: 40, 8, 17, 1, 3, 6, 19
  print(douList);
  insert(douList, 5);  // list: 5, 40, 8, 17, 1, 3, 6, 19
  print(douList);
  insert(douList, 20); // list: 20, 5, 40, 8, 17, 1, 3, 6, 19
  print(douList);
  insert(douList, 10); // list: 10, 20, 5, 40, 8, 17, 1, 3, 6, 19
  print(douList);
  merge(douList, 25);  // list: 10, 25, 40, 25, 1, 3, 25
  print(douList);
  merge(douList, 65);  // list: 10, 65, 25, 1, 3, 25
  print(douList);
  merge(douList, 4);   // list: 10, 65, 25, 4, 25
  print(douList);
  deleteTail(douList); // list: 10, 65, 25, 4
  print(douList);
  deleteTail(douList); // list: 10, 65, 25
  print(douList);

  // Free the NodeList.
  freeDouList(douList);
}
/*-----------------------------------------------------------------------------*/