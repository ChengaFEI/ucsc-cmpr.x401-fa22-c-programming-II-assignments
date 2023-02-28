/* Copyright SPEL Technologies, Inc.
 * fileIO.c
 * Read scores from a text file and print out the maximum score
 * 1. Open the file for reading
 * 2. Check if it was opened successfully
 * 3. Read the number of scores
 * 4. Read the scores and record the maximum score
 * 5. Close the file
 *
 * MIT License
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "scores.txt"

int main(void) {
	FILE *scores;
	float maxscore = 0, testScore;
	int j, numberOfStudents;

	scores = fopen(FILENAME, "r");
	if (scores == NULL) {
		printf("%s", "Error opening input file");
		exit(EXIT_FAILURE);
	} else {
		fscanf(scores, "%d", &numberOfStudents);

		for( j = 0; j < numberOfStudents; j++ ) {
			fscanf(scores, "%f", &testScore);
			maxscore = maxscore > testScore? maxscore: testScore;
		}

		printf("The maximum score is %f", maxscore);

		if (fclose(scores) == EOF) {
			printf("Error closing file");
		    exit(EXIT_FAILURE);
	   }

		return(EXIT_SUCCESS);
	}
}
