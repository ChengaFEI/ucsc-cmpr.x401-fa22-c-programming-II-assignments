// UCSC Silicon Valley Extension
// Advanced C Programming
// Test 1
// Problem 4
//
// path-finder.c
// path-finder
// 
// Function: Find a highest value path from the source to the destination.

#include <stdlib.h>
#include <stdio.h>

// Change the input/output file's path here.
#define INPUT_FILEPATH  "../test-case/inputs.txt"
#define OUTPUT_FILEPATH "../test-case/outputs.txt"
/*-----------------------------------------------------------------------------*/

void readSquare(FILE *inputFile, int *srcX, int *srcY, char square[5][5]);
void displaySquare(FILE *outputFile, char square[5][5]);
void findMaxValue(char square[5][5], int x, int y, int value, int *maxValue, int initial);
/*-----------------------------------------------------------------------------*/

int main(void)
{
  printf("\n");

  // Basic variables.
  int casei;         // The test case iterator.
  int srcX, srcY;    // Coordinates of the source and the destination.
  char square[5][5]; // The array to store the square.
  int maxValue;      // The maximum value a path can get in a square.

  // Open the input stream.
  FILE *inputFile = fopen(INPUT_FILEPATH, "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error opening the input file.\n");
    return EXIT_FAILURE;
  }
  FILE *outputFile = fopen(OUTPUT_FILEPATH, "w");
  if (outputFile == NULL) {
    fprintf(stderr, "Error opening the output file.\n");
    fclose(inputFile);
    return EXIT_FAILURE;
  }

  for (casei = 0; casei < 5; casei++) {
    maxValue = 0; // Reset the maxValue.
    readSquare(inputFile, &srcX, &srcY, square);
    displaySquare(outputFile, square);
    findMaxValue(square, srcX, srcY, 0, &maxValue, 1);
    fprintf(outputFile, "The maximum value is: %d\n", maxValue);
    fprintf(outputFile, "\n");
  }

  // Close the output stream
  fclose(outputFile);
  fclose(inputFile);
  return EXIT_SUCCESS;
}
/*-----------------------------------------------------------------------------*/

// readSquare() reads data of a square from the input file into the square array.
// @Param:   inputFile -- pointer to the input file's stream.
// @Param:   srcX      -- pointer to the x-coordinate of the source.
// @Param:   srcY      -- pointer to the y-coordinate of the source.
// @Param:   square    -- the array of characters in the square.
// @Return:  srcX, srcY, destX, destY, square.
// @Require: inputFile is not NULL.
// @Note:    none
void readSquare(FILE *inputFile, int *srcX, int *srcY, char square[5][5])
{
  if (inputFile == NULL) return;
  fscanf(inputFile, "%d %d ", srcX, srcY);
  for (int rowi = 0; rowi < 5; rowi++) {
    fscanf(inputFile, "%c %c %c %c %c ", 
      &square[rowi][0], &square[rowi][1], &square[rowi][2],
      &square[rowi][3], &square[rowi][4]);
  }
}
/*-----------------------------------------------------------------------------*/

// displaySquare() displays data of a square on the console.
// @Param:   square    -- the array of characters in the square.
// @Return:  none.
// @Require: none.
// @Note:    none
void displaySquare(FILE *outputFile, char square[5][5])
{
  if (square == NULL) return;
  fprintf(outputFile, "The square is:\n");
  fprintf(outputFile, "--------------\n");
  for (int rowi = 0; rowi < 5; rowi++) {
    for (int coli = 0; coli < 5; coli++) {
      fprintf(outputFile, "%c ", square[rowi][coli]);
    }
    fprintf(outputFile, "\n");
  }
  fprintf(outputFile, "--------------\n");
}
/*-----------------------------------------------------------------------------*/

// findMaxValue() finds the maximum value a path can get in a square.
// @Param:   square   -- the array storing all the characters.
// @Param:   x        -- the x-coordinate of the current location.
// @Param:   y        -- the y-coordinate of the current location.
// @Param:   value    -- the cumulative value before arriving in this location.
// @Param:   maxValue -- pointer to the shared maximum value.
// @Return:  maxValue (update)
// @Require: square is not NULL.
// @Note:    none
void findMaxValue(char square[5][5], int x, int y, int value, int *maxValue, int initial)
{
  if (square == NULL) return;

  // Terminate if go out of the square.
  if (x<0 || x>=5 || y<0 || y>=5) return;

  char location = square[x][y];
  // Terminate if arrive at '0'.
  if (location == '0') return;
  // Terminate if go back to 'S'.
  if (location == 'S' && initial != 1) return;
  // Update maxValue if arrive at 'D' and terminate.
  if (location == 'D') {
    *maxValue = value > *maxValue ? value : *maxValue;
    return;
  }

  // Update the cumulative value if arrive at other numbers.
  switch (location) {
    case ('1'): 
      value += 1; 
      square[x][y] = '0';
      break;
    case ('2'): 
      value += 2; 
      square[x][y] = '1';
      break;
  }

  // Recursively walk in all four directions.
  findMaxValue(square, x+1, y, value, maxValue, 0);
  findMaxValue(square, x-1, y, value, maxValue, 0);
  findMaxValue(square, x, y+1, value, maxValue, 0);
  findMaxValue(square, x, y-1, value, maxValue, 0);

  // Restore the original number in the location.
  switch(location) {
    case ('1'): square[x][y] = '1'; break;
    case ('2'): square[x][y] = '2'; break;
  }
}
/*-----------------------------------------------------------------------------*/
