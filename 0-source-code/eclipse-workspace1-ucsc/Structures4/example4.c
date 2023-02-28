/* Copyright SPEL Technologies, Inc.
 * example4.c
 * This program finds the sum of all values in an array using a pointer (instead of array subscripts)
 *
 *
 */
#include <stdio.h>
#include "example4.h"

/* This function called readRecord reads data from the keyboard and returns it in a Record structure. */
Record readRecord(void) {/* returning structure by value */
	Record r;
	int i;
	printf("%s", "Enter day of week:");
	scanf("%9s", r.nameOfDay);
	for( i = 0; i < 2; i++ ) {
		printf("Enter temperature for hour %d:", i);
		scanf("%d", &r.temperatures[i] );
	}
	return r;
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

	/* Call function change */
	printf("%s", "\n\n Calling function change to read input \n");
	r1 = readRecord();  /* Note: the structure returned by function change is 				copied  into r1*/
	print(r1);     /* This function was defined earlier to print a Record */
	return 0;
}
