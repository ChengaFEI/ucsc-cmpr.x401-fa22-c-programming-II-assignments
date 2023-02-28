/* Copyright SPEL Technologies, Inc.
 * malloc_example.c
 * Using malloc correctly
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int newsize = 5;
	// malloc creates an array to store 5 ints
	int *arr = (int *)  malloc(sizeof(int) * newsize);

	if (arr == NULL) {
		// print memory could not be allocated
		printf("%s","Error: could not allocate memory");
		exit (EXIT_FAILURE);
	} else {
		// initialize all bytes in the array to 2
		memset(arr, 2, sizeof(int) * newsize);
		for (int i = 0; i < newsize; i++) {
			printf("%d\n", arr[i]); // print array
		}
		return EXIT_SUCCESS;
	}
}



