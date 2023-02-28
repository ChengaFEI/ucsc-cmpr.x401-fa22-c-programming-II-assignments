#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
void ranges();

int main(int argc, char *argv[])
{
	printf("The size of a char is %zu \n", sizeof(char));
	printf("The size of an int is %zu \n", sizeof(int));
	printf("The size of a long is %zu \n", sizeof(long int));
	printf("The size of a long long is %zu \n", sizeof(long long int));
	printf("The size of size_t is %zu \n", sizeof(size_t));

	printf("The size of a uint8_t is %zu \n", sizeof(uint8_t));
	printf("The size of a uint16_t is %zu \n", sizeof(uint16_t));
	printf("The size of a uint_least16_t is %zu \n", sizeof(uint_least16_t));
	printf("The size of a intmax_t is %zu \n", sizeof(intmax_t));

	ranges();



	size_t len = strlen(argv[1]);
	char *arr = (char *)  malloc(len + 1);
    strncpy(arr, argv[1], len);
    printf(arr);
    free(arr);
	return 0;
	return 0;
}


