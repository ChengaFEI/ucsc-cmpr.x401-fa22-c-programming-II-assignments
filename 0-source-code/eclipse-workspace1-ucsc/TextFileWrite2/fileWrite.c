/* Copyright SPEL Technologies, Inc.
 * fileWrite.c
 * This program reads data from the console and writes to the file temperatures.txt
 *
 *
 */
#include <stdio.h>
#define FILENAME "temperatures.txt"

int main(void)  {
	/* declare and initialize variables */
	FILE *temp;
	int j, numberOfDataValues;
	float tempVal;

	temp = fopen(FILENAME, "w");          /* open file for writing */
	printf("%s", "Enter the size of dataset");
	scanf("%d", &numberOfDataValues);  /* read number of entries */
	fprintf(temp, "%d \n", numberOfDataValues);
	for(j = 0; j < numberOfDataValues; j++) {    /* repeat this for every entry */
		printf("%s", "Enter temperature:");
		scanf("%f", &tempVal);              /* read temperature value */
		fprintf(temp, "%f \n", tempVal);  /* record temperature in file */
	}
	fclose(temp);                                              /* close file */
	return 0;
}
