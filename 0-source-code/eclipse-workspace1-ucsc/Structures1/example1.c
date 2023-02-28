/* Copyright SPEL Technologies, Inc.
 * example1.c
 *
 * Reads a file into a structure and displays it on the console
 */
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "record.txt"


int main(void) {
	typedef struct {
		char name[50];
		int id;
		float totalMarks;
		char grade;
	} Record;

	Record rec;
	FILE *fp;
	int val;

	fp = fopen(FILENAME, "r");
	if (fp == NULL) {
		printf("%s", "Error opening file");
		exit(EXIT_FAILURE);
	}

	/* Read data from file into the structure rec and print it to the screen */
	while(( val = fscanf(fp, "%49s  %d  %f  %c", rec.name, &rec.id, &rec.totalMarks, &rec.grade)) != EOF) {
		printf("%s %d %f %c \n", rec.name, rec.id, rec.totalMarks, rec.grade);
	}

	/* close the file pointer */
	if (fclose(fp) == EOF) {
		printf("Error closing file");
	    exit(EXIT_FAILURE);
   }
	return(EXIT_SUCCESS);
}
