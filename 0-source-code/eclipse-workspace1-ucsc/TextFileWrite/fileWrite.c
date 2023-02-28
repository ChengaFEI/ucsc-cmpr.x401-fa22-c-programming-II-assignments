/* Copyright SPEL Technologies, Inc.
 * fileWrite.c
 * This program reads data from the console and writes to the file temperatures.txt
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define FILENAME "temperatures.txt"

int main(void) {
	FILE *tempPtr;
	int j, numValues;
	float tempValue;

	tempPtr = fopen(FILENAME, "w");

	if (tempPtr == NULL) {
		printf("%s", "Error: file could not be opened for writing");
		exit(EXIT_FAILURE);
	}

	printf("%s", "Enter the size of the dataset");
	scanf("%d", &numValues);

	for (j = 0; j < numValues; j++) {
		printf("%s", "Enter temperature:");
		scanf("%f", &tempValue);
		printf("%f", tempValue);
		fprintf(tempPtr, "%f \n", tempValue);
	}

	fclose(tempPtr);
	return(EXIT_SUCCESS);
}
