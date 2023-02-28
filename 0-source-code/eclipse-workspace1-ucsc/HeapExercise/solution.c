/* Copyright SPEL Technologies, Inc.
 * solution.c
 * Using malloc correctly
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	// Run the program with negative and large values of argv[1]
    long long int len = atoll(argv[1]);
	if (len <= 0) {
		// print error that buffer size must be greater than 0
		printf("%lld Error: Buffer size must be greater than 0", len);
		exit (EXIT_FAILURE);
	}
	else if (len > SIZE_MAX/sizeof(int)) {
		// print error message that the value of len may
		// lead to a buffer overflow
		printf("Error: %lld * sizeof(int) is greater than SIZE_MAX", len);
		exit (EXIT_FAILURE);
	} else {
		// malloc creates an array to store len ints
		int *arr = (int *)  malloc(sizeof(int) * len);
		if (arr == NULL) {
			// print memory could not be allocated
			printf("%s", "Error: could not allocate memory");
			exit (EXIT_FAILURE);
		} else {
			// fill data into arr until a special character is read
			// release memory when done
			free(arr);
			arr = NULL;
			return EXIT_SUCCESS;
		}
	}
}





