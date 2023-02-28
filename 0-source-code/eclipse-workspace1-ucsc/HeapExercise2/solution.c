/* Copyright SPEL Technologies, Inc.
 * solution.c
 * Using malloc correctly
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("%s", "Error: give a string as command line argument");
		return (-1);
	}
    size_t len = strlen(argv[1]);
    if (len > SIZE_MAX - 1 ) {
    		// print error message that string size is greater than maximum allowed
    		printf("Error: %zu + 1 is greater maximum allowed, buffer overflow may occur", len);
    		return (-1);
    	} else {
		// malloc creates an array to store a string of length len + 1 for null terminator
		int *arr = (int *)  malloc(len + 1);
		if (arr == NULL) {
			// print memory could not be allocated
			printf("%s", "Error: could not allocate memory");
			return (-1);
		} else {
			// use a safe function such as strncpy to copy string into arr and then free memory
			free(arr);
			arr = NULL;
			return 0;
		}
	}
}





