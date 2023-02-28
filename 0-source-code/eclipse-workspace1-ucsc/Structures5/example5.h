#ifndef EXAMPLE5_H_
#define EXAMPLE5_H_

#include <stdio.h>
#include <string.h>

#define FILENAME "comets.txt"
#define MAX_SIZE 100

typedef struct  {
		char name[50];
		int yearOfFirstSighting;
		float period;
	} Comet;

void printArray(Comet arr[], int size); /* print out the contents of array arr */
void sort(Comet arr[], int size);           /* sort the array a by field yearOfFirstSighting */
void swap(Comet *c1_ptr, Comet *c2_ptr);  /* swap the contents of Comet structures 					pointed to by c1_ptr and c2_ptr */

#endif /* EXAMPLE5_H_ */
