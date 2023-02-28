#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	size_t len = strlen(argv[1]);
	// malloc creates an array to store a string of length len + 1 for null terminator
	int *arr = (int *)  malloc(len + 1);
	if (arr == NULL) {
		// print memory could not be allocated
		printf("Error: could not allocate memory");
		return (-1);
	} else {
		// use a safe function such as strncpy to copy string into arr and then free memory
		return 0;
	}
}





