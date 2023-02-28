// Author: SPEL Technologies, Inc.
// Solution to the Its All in the Genes Problem
// Warmup assignment problem 3
//
/************ DO NOT DISTRIBUTE ******************************/

// Input file: codons.txt contains 64 codons
// Input file testcases.txt contains the test cases
// Bases are A, C, G and U; the START codon is AUG; the STOP codons are UAA, UAG, and UGA
// An RNA sequence starts with one START codon and ends with one STOP codon
// Note that there could be multiple RNA sequences in each row and column in two directions
// When a START codon is found, a flag called startState is set to true. When an invalid triplet is found or a STOP codon is reached, this flag
// is set to false. When a codon is found and startState is true, the count of number of codons is incremented. The flag is helpful because we
// don't want to start counting codons until a START codon has been found. The solution is the maximum number of codons found and is stored in maxCount.
// For example, consider this string:
// XAUGAAAUAGYAUGAAAAAAUAG
// There are two RNA sequences in this string. When the first codon AUG is found, the startState flag is set to true. Then, the next triplet is checked.
// This is AAA and is also a codon. Then, the next triplet UAG is checked. This is a STOP codon and so the startState flag is set to false. The total number
// of codons found so far is 3. As this value is greater than maxCount (0), the value of maxCount is updated to 3. Then the next triplet YAU is checked - this
// is not a codon and so AUG is found next. (We increment by 1 if an invalid codon is found, otherwise, increment by 3 to go to next codon.) This is a
// START codon, and so the startState flag is set to true. The next two triplets AAA are also codons and then the STOP codon UAG is found. The total
// number of codons in this sequence is 4, and so maxCount is updated to 4 and the startState flag is set to false. The search is repeated from
// left to right, bottom to top, and top to bottom.
// MIT License

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
//#define DEBUG

#define MAXROWS 100
#define MAXCOLS 100
#define NUM_CODONS 64
#define NUM_BASES 4   					// four bases A, C, G and U

const short SIZE_OF_CODON = 3;

char grid[MAXROWS][MAXCOLS];  			// stores the test case
char codons[MAXROWS][SIZE_OF_CODON];		 // stores all the codons
int numTestCases, numRows, numCols;

char base[] = { 'A', 'C', 'G', 'U'};
char startCodon[] = {'A', 'U', 'G'}; 	// stores the START codon
char stopCodon[][3] = { {'U', 'A', 'A'}, {'U', 'A', 'G'}, {'U', 'G', 'A'} };  // stores the STOP codons
char temp[MAXCOLS], colArray[MAXCOLS];	 // temporary arrays

int maxCount; 							 // this is the solution - maximum number of codons in a valid RNA sequence

enum CodonType {START_CODON, STOP_CODON, REG_CODON, INVALID};


// returns -1 if codon is invalid, 0 if it is a START codon, 1 if it is a STOP codon, and 2 for all other codons
int checkCodon(int row, int col, bool ROWCHECK, bool REVERSE) {
	int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

	if (ROWCHECK) {
		if (!REVERSE) {  //  check codon in grid[row][col], grid[row][col+1], grid[row][col+2]
			c1 = 1;
			c2 = 2;
		}
		else {           //  check codon in grid[row][col], grid[row][col-1], grid[row][col-2]
			c1 = -1;
			c2 = -2;
		}
	} else {
		if (!REVERSE) {
			r1 = 1;   // check codon in grid[row][col], grid[row+1][col], grid[row+2][col]
			r2 = 2;
		}
		else {
			r1 = -1;  // check codon in grid[row][col], grid[row-1][col], grid[row-2][col]
			r2 = -2;
		}
	}

	if ( (grid[row][col] == 'A') && (grid[row + r1][col + c1] == 'U') && (grid[row + r2][col + c2] == 'G') )
		return START_CODON; // found "AUG"
	else if ((grid[row][col] == 'U') &&  (grid[row + r1][col + c1] == 'A') && (grid[row + r2][col + c2] == 'A'))
		return STOP_CODON;  // found "UAA"
	else if ((grid[row][col] == 'U') &&  (grid[row + r1][col + c1] == 'A') && (grid[row + r2][col + c2] == 'G'))
		return STOP_CODON;  // found "UAG"
	else if ((grid[row][col] == 'U') &&  (grid[row + r1][col + c1] == 'G') && (grid[row + r2][col + c2] == 'A'))
		return STOP_CODON;  // found "UGA"
	else if  ( ( (grid[row][col] == 'A' ) ||  (grid[row][col] == 'C') || (grid[row][col] == 'G') || (grid[row][col] == 'U') ) &&
			( (grid[row + r1][col + c1] == 'A' ) || (grid[row + r1][col + c1] == 'C') || (grid[row + r1][col + c1] == 'G') || (grid[row + r1][col + c1] == 'U') ) &&
			( (grid[row + r2][col + c2] == 'A' ) || (grid[row + r2][col + c2] == 'C') || (grid[row + r2][col + c2] == 'G') || (grid[row + r2][col + c2] == 'U') ) )
		return REG_CODON; // found a codon that is not one of the START or STOP codons
	else
		return INVALID; // not a codon
}


// This function takes a character array as input, checks if contains a RNA sequence, and returns the number of codons in this sequence.
// To do this, it first checks if the string contains a substring that starts with a START codon and ends with an END codon.
// It then counts the number of codons between the START and STOP codons and returns this value, or 0 if it is not a valid
// RNA sequence.
void countCodons() {
	int col = 0;
	int codonCount = 0; // count of number of codons in each RNA sequence
	bool startState = false; // set to true when a START codon is found

	// count the number of codons in each row from left to right
#ifdef DEBUG
	cout << "Counting codons from left to right" << endl;
#endif

	for (int row = 0; row < numRows; row++) {
		codonCount = 0;
		col = 0;
		startState = false;

		while (col < numCols) {
			enum CodonType result = checkCodon(row, col, true, false);
			if (result == START_CODON) {
				codonCount = 1;    // found a START codon, reset count to 1
				col = col + SIZE_OF_CODON;     // look for next codon
				startState = true;
			} else if (result == STOP_CODON && startState)  {   // found a STOP codon
				codonCount++;
				startState = false;

				// check if a better solution has been found
				if (codonCount > maxCount) {
					maxCount = codonCount;
#ifdef DEBUG
					cout << row << "," << col << "  maxcount:" << maxCount << " " << "true" << "false" << endl;
#endif
				}
				codonCount = 0; // continue looking for the another RNA sequence in the same row
				col = col + SIZE_OF_CODON;  // check next codon

			} else if (result == REG_CODON && startState) { // found another codon that is not START/STOP
				codonCount++;
				col = col + 3;
			} else {  // invalid or have not found START codon as yet
				codonCount = 0;  // reset codonCount and start searching from next index
				col++;
				startState  = false;
			}

		}
	}

	// count the number of codons in each row from right to left
#ifdef DEBUG
	cout << "Counting codons from right to left" << endl;
#endif

	for (int row = 0; row < numRows; row++) {
		codonCount = 0;
		col = numCols - 1;
		startState = false;

		while (col > -1) {
			int result = checkCodon(row, col, true, true);
			if (result == START_CODON) {
				codonCount = 1;    // found a START codon, reset count to 1
				col = col - SIZE_OF_CODON;     // look for next codon
				startState = true;
			} else if (result == STOP_CODON && startState)  {   // found a STOP codon
				codonCount++;
				startState = false;

				// check if a better solution has been found
				if (codonCount > maxCount) {
					maxCount = codonCount;
#ifdef DEBUG
					cout << row << "," << col << "  maxcount:" << maxCount << " " << "true" << "true" << endl;
#endif

				}

				codonCount = 0; // continue looking for the another RNA sequence in the same row/column
				col = col - SIZE_OF_CODON;

			} else if (result == REG_CODON && startState) { // found the next codon in sequence
				codonCount++;
				col = col - SIZE_OF_CODON;
			} else { // invalid codon
				codonCount = 0;  // reset codonCount and start searching from next index
				col--;
				startState  = false;

			}
		}
	}

	int row = 0;
	// count the number of codons in each column from top to bottom
#ifdef DEBUG
	cout << "Counting codons from top to bottom" << endl;
#endif

	for (int col = 0; col < numCols; col++) {
		codonCount = 0;
		row = 0;
		startState = false;

		while (row < numRows) {
			int result = checkCodon(row, col, false, false);

			if (result == START_CODON) {
				codonCount = 1;    // found a START codon, reset count to 1
				row = row + SIZE_OF_CODON;     // look for next codon
				startState = true;
			} else if (result == STOP_CODON && startState)  {   // found a STOP codon
				codonCount++;

				// check if a better solution has been found
				if (codonCount > maxCount) {
					maxCount = codonCount;
#ifdef DEBUG
					cout << row << "," << col << " " << "  maxcount:" << maxCount << "false" << "false" << endl;
#endif

				}
				codonCount = 0; // continue looking for the another RNA sequence in the same column
				startState = false;
				row = row + SIZE_OF_CODON;
			} else if (result == REG_CODON && startState) { // found the next codon in sequence
				codonCount++;
				row = row + SIZE_OF_CODON;
			} else  { // invalid codon or START codon has not been found as yet
				codonCount = 0;  // reset codonCount and start searching from next index
				row++;
				startState = false;
			}
		}
	}

	// count the number of codons in each column from bottom to top
#ifdef DEBUG
	cout << "Counting codons from bottom to top" << endl;
#endif

	for (int col = 0; col < numCols; col++) {
		codonCount = 0;
		row = numRows - 1;
		startState = false;

		while (row > -1) {
			int result = checkCodon(row, col, false, true);

			if (result == START_CODON) {
				codonCount = 1;    // found a START codon, reset count to 1
				row = row - SIZE_OF_CODON;     // look for next codon
				startState = true;

			} else if (result == STOP_CODON && startState)  {   // found a STOP codon
				codonCount++;

				// check if a better solution has been found
				if (codonCount > maxCount) {
					maxCount = codonCount;
#ifdef DEBUG
					cout << row << "," << col << " " << "  maxcount:" << maxCount << "false" << "true" << endl;
#endif

				}

				codonCount = 0; // continue looking for the another RNA sequence in the same row/column
				startState = false;

				row = row - SIZE_OF_CODON;
			} else if (result == REG_CODON && startState) { // found the next codon in sequence
				codonCount++;
				row = row - SIZE_OF_CODON;
			} else  { // invalid codon
				codonCount = 0;  // reset codonCount and start searching from next index
				row--;
				startState = false;
			}
		}
	}
}

int main() {
	freopen("input_problem_3.txt", "r", stdin);
	int numCodons;

	//read the number of codons
	scanf("%d", &numCodons);

	//read the codons
	for (int i = 0; i < numCodons; i++)
		scanf("%s", codons[i]); // read one codon string at a time


	freopen("input_problem_3.txt", "r", stdin);

	// read the number of test cases
	scanf("%d", &numTestCases);
	int testcase;
	for (testcase = 0; testcase < numTestCases; testcase++) {
		// initialize count of maximum number of codons to 0
		maxCount = 0;

		// read a test case
		scanf("%d", &numRows);
		scanf("%d", &numCols);


		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j < numCols; j++) {
				// Note: insert a space before the format specifier %c to skip whitespace and newline characters
				scanf(" %c", &grid[i][j]);
			}
		}

		countCodons();

		// Print out the result; include the start and stop codon in maxCount
		printf("Test case %d  Max number of codons is  %d \n" ,  testcase+1, maxCount );

	}

}







