/* Copyright SPEL Technologies, Inc.
 * example3.c
 *
 *
 */
#include <stdio.h>
#include "example3.h"

/* This function also reads the name of day and 2 temperature values from
the keyboard into a Record structure. The difference is that the argument
is a pointer to a structure and not a structure. Here, changes are made to the
original structure "r1" as it is passed by reference */
void change(Record *r) {/* passing structure by reference */
	int i;
	printf("%s", "Enter day of week:");
	scanf("%9s", r->nameOfDay);
	for( i = 0; i < 2; i++ ) {
		printf("Enter temperature for hour %d:", i);
		scanf("%d", &r->temperatures[i] );
	}
}

/* This function prints the name of day and 2 temperature values stored in the record that is passed as an argument. Here it is okay to pass argument r by value as we do not have to modify it inside print. */
void print(Record r) {
	int i;
	printf("%s", "\n Printing the data read from keyboard \n");
	printf("Day of week: %s \n", r.nameOfDay);
	for( i = 0; i < 2; i++ ) {
		printf("Temperature for hour %d is %d\n", i, r.temperatures[i]);
	}
}


int main(void) {
	int i;
	Record r1[5] = { { "none", { -1, -1 } }, { "none", { -1, -1 } }};

	for (i = 0; i < 5; i++)
		print(r1[i]);
	/* Call function change */
	printf("%s", "\n\n Calling function change to read input \n");
	for (i = 0; i < 5; i++)
		change(&r1[i]);  /* Note: we are passing the address of  “r1[i]” */
	for (i = 0; i < 5; i++)
		print(r1[i]);
	return 0;
}
