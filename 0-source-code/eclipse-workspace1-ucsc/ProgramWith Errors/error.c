/* Copyright SPEL Technologies, Inc.
 * sum.c
 * Correct this program with errors
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[])
{

	size_t len = strlen(argv[1]);

	char *arr = (char *) malloc(len + 1);
	if (arr == NULL) {
		printf("%s", "Error: could not allocate memory");
		return (-1);
	} else {
		strncpy(arr, argv[1], len);
		arr[len] = '\0';
		printf(arr);
		// process the data and then free allocated memory
		free(arr);
		return 0;
	}
}
