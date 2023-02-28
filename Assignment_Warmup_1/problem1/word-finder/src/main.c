//
//  UCSC Silicon Valley Extension
//  Advanced C Programming
//  Assignment 1 : C Review
//  Problem 1
//
//  main.c
//  word-finder
//

#include <stdio.h>
#include <string.h>
#include <ctype.h> 

// Basic variables settings.
#define MAXROWS 100
#define MAXCOLS 100
#define MAXWORDS 10
char grid[MAXROWS][MAXCOLS]; // Grid of words from which to search.
char wordsToFind[MAXWORDS][MAXCOLS]; // List of words to find.

// taken from  gcc-9.2.0
__attribute__ ((__noinline__))

/**************************************/
/* Helper function prototype          */
/**************************************/
size_t strnlen (const char *, size_t);

/**************************************/
/* Main function                    */
/**************************************/
int main() {
    // Declare local variables.
    // numTestCases -- overall number of test cases.
    // testi -- current test case's index.
    // size -- the size of the current grid (both the row and the column).
    // numWords -- the number of words to find in current test case.
    // numDiagonals -- the overall number of diagonals in the grid.
    int size, numWords, numTestCases, testi, numDiagonals;
    
    // Open test cases.
    freopen("input.txt", "r", stdin);
    // Read the number of test cases.
    scanf("%d", &numTestCases);
    // Initialize the result array to be all 0s.
    int wordsCount[numTestCases][MAXWORDS];
    for (testi = 0; testi < numTestCases; testi++) {
        for (int i = 0; i < MAXWORDS; i++) {
            wordsCount[testi][i] = 0;
        }
    }
    
    // Loop over all test cases.
    for (testi = 0; testi < numTestCases; testi++) {
        // Step 1.1: Load words to find from test cases.
        scanf("%d", &size);
        scanf("%d", &numWords);
        numDiagonals = 2 * size - 1; // The overall number of diagonals in the grid.

        for (int i = 0; i < numWords; i++) {
            scanf("%s", wordsToFind[i]);
        }
        
        // Step 1.2: Load the grid of words from test cases.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                scanf(" %c", &grid[i][j]); // Note: there should be a space before %c to skip spaces and newlines
            }
        }
        
#ifdef DEBUG
        // Output words to find.
        for (int i = 0; i < numWords; i++) {
            printf("%s \n", wordsToFind[i]);
        }
        // Output the grid of words.
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
#endif
        
        // Step 2: Search for words in the grid.
        //         Loop over words to find.
        char *word; // The current word to find.
        int searchRange; // The length of current word (or maximum possible length).
        int loopTimes; // Turns of a loop.
        int found; // 0 indicates current entry isn't correct, 1 indicates the correct word found.
        for (int i = 0; i < numWords; i++) {
            // Retrieve the word.
            word = wordsToFind[i];

            if (strlen(word) <= size) {
                // Step 2.1: Search in rows.
                for (int j = 0; j < size; j++) {
                    searchRange = strnlen(word, size);
                    // Identify the row.
                    loopTimes = size - searchRange + 1;
                    for (int k = 0; k < loopTimes; k++) {
                        // Inspect the current row in ascending order.
                        found = 1;
                        for (int l = 0; l < searchRange; l++) {
                            // Compare the current character in the grid with that in the word.
                            if (toupper(grid[j][k+l]) != toupper(word[l])) {
                                found = 0;
                                break;
                            }
                        }
                        if (1 == found) {
                            wordsCount[testi][i] += 1;
                        }

                        // Inspect the current row in descending order.
                        found = 1;
                        for (int l = 0; l < searchRange; l++) {
                            // Compare the current character in the grid with that in the word.
                            if (toupper(grid[j][size-k-1-l]) != toupper(word[l])) {
                                found = 0;
                                break;
                            }
                        }
                        if (1 == found) {
                            wordsCount[testi][i] += 1;
                        }
                    }
                }

                // Step 2.2: Search in columns.
                for (int j = 0; j < size; j++) {
                    searchRange = strnlen(word, size);
                    // Identify the column.
                    loopTimes = size - searchRange + 1;
                    for (int k = 0; k < loopTimes; k++) {
                        // Inspect the current row in ascending order.
                        found = 1;
                        for (int l = 0; l < searchRange; l++) {
                            // Compare the current character in the grid with that in the word.
                            if (toupper(grid[k+l][j]) != toupper(word[l])) {
                                found = 0;
                                break;
                            }
                        }
                        if (1 == found) {
                            wordsCount[testi][i] += 1;
                        }

                        // Inspect the current row in descending order.
                        found = 1;
                        for (int l = 0; l < searchRange; l++) {
                            // Compare the current character in the grid with that in the word.
                            if (toupper(grid[size-k-1-l][j]) != toupper(word[l])) {
                                found = 0;
                                break;
                            }
                        }
                        if (1 == found) {
                            wordsCount[testi][i] += 1;
                        }
                    }
                } 
            }
            
            int diagonalLength; // The length of the current diagonal.
            int startX, startY; // The index of the starting point.
            // Step 2.3: Search in diagonals.
            for (int j = 0; j < numDiagonals; j++) {
                // Identify the diagonal.
                if (j < size) diagonalLength = j + 1;
                else diagonalLength = numDiagonals - j;
                if (diagonalLength < strlen(word)) continue;
                searchRange = strnlen(word, diagonalLength);
                loopTimes = diagonalLength - searchRange + 1;

                for (int k = 0; k < loopTimes; k++) {
                    startX = j < size ? j-k : size-1-k;
                    startY = j < size ? k : j-size+1+k;
                    // Inspect the current diagonal in ascending order.
                    found = 1;
                    for (int l = 0; l < searchRange; l++) {
                        // Compare the current character in the grid with that in the word.
                        if (toupper(grid[startX-l][startY+l]) != toupper(word[l])) {
                            found = 0;
                            break;
                        }
                    }
                    if (1 == found) {
                        wordsCount[testi][i] += 1;
                    }

                    startX = j < size ? k : j-size+1+k;
                    startY = j < size ? j-k : size-1-k;
                    // Inspect the current row in descending order.
                    found = 1;
                    for (int l = 0; l < searchRange; l++) {
                        // Compare the current character in the grid with that in the word.
                        if (toupper(grid[startX+l][startY-l]) != toupper(word[l])) {
                            found = 0;
                            break;
                        }
                    }
                    if (1 == found) {
                        wordsCount[testi][i] += 1;
                    }
                }
            }

            // Step 2.4: Search in anti-diagonals.
            for (int j = 0; j < numDiagonals; j++) {
                // Identify the anti-diagonal.
                if (j < size) diagonalLength = j + 1;
                else diagonalLength = numDiagonals - j;
                if (diagonalLength < strlen(word)) continue;
                searchRange = strnlen(word, diagonalLength);
                loopTimes = diagonalLength - searchRange + 1;

                for (int k = 0; k < loopTimes; k++) {
                    startX = j < size ? size - 1 - j + k: k;
                    startY = j < size ? k : j - size + 1 + k;
                    // Inspect the current diagonal in ascending order.
                    found = 1;
                    for (int l = 0; l < searchRange; l++) {
                        // Compare the current character in the grid with that in the word.
                        if (toupper(grid[startX+l][startY+l]) != toupper(word[l])) {
                            found = 0;
                            break;
                        }
                    }
                    if (1 == found) {
                        wordsCount[testi][i] += 1;
                    }

                    startX = j < size ? size - 1 - k : numDiagonals - 1 - j - k;
                    startY = j < size ? j - k : size - k;
                    // Inspect the current row in descending order.
                    found = 1;
                    for (int l = 0; l < searchRange; l++) {
                        // Compare the current character in the grid with that in the word.
                        if (toupper(grid[startX-l][startY-l]) != toupper(word[l])) {
                            found = 0;
                            break;
                        }
                    }
                    if (1 == found) {
                        wordsCount[testi][i] += 1;
                    }
                }
            }
        }

        // Output results.
        for (int i = 0; i < numWords; i++) {
            printf("%s %d ", wordsToFind[i], wordsCount[testi][i]);
        }
        printf("\n");
    }
}

/**************************************/
/* Helper function implementation     */
/**************************************/

// Calculate the length of a word.
// Params: s -- pointer to char object pointing at the word.
// Params: n -- size_t object with the largest possible length.
// Returns: size_t object with the actual length of the word or the maximum possible length of a word.
size_t strnlen (const char *s, size_t n)
{
  size_t i = 0;
  // Loop until the word terminates or reaches the maximum length.
  while (s[i] != 0 && n--)
    i++;
  return i;
}
