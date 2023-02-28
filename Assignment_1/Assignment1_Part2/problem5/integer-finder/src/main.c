//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1: Recursion and Time Complexity
// Problem 5
//
// main.c
// grid-visitor
// 
// Function: Find whether a given array has two integers whose sum equals a given integer.
//

#include <stdlib.h>
#include <stdio.h>
/*-----------------------------------------------------------------------------*/

// Major functions:
// Functions in this group are in charge of implementing the search.
int exhaustiveSearch(int *arr, int size, int target);
int backtrackSearch(int *arr, int size, int target);

// Helper functions:
// Functions in this group help with the major functions' implementation.
void mergeSort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  int target = 60; // Change the searching target here.
  // Initialize the array.
  printf("\n");
  int arr[10] = {10, 2, 3, 4, 38, 90, 23, 1, 10, 9};
  printf("The input array is: \n");
  for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
  printf("\n\n");

  int found;
  printf("Search method 1: Exhaustive Search...\n");
  // Search for the target.
  found = exhaustiveSearch(arr, 10, target);
  // Log the searching result.
  if (found == 0) printf("The sum %d is found.\n", target);
  else printf("The sum %d is not found.\n", target);
  printf("\n");

  printf("Search method 2: Backtracking Search...\n");
  // Sort the array.
  mergeSort(arr, 0, 9);
  // Log the sorted array.
  printf("The sorted array is: \n");
  for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
  printf("\n");
  // Search for the target.
  found = exhaustiveSearch(arr, 10, target);
  // Log the searching result.
  if (found == 0) printf("The sum %d is found.\n", target);
  else printf("The sum %d is not found.\n", target);
  printf("\n");

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// exhaustiveSearch() searches the array exhaustively and only returns true when it finds two integers in the array whose sum equals the target.
// @Params:   arr    -- the array to be searched.
// @Params:   size   -- the number of elements in the array.
// @Params:   target -- the target integer.
// @Returns:  a binary flag
//                   -- 0 indicates true (the target sum found).
//                   -- 1 indicates false (the target sum not found).
// @Requires: none
int exhaustiveSearch(int *arr, int size, int target)
{
  // Traverse all combinations of two integers in the array.
  for (int i = 0; i < size-1; i++) {
    for (int j = i+1; j < size; j++) {
      if (arr[i] + arr[j] == target) return 0;
    }
  }
  return 1;
}
/*-----------------------------------------------------------------------------*/

// backtrackSearch() searches the array in a backtrack fashion and only returns true when it finds two integers in the array whose sum equals the target.
// @Params:   arr    -- the array to be searched.
// @Params:   size   -- the number of elements in the array.
// @Params:   target -- the target integer.
// @Returns:  a binary flag
//                   -- 0 indicates true (the target sum found).
//                   -- 1 indicates false (the target sum not found).
// @Requires: the array is sorted in the ascending order.
int backtrackSearch(int *arr, int size, int target)
{
  int sum = 0;
  for (int i = 0; i < size-1; i++) {
    for (int j = i+1; j < size; j++) {
      sum = arr[i] + arr[j];
      if (sum == target) return 0; // Integers are found.
      if (sum > target) break;     //Backtrack if the sum exceeds the target.
    }
  }
  return 1;
}

/*-----------------------------------------------------------------------------*/

// mergeSort() sorts the array (elements from the index l to r) in an ascending order in the merge sort fashion.
// @Params:   arr -- the array to be sorted.
// @Params:   l   -- the index of the left bound element.
// @Params:   r   -- the index of the right bound element.
// @Returns:  arr -- the sorted array.
// @Requires: none
void mergeSort(int *arr, int l, int r)
{
  if (l < r) {
    int m = (l + r) / 2;
    mergeSort(arr, l, m);   // Traverse the left half of the array.
    mergeSort(arr, m+1, r); // Traverse the right half of the array.
    merge(arr, l, m, r);
  }
}
/*-----------------------------------------------------------------------------*/

// merge() merges elements from the index l to m with elements from the index m to r into one sorted array.
// @Params:   arr -- the array to be merged.
// @Params:   l   -- the index of the left bound element.
// @Params:   m   -- the index of the dividend element.
// @Params:   r   -- the index of the right bound element.
// @Returns:  arr -- the sorted array.
// @Requires: none
void merge(int *arr, int l, int m, int r)
{
  int length = r - l + 1; // The number of elements to be merged.
  int sorted[length];     // The array to accept sorted elements.
  int p1 = l;             // p1 points to the element in the array's left half.
  int p2 = m + 1;         // p2 points to the element in the array's right half.
  int p3 = 0;             // p3 points to the element in the sorted array.

  // Compare the left half with the right half.
  while (p1 <= m && p2 <= r) {
    if (arr[p1] < arr[p2]) sorted[p3++] = arr[p1++];
    else sorted[p3++] = arr[p2++];
  }
  // If the left half of the original array is depleted.
  while (p2 <= r) sorted[p3++] = arr[p2++];
  // If the right half of the original array od depleted.
  while (p1 <= m) sorted[p3++] = arr[p1++];
  // Copy sorted integers back to the original array.
  for (int i = 0; i < length; i++) arr[l+i] = sorted[i];
}