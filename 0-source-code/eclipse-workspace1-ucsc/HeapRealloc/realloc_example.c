/* Copyright SPEL Technologies, Inc.
 * realloc_example.c
 * Using realloc correctly
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *arr = NULL;
	// realloc creates an array of size 5
	int newsize = 5;
	int *ptr = realloc(arr, sizeof(int) * newsize);

	if (!ptr) {
		// print memory could not be allocated
		printf("Error: could not allocate memory %p", ptr);
		exit(EXIT_FAILURE);
	} else {
		arr = ptr; // important because arr is still null
		for (int i = 0; i < newsize; i++) {
			arr[i] = i; // put some values in the array
		}
		// realloc resizes the allocated array to 10
		newsize = 10;
		ptr = realloc(arr, sizeof(int) * newsize);

		if (ptr == NULL) {
			// print memory could not be allocated
			printf("%s", "Error: could not allocate memory");
			exit(EXIT_FAILURE);
		} else {
			arr = ptr; // important

			for (int i = 0; i < newsize; i++) {
				printf("%d\n", arr[i]); // print array
			}
			return EXIT_SUCCESS;
		}
	}
}



