/* Copyright SPEL Technologies, Inc.
 * problem.c
 * Program with a vulnerability
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char *arr = (char *)  malloc(10*sizeof(char));
	if (arr == NULL) {
		// print memory could not be allocated
		printf("%s", "Error: could not allocate memory");
		return (EXIT_FAILURE);
	} else {
		strcpy(arr, "Hello");
		free(arr); // free memory allocated
		printf("%s", arr); // does it display deleted contents?!!
		return EXIT_SUCCESS;
	}
}






