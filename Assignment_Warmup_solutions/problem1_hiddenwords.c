// Copyright 2018 SPEL Technologies, Inc.
// Find the words hidden in a 2-d grid by searching in 8 directions
// Warm up assignment, problem 1 solution
//
/*****************  DO NOT DISTRIBUTE ************************/


#include <stdio.h>
#include <string.h>

#define MAXROWS 100
#define MAXCOLS 100
#define MAXWORDS 10


char grid[MAXROWS][MAXCOLS];
char wordsToFind[MAXWORDS][MAXCOLS];

// Start searching for searchWord from the position (startRow, startCol)
// To find the word in a row from left to right, set stepRow to 0 and stepCol to 1
// To find the word in a row from right to left, set stepRow to 0 and stepCol to -1
// To find the word in a column from top to bottom, set stepRow to 1 and stepCol to 0
// To find the word in a column from bottom to top, set stepRow to -1 and stepCol to 0
// To find the word in a diagonal from upper left to lower right, set stepRow to 1 and stepCol to 1
// To find the word in a diagonal from lower right to upper left, set stepRow to -1 and stepCol to -1
// To find the word in a diagonal from lower left to upper right, set stepRow to -1 and stepCol to 1
// To find the word in a diagonal from upper right to lower left, set stepRow to 1 and stepCol to -1
// This function returns 0 if the word is not found, otherwise, it returns 1
int checkIfOccurs(const char *word, int startRow, int startCol, int stepRow, int stepCol) {
	int row = startRow;
	int col = startCol;
	int found = 1;
	int i = 0, len=0;
	 len = strnlen(word, MAXCOLS);  // length of searchWord


	while (row >= 0 && col >= 0 && row <= MAXROWS-1 && col <= MAXCOLS-1 && found == 1 && i < len) {
		if(word[i] != grid[row][col])
			found = 0;
		else {
			i++;
			row = row + stepRow;
			col = col + stepCol;
		}
	}
	if (i != len)   // Number of characters compared were less than the length of searchWord
		found = 0;
	return found;
}

// taken from  gcc-9.2.0
__attribute__ ((__noinline__))
size_t
strnlen (const char *s, size_t n)
{
  size_t i;

  i = 0;
  while (s[i] != 0 && n--)
    i++;

  return i;
}


int main() {
	int testi;

	freopen("input_problem_1.txt", "r", stdin);
	int size, numWords, numTestCases;
	scanf("%d", &numTestCases);

	for (testi = 0; testi < numTestCases; testi++) {
		scanf("%d", &size);
		scanf("%d", &numWords);
		for (int i = 0; i < numWords; i++) {
			scanf("%s", wordsToFind[i]);
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				scanf(" %c", &grid[i][j]); // Note: there should be a space before %c to skip spaces and newlines
			}
		}
#ifdef DEBUG
		for (int i = 0; i < numWords; i++) {
				printf("%s \n", wordsToFind[i]);
			}
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
#endif

		int count = 0;
		for (int k = 0; k < numWords; k++) {
			count = 0;
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					count += checkIfOccurs(wordsToFind[k], i, j, 0, 1);
					count += checkIfOccurs(wordsToFind[k], i, j, 0, -1);
					count += checkIfOccurs(wordsToFind[k], i, j, 1, 0);
					count += checkIfOccurs(wordsToFind[k], i, j, -1, 0);
					count += checkIfOccurs(wordsToFind[k], i, j, 1, 1);
					count += checkIfOccurs(wordsToFind[k], i, j, -1, -1);
					count += checkIfOccurs(wordsToFind[k], i, j, -1, 1);
					count += checkIfOccurs(wordsToFind[k], i, j, 1, -1);

				}
			}
			printf(" %s    %d ", wordsToFind[k], count) ;
		}
		printf("\n");
	}
}
