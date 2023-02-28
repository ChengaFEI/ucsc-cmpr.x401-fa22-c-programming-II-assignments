/* Copyright SPEL Technologies, Inc.
 * sum.c
 * This program finds the sum of all values in an array using a pointer (instead of array subscripts)
 *
 *
 */
#include <stdio.h>
#define SIZE 4

int main(void)
{
	double array[SIZE] = { 100.1, 200.2, 300.3, 400.4 };  /* declare an array */
	double sum = 0.0;
	double *ptr = &array[0];                   /* declare a pointer to first array element */
	int i;

	for (i = 0; i < SIZE; i++ )
		sum += *(ptr + i);                  /* sum += array[k] */

	printf("The sum of values in the array is %lf \n", sum);
	return 0;
}


