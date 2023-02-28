/* Copyright SPEL Technologies, Inc.
 * binaryFileIO.c
 *
 * Write data from an array to a binary file. Then read binary data from the same file into another array.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#define FILENAME "numbers.bin"
#define SIZE 5

int main(void) {

	FILE *fp; int i, ret;
	/* writing to binary file numbers.bin */
	int array[SIZE] = { 1, 2, 3, 4, 5 };

	fp = fopen(FILENAME, "wb");

	if (!fp) {
		printf("Error opening file");
		return(-1);
	}
	ret = fwrite (&array, sizeof(int), SIZE, fp);
	if (ret != SIZE)
		printf ("Error writing data to numbers.bin.\n");
	else
		printf ("Successfully wrote data to numbers.bin.\n");
	/* close stream */
	if (fclose(fp) == EOF) {
		printf("Error closing file");
	    exit(-1);
   }

	 /* reading from binary file numbers.bin */
	int array1[SIZE] = {0};
	fp = fopen(FILENAME, "rb");
	ret = fread (&array1, sizeof(int), SIZE, fp);
	if (ret != SIZE)
		printf ("Error reading data from numbers.bin.\n");
	else
		printf ("Successfully read data from numbers.bin.\n");
	for (i = 0; i < SIZE; i++)
		printf("%d", array1[i]);

	/* close stream */
	if (fclose(fp) == EOF) {
		printf("Error closing file");
	    exit(-1);
   }
	return 0;
}
