/* Copyright SPEL Technologies, Inc.
 * example5.c
 * This program finds the sum of all values in an array using a pointer (instead of array subscripts)
 *
 *
 */
#include "example5.h"

void swap(Comet *c1_ptr, Comet *c2_ptr) {
	Comet temp;
	int len = sizeof(temp.name);
	// copy c1_ptr's pointee into temp
	strncpy(temp.name, c1_ptr->name, len- 1);
	temp.name[len - 1] = '\0';
	temp.yearOfFirstSighting = c1_ptr->yearOfFirstSighting;
	temp.period = c1_ptr->period;

	// copy c2_ptr's pointee into c1_ptr's pointee
	strncpy(c1_ptr->name, c2_ptr->name, len - 1);
	c1_ptr->name[len - 1] = '\0';
	c1_ptr->yearOfFirstSighting = c2_ptr->yearOfFirstSighting;
	c1_ptr->period = c2_ptr->period;

	// copy temp into c2_ptr's pointee
	strncpy(c2_ptr->name, temp.name, len - 1);
	c1_ptr->name[len - 1] = '\0';
	c2_ptr->yearOfFirstSighting = temp.yearOfFirstSighting;
	c2_ptr->period = temp.period;
}

void sort(Comet a[], int size) {
	int j, i, min;
	for ( j = 0; j < size; j++ ) {
		min = j;
		/* find the smallest number from a[j+1] to a[j] */
		for ( i = j+1; i < size; i++) {
			if( a[i].yearOfFirstSighting < a[min].yearOfFirstSighting )
				min = i;
		}
		/* swap the structures at index j & min*/
		swap(&a[j], &a[min]);
	}

}

void printArray(Comet arr[], int size) {
	int j;
	for (j = 0; j < size; j++) {
		printf("Comet name: %s \t", arr[j].name);
		printf("Year of first sighting %d \t", arr[j].yearOfFirstSighting);
		printf("period: %f \n", arr[j].period);
	}
}

int main(void) {
	Comet r[MAX_SIZE];
	FILE *fp;
	int i = 0, val;
	fp = fopen(FILENAME, "r");
	if(fp == NULL) {
		printf("Error opening file \n");
		return 1;
	}
	/* Read data from file into structure r and print it to the screen */
	while( (val = fscanf(fp, "%49s %d %f", r[i].name, &r[i].yearOfFirstSighting, &r[i].period)) != EOF ) {
		printf("%s %d %f  \n", r[i].name, r[i].yearOfFirstSighting, r[i].period);
		i++;
	}
	/* sort the array, i is the number of elements in the array */
	sort(r, i);
	/* print the sorted array */
	printArray(r, i);
	fclose(fp); /* close the file pointer */
	return 0;
}
