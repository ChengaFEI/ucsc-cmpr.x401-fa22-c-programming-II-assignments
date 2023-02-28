/* Copyright SPEL Technologies, Inc.
 * fileIO.c
 * Read scores from a text file and print out the maximum score
 *
 * MIT License
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "scores.txt"

int main(void) {
	/* declare and initialize variables */
	FILE *scores;
	float maxScore = 0, test1;
	int j, numberOfStudents;

	scores = fopen(FILENAME, "r");                /* open file for reading */
	if (scores == NULL) {                         /* Check if file exists */
		printf("%s", "Error opening input file \n");
		exit(EXIT_FAILURE);
	}
	else {
		fscanf(scores, "%d", &numberOfStudents); /* read 1st line in file */
		for( j = 0; j < numberOfStudents; j++) { /* read remaining lines in file */
			fscanf(scores, "%f", &test1);
			maxScore = maxScore > test1? maxScore : test1; /* record maximum score */
		}
	}
	fclose(scores);                                                                   /* close the file */
	printf("The maximum score is %f \n", maxScore);        /* print out maximum score */
	return EXIT_SUCCESS;
}
