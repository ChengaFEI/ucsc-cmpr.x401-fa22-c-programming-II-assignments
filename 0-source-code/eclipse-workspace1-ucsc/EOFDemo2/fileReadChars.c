/* Copyright SPEL Technologies, Inc.
 * fileReadChars.c
 * Read data from a file until EOF is reached
 *
 * MIT License
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "grades.txt"

int main(void) {
	FILE *fp;
	 char ch;

	fp = fopen("grades.txt", "r");

	while( (ch = fgetc(fp)) != EOF) {
		printf("%c", ch);
	}

	if (fclose(fp) == EOF) {
		printf("Error closing file");
	    exit(EXIT_FAILURE);
   }
	return 0;
}
