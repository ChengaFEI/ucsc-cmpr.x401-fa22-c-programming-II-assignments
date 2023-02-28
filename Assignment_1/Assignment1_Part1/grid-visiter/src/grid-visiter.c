//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1 : Recursion and Time Complexity
// Problem 2
//
// main.c
// grid-visitor
// 
// Function: Traverse all the grids.
//

#include <stdlib.h>
#include <stdio.h>

// Change your grid size here.
#define GRID_SIZE 5
/*-----------------------------------------------------------------------------*/

void move(int arr[GRID_SIZE][GRID_SIZE], int r, int c);
void initArray(int arr[GRID_SIZE][GRID_SIZE]);
/*-----------------------------------------------------------------------------*/

int main(void) 
{
  int arr[GRID_SIZE][GRID_SIZE];
  // Initialize the array with all 0.
  initArray(arr);
  // Move from the top-left side of the grid.
  move(arr, 0, 0);
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// move() traverses the grid from the indexed row and column, to its up/down/left/right grids.
// @Params:   arr -- the grids to traverse.
// @Params:   r   -- the row index.
// @Params:   c   -- the column index.
// @Returns:  none
// @Requires: none
void move(int arr[GRID_SIZE][GRID_SIZE], int r, int c)
{
  static int moveCount = 0;
  // Return if the index is out of the bound or the grid has been visited.
  if (r >=0 && r < GRID_SIZE && 
      c >= 0 && c < GRID_SIZE &&
      arr[r][c] != 1) {
    arr[r][c] = 1;
    moveCount++;
    // Log the current location and the total move.
    printf("The row %d column %d is visited. ", r, c);
    printf("Move Count: %d.\n", moveCount);
    // Move one grid upward/downward/leftward/rightward.
    move(arr, r, c+1);
    move(arr, r, c-1);
    move(arr, r+1, c);
    move(arr, r-1, c);
  }
}

// initArray() initializes all elements in the grid to be 0.
// @Params:   arr -- the array to be initialized.
// @Returns:  none
// @Requires: none
void initArray(int arr[GRID_SIZE][GRID_SIZE])
{
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      arr[i][j] = 0;
    }
  }
}