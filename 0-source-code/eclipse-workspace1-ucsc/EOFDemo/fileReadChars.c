/* Copyright SPEL Technologies, Inc.
 * fileReadChars.c
 * Read data from a file until EOF is reached
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define FILENAME "grades.txt"
int main(void)  {
	FILE *fPtr; 	                                         /* declare variables */
	int id;
	char grade;
	int fileStatus;
	fPtr = fopen(FILENAME, "r");                             /* open file for reading */
	if(fPtr == NULL) {
		printf("%s", "Error opening file \n");
		exit(EXIT_FAILURE);
	}
	printf("Student ID	Grade \n");

	fileStatus = fscanf(fPtr, "%d  %c", &id, &grade); 		/* read one line */
	while(fileStatus != EOF) {                              /* check if end of file is reached */
		printf("%d\t	%c\n", id, grade);        			/* print out data */
		fileStatus = fscanf(fPtr, "%d  %c", &id, &grade);	 /* read next line */
	}
	if (fclose(fPtr) == EOF) {
		printf("Error closing file");
	    exit(EXIT_FAILURE);
   }                                            /* close file */
	return 0;
}
