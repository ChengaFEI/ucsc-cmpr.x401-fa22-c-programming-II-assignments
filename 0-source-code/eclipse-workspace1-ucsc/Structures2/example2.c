/* Copyright SPEL Technologies, Inc.
 * example2.c
 *
 *
 */
#include <stdio.h>
#include "example2.h"

/* This function reads the name of day and 2 temperature values from
the keyboard into a Record structure. However, no changes are made to the original structure r1 as it is passed by value */
void noChange(Record r) {  /* passing structure by value */
	int i;
	printf("%s", "Enter day of week:");
	scanf("%9s", r.nameOfDay);
	for( i = 0; i < 2; i++ ) {
		printf("Enter temperature for hour %d:", i);
		scanf("%d", &r.temperatures[i] );
	}
}

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
	Record r1 = { "none", { -1, -1 } };

	/* Call function noChange */
	printf("%s", "Calling function noChange to read input \n");
	noChange(r1);
	print(r1);
	/* Call function change */
	printf("%s", "\n\n Calling function change to read input \n");
	change(&r1);  /* Note: we are passing the address of structure “r1” */
	print(r1);
	return 0;
}
