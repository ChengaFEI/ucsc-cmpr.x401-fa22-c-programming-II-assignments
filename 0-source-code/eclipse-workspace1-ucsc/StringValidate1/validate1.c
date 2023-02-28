/* Copyright SPEL Technologies, Inc.
 * validate1.c
 *
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

#define SIZE 10
char str1[SIZE] = "alpha", str2[SIZE] = "bet ";
strncat(str1, " betical ", 3);
printf("%s\n", str1);


strncat(str1, str2, SIZE - strlen(str1) - 1);
 //Error! str1 is not a valid string. Why?
printf("%s\n", str1);

// Copy only as much as can fit in available slots using strlen:
strncat(str1, str2, SIZE - strlen(str1) - 1);
str1[SIZE - 1] = '\0';

printf("%s\n", str1);

	char name[20];
    if (strlen(argv[1]) >= sizeof(name)) {
    	printf("%s", "Error 1: buffer size exceeded");
    	exit(-1);
    }
    strcpy(name, argv[1]);
    strcat(name, " ");
    if (strlen(argv[2]) >= (sizeof(name) - strlen(name))) {
       	printf("%s","Error 2: buffer size exceeded");
       	exit(-1);
       }
    strcat(name, argv[2]);
    printf("%s", name);
    return 0;
}

