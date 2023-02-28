//
// UCSC Silicon Valley Extension
// Advanced C Programming
// Assignment 1: Recursion and Time Complexity
// Problem 6
//
// main.c
// halloween-candy-binge
// 
// Function: Help Sugar Junkie eat candy to score maximum points.
// 

#include <stdlib.h>
#include <stdio.h>

// Change the file path of inputs/outputs here.
#define INPUT_FILEPATH "../test-case/inputs.txt"
#define OUTPUT_FILEPATH "../test-case/outputs.txt"
// Set the maximum size of the grid here.
#define MAX_ROW_SIZE 100
#define MAX_COL_SIZE 100
/*-----------------------------------------------------------------------------*/

// Step functions.
// Functions in this group are in charge of the major parts of the program.
void readTestCase(FILE *inputFile, size_t *numRows, size_t *numCols, int *startRow, int *startCol, char grid[MAX_ROW_SIZE][MAX_COL_SIZE]);
void findMaxPoints(char grid[MAX_ROW_SIZE][MAX_COL_SIZE], size_t numRows, size_t numCols, int rowIndex, int colIndex, int cumPoints, int *maxPoints);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  // Open the file stream.
  printf("\n");
  FILE *inputFile = fopen(INPUT_FILEPATH, "r");
  if (inputFile == NULL) {
    printf("Error opening the file: %s\n\n", INPUT_FILEPATH);
    return EXIT_FAILURE;
  }
  FILE *outputFile = fopen(OUTPUT_FILEPATH, "w");
  if (outputFile == NULL) {
    printf("Error opening the file: %s\n\n", OUTPUT_FILEPATH);
    fclose(inputFile);
    return EXIT_FAILURE;
  }
  
  // Read the number of test cases.
  size_t numCases;
  fscanf(inputFile, "%zu", &numCases);
  int casei;
  // Run the algorithm for all test cases.
  for (casei = 0; casei < numCases; casei++) {
    // Basic variables.
    size_t numRows, numCols; // Number of rows and columns.
    int startRow, startCol;  // Coordinate of the starting position.
    char grid[MAX_ROW_SIZE][MAX_COL_SIZE]; // Elements in the grid.
    // Step 0: Refresh the max points.
    int maxPoints = 0;
    // Step 1: Read the data for current test case.
    readTestCase(inputFile, &numRows, &numCols, &startRow, &startCol, grid);
    // Step 2: Calculate the maximum points.
    findMaxPoints(grid, numRows, numCols, startRow, startCol, 0, &maxPoints);
    // Step X: Log the result.
    fprintf(outputFile, "Test case: %u\n", casei+1);
    fprintf(outputFile, "Max points collected: %u\n", maxPoints);
  }

  // Close the file stream.
  fclose(inputFile);
  fclose(outputFile);
  printf("The program runs successfully!\n");
  printf("Please read outputs in the path: \"%s\"\n\n", OUTPUT_FILEPATH);

  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// readTestCase() loads the data from the input file.
// @Param:   inputFile -- the input file stream.
// @Param:   numRows   -- pointer to the number of rows.
// @Param:   numCols   -- pointer to the number of columns.
// @Param:   startRow  -- pointer to the starting row's index.
// @Param:   startCol  -- pointer to the starting column's index.
// @Param:   grid      -- array of elements in the grid.
// @Return:  numRows, numCols, startRow, startCol, grid.
// @Require: inputFile is not NULL.
void readTestCase(FILE *inputFile, size_t *numRows, size_t *numCols, int *startRow, int *startCol, char grid[MAX_ROW_SIZE][MAX_COL_SIZE])
{
  // Basic variables.
  unsigned int rowi, coli; // Row iterator and column iterator.
  char ch;                 // Character to read.

  // Read the number of rows and columns.
  fscanf(inputFile, "%zu %zu", numRows, numCols);
  // Read the coordinate of the starting point.
  fscanf(inputFile, "%u %u", startRow, startCol);
  // Read elements in the grid.
  for (rowi = 0; rowi < *numRows; rowi++) {
    for (coli = 0; coli < *numCols; coli++) {
      ch = fgetc(inputFile);
      // Discard invalid characters.
      while (ch!='P' &&  ch!='G' && ch!='T' && ch!='S')
        ch = fgetc(inputFile);
      grid[rowi][coli] = ch;
    }
  }
}
/*-----------------------------------------------------------------------------*/

// findMaxPoints() traverses the given grid until no moves are allowed, and update the maximum points.
// @Param:   grid      -- the array of elements to traverse.
// @Param:   numRows   -- the number of rows in the grid.
// @Param:   numCols   -- the number of columns in the grid.
// @Param:   rowIndex  -- the row index of the current location.
// @Param:   colIndex  -- the column index of the current location.
// @Param:   cumPoints -- the cumulative points from all visited rooms.
// @Param:   maxPoints -- pointer to the shared maximum points.
// @Return:  maxPoints (update).
// @Require: none
void findMaxPoints(char grid[MAX_ROW_SIZE][MAX_COL_SIZE], size_t numRows, size_t numCols, int rowIndex, int colIndex, int cumPoints, int *maxPoints)
{
  // If the index is out of the bound, end the move, and update the max points.
  if (rowIndex<0 || rowIndex>=numRows || colIndex<0 || colIndex>=numCols) {
    *maxPoints = cumPoints > *maxPoints ? cumPoints : *maxPoints;
    return;
  }
  // If Sugar Junkie encounters a ghost or a visited grid, end the move, and update the max points. 
  char currRoom = grid[rowIndex][colIndex];
  if (currRoom == 'G' || currRoom == 'V') {
    *maxPoints = cumPoints > *maxPoints ? cumPoints : *maxPoints;
    return;
  }
  // If the current room is valid.
  // Cumulate the points.
  switch (currRoom) {
    case ('T'): cumPoints += 3; break;
    case ('S'): cumPoints += 2; break;
    case ('P'): break;
  }
  // Mark the current room as "visited" ('V').
  grid[rowIndex][colIndex] = 'V';
  // Traverse adjacent rooms.
  findMaxPoints(grid, numRows, numCols, rowIndex, colIndex-1, cumPoints, maxPoints);
  findMaxPoints(grid, numRows, numCols, rowIndex, colIndex+1, cumPoints, maxPoints);
  findMaxPoints(grid, numRows, numCols, rowIndex-1, colIndex, cumPoints, maxPoints);
  findMaxPoints(grid, numRows, numCols, rowIndex+1, colIndex, cumPoints, maxPoints);
  // Reset the current room to its original character.
  grid[rowIndex][colIndex] = currRoom;
}