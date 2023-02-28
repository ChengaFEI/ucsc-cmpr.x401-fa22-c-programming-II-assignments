
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char myString[] = {'t', 'e', 's', 't', '\0'};

	/* Note: strlen returns length of string minus the null terminator character */
	printf("The length of the string is %zu characters \n", strlen(myString) );
	return 0;
}


