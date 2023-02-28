/* Copyright SPEL Technologies, Inc.
 * fgetcDemo.c
 * Reads one character from a file at a time and displays it on the console
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "grades.txt"

int main(void)  {
	/* declare variables */
	FILE *fPtr;
	int ch;

	fPtr = fopen(FILENAME, "r");          /* open file for writing */
	if(fPtr == NULL) {
		printf("%s", "Error opening file \n");
		exit(EXIT_FAILURE);
	}
	printf("%s", "Student Id  Grade\n");
	while( (ch = fgetc(fPtr)) != EOF) {     /* check if end of file is reached */
		putchar(ch);
	}
	fclose(fPtr);                           /* close file */
	return EXIT_SUCCESS;
}


