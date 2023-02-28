//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 3
//
//  main.c
//  dna-counter
//

#include <stdio.h>
#include <stdlib.h>

// Basic variables settings.
#define MAXROWS 100
#define MAXCOLS 100
char chars[MAXROWS][MAXCOLS];

/**************************************/
/* Function prototype                 */
/**************************************/
int rnaCount(int numRows, int numCols);
void reset(int *, int *, int *, int *, int*, int *, int *, int *, int *, int *, int *);

/**************************************/
/* Main function                      */
/**************************************/
int main(void) {
  // Load data.
  freopen("input.txt", "r", stdin);
  int numTestCase, numRows, numCols;
  scanf(" %d", &numTestCase);

  for (int testi = 0; testi < numTestCase; testi++) {
    printf("Test case %d ", testi+1);
    // Load number of rows and columns.
    scanf(" %d", &numRows);
    scanf(" %d ", &numCols);
    // Load characters in rows and columns.
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j <= numCols; j++) {
        scanf("%c", &chars[i][j]);
      }
    }
    // Output result.
    printf("Max number of codons is %d\n", rnaCount(numRows, numCols));
  }

  return EXIT_SUCCESS;
}

/**************************************/
/* Function Implementation            */
/**************************************/

// Find total numbers of valid DNAs in the character matrix.
// Params: chars -- char pointer object with DNA candidates.
// Returns: total number of valid DNAs.
// PS: Valid DNA starts with AUG codon and ends with UAA, UAG, UGA condons.
int rnaCount(int numRows, int numCols) {
  // Initialize basic variables.
  char currentChar;
  int result = 0; // Record the total number of valid DNAs.
  int beginFirstMatch = 0; // Check whether the first character in series matches 'A'.
  int beginSecondMatch = 0; // Check whether the second character in series matches 'U'.
  int beginThirdMatch = 0; // Check whether the third character in series matches 'G'.
  // Check whether the middle characters match AUG.
  int middleFirstMatch = 0;
  int middleSecondMatch = 0;
  int middleThirdMatch = 0;
  // Check whether the ending characters match any of UAA, UAG, and UGA.
  int endFirstMatch = 0;
  int endSecondMatch = 0;
  int endSecondIsA = 0;
  int endThirdMatch = 0;
  int count = 0; // Record the number of intermediate characters.
  int countModulo = 0;

  // Loop over rows.
  for (int i = 0; i < numRows; i++) {
    reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count); // Reset basic variables to zero.
    // Loop over characters in current row.
    for (int j = 0; j < numCols; j++) {
      currentChar = chars[i][j];
      if (1 != beginThirdMatch) {
        // Check whether it matches "AUG".
        // Check the first character.
        if (1 != beginFirstMatch) {
          beginFirstMatch = currentChar == 'A';
          continue;
        }
        // Check the second character.
        if (1 != beginSecondMatch) {
          beginSecondMatch = currentChar == 'U';
          beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
          continue;
        }
        // Check the third character.
        beginThirdMatch = currentChar == 'G';
        beginSecondMatch = beginThirdMatch;
        beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
        continue;
      }
      count++;
      countModulo = count % 3;
      // Check whether it is not any character in 'A', 'U', 'C', 'G'.
      if (currentChar != 'A' && currentChar != 'U' && currentChar != 'C' && currentChar != 'G') {
        beginFirstMatch = 0;
        beginSecondMatch = 0;
        beginThirdMatch = 0;
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        count = 0;
        continue;
      }
      // Check whether it matches "AUG" in the middle of the series.
      if (countModulo==1 && currentChar=='A') {
        middleFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==middleFirstMatch) {
        if (currentChar=='U') {
          middleSecondMatch = 1;
          continue;
        }
        else {
          middleFirstMatch = 0;
          middleSecondMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==middleFirstMatch && 1==middleSecondMatch) {
        if (currentChar=='G') {
          count = 0;
        }
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        continue;
      }
      // Check whether it matches "UAA", "UAG", "UGA".
      if (countModulo==1 && currentChar=='U') {
        endFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==endFirstMatch) {
        if (currentChar=='A' || currentChar=='G') {
          endSecondMatch = 1;
          endSecondIsA = currentChar == 'A';
          continue;
        }
        else {
          endSecondMatch = 0;
          endFirstMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==endFirstMatch && 1==endSecondMatch) {
        if (currentChar=='A' || (currentChar=='G' && endSecondIsA==1)) {
          // Matches the pattern "UAA" or "UGA".
          count /= 3;
          count++;
          result = count > result ? count : result;
          reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count);
          continue;
        }
        else {
          endFirstMatch = 0;
          endSecondMatch = 0;
          endThirdMatch = 0;
          continue;
        }
      }
    }
  }
  
  // Loop over rows in reverse order.
  for (int i = 0; i < numRows; i++) {
    reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count); // Reset basic variables to zero.
    // Loop over characters in current row.
    for (int j = 0; j < numCols; j++) {
      currentChar = chars[i][numCols-1-j];
      if (1 != beginThirdMatch) {
        // Check whether it matches "AUG".
        // Check the first character.
        if (1 != beginFirstMatch) {
          beginFirstMatch = currentChar == 'A';
          continue;
        }
        // Check the second character.
        if (1 != beginSecondMatch) {
          beginSecondMatch = currentChar == 'U';
          beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
          continue;
        }
        // Check the third character.
        beginThirdMatch = currentChar == 'G';
        beginSecondMatch = beginThirdMatch;
        beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
        continue;
      }
      count++;
      countModulo = count % 3;
      // Check whether it is not any character in 'A', 'U', 'C', 'G'.
      if (currentChar != 'A' && currentChar != 'U' && currentChar != 'C' && currentChar != 'G') {
        beginFirstMatch = 0;
        beginSecondMatch = 0;
        beginThirdMatch = 0;
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        count = 0;
        continue;
      }
      // Check whether it matches "AUG" in the middle of the series.
      if (countModulo==1 && currentChar=='A') {
        middleFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==middleFirstMatch) {
        if (currentChar=='U') {
          middleSecondMatch = 1;
          continue;
        }
        else {
          middleFirstMatch = 0;
          middleSecondMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==middleFirstMatch && 1==middleSecondMatch) {
        if (currentChar=='G') {
          count = 0;
        }
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        continue;
      }
      // Check whether it matches "UAA", "UAG", "UGA".
      if (countModulo==1 && currentChar=='U') {
        endFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==endFirstMatch) {
        if (currentChar=='A' || currentChar=='G') {
          endSecondMatch = 1;
          endSecondIsA = currentChar == 'A';
          continue;
        }
        else {
          endSecondMatch = 0;
          endFirstMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==endFirstMatch && 1==endSecondMatch) {
        if (currentChar=='A' || (currentChar=='G' && endSecondIsA==1)) {
          // Matches the pattern "UAA" or "UGA".
          count /= 3;
          count++;
          result = count > result ? count : result;
          reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count);
          continue;
        }
        else {
          endFirstMatch = 0;
          endSecondMatch = 0;
          endThirdMatch = 0;
          continue;
        }
      }
    }
  }
  
  // Loop over columns.
  for (int i = 0; i < numCols; i++) {
    reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count); // Reset basic variables to zero.
    // Loop over characters in current row.
    for (int j = 0; j < numRows; j++) {
      currentChar = chars[j][i];
      if (1 != beginThirdMatch) {
        // Check whether it matches "AUG".
        // Check the first character.
        if (1 != beginFirstMatch) {
          beginFirstMatch = currentChar == 'A';
          continue;
        }
        // Check the second character.
        if (1 != beginSecondMatch) {
          beginSecondMatch = currentChar == 'U';
          beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
          continue;
        }
        // Check the third character.
        beginThirdMatch = currentChar == 'G';
        beginSecondMatch = beginThirdMatch;
        beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
        continue;
      }
      count++;
      countModulo = count % 3;
      // Check whether it is not any character in 'A', 'U', 'C', 'G'.
      if (currentChar != 'A' && currentChar != 'U' && currentChar != 'C' && currentChar != 'G') {
        beginFirstMatch = 0;
        beginSecondMatch = 0;
        beginThirdMatch = 0;
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        count = 0;
        continue;
      }
      // Check whether it matches "AUG" in the middle of the series.
      if (countModulo==1 && currentChar=='A') {
        middleFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==middleFirstMatch) {
        if (currentChar=='U') {
          middleSecondMatch = 1;
          continue;
        }
        else {
          middleFirstMatch = 0;
          middleSecondMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==middleFirstMatch && 1==middleSecondMatch) {
        if (currentChar=='G') {
          count = 0;
        }
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        continue;
      }
      // Check whether it matches "UAA", "UAG", "UGA".
      if (countModulo==1 && currentChar=='U') {
        endFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==endFirstMatch) {
        if (currentChar=='A' || currentChar=='G') {
          endSecondMatch = 1;
          endSecondIsA = currentChar == 'A';
          continue;
        }
        else {
          endSecondMatch = 0;
          endFirstMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==endFirstMatch && 1==endSecondMatch) {
        if (currentChar=='A' || (currentChar=='G' && endSecondIsA==1)) {
          // Matches the pattern "UAA" or "UGA".
          count /= 3;
          count++;
          result = count > result ? count : result;
          reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count);
          continue;
        }
        else {
          endFirstMatch = 0;
          endSecondMatch = 0;
          endThirdMatch = 0;
          continue;
        }
      }
    }
  }

  // Loop over columns in reverse order.
  for (int i = 0; i < numCols; i++) {
    reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count); // Reset basic variables to zero.
    // Loop over characters in current row.
    for (int j = 0; j < numRows; j++) {
      currentChar = chars[numRows-j-1][i];
      if (1 != beginThirdMatch) {
        // Check whether it matches "AUG".
        // Check the first character.
        if (1 != beginFirstMatch) {
          beginFirstMatch = currentChar == 'A';
          continue;
        }
        // Check the second character.
        if (1 != beginSecondMatch) {
          beginSecondMatch = currentChar == 'U';
          beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
          continue;
        }
        // Check the third character.
        beginThirdMatch = currentChar == 'G';
        beginSecondMatch = beginThirdMatch;
        beginFirstMatch = (beginSecondMatch) || (currentChar == 'A');
        continue;
      }
      count++;
      countModulo = count % 3;
      // Check whether it is not any character in 'A', 'U', 'C', 'G'.
      if (currentChar != 'A' && currentChar != 'U' && currentChar != 'C' && currentChar != 'G') {
        beginFirstMatch = 0;
        beginSecondMatch = 0;
        beginThirdMatch = 0;
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        count = 0;
        continue;
      }
      // Check whether it matches "AUG" in the middle of the series.
      if (countModulo==1 && currentChar=='A') {
        middleFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==middleFirstMatch) {
        if (currentChar=='U') {
          middleSecondMatch = 1;
          continue;
        }
        else {
          middleFirstMatch = 0;
          middleSecondMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==middleFirstMatch && 1==middleSecondMatch) {
        if (currentChar=='G') {
          count = 0;
        }
        middleFirstMatch = 0;
        middleSecondMatch = 0;
        middleThirdMatch = 0;
        continue;
      }
      // Check whether it matches "UAA", "UAG", "UGA".
      if (countModulo==1 && currentChar=='U') {
        endFirstMatch = 1;
        continue;
      }
      if (countModulo==2 && 1==endFirstMatch) {
        if (currentChar=='A' || currentChar=='G') {
          endSecondMatch = 1;
          endSecondIsA = currentChar == 'A';
          continue;
        }
        else {
          endSecondMatch = 0;
          endFirstMatch = 0;
          continue;
        }
      }
      if (countModulo==0 && 1==endFirstMatch && 1==endSecondMatch) {
        if (currentChar=='A' || (currentChar=='G' && endSecondIsA==1)) {
          // Matches the pattern "UAA" or "UGA".
          count /= 3;
          count++;
          result = count > result ? count : result;
          reset(&beginFirstMatch, &beginSecondMatch, &beginThirdMatch, &endFirstMatch, &endSecondMatch, &endSecondIsA, &endThirdMatch, &middleFirstMatch, &middleSecondMatch, &middleThirdMatch, &count);
          continue;
        }
        else {
          endFirstMatch = 0;
          endSecondMatch = 0;
          endThirdMatch = 0;
          continue;
        }
      }
    }
  }

  return result;
}

// Reset arguments to zero.
void reset(int *beginFirstMatch, int *beginSecondMatch, int *beginThirdMatch, int *endFirstMatch, int *endSecondMatch, int *endSecondIsA, int *endThirdMatch, int *middleFirstMatch, int *middleSecondMatch, int *middleThirdMatch, int *count) {
  *beginFirstMatch = 0;
  *beginSecondMatch = 0;
  *beginThirdMatch = 0;
  *endFirstMatch = 0;
  *endSecondMatch = 0;
  *endThirdMatch = 0;
  *middleFirstMatch = 0;
  *middleSecondMatch = 0;
  *middleThirdMatch = 0;
  *count = 0;
}
