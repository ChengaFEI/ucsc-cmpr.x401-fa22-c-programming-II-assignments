/* Copyright SPEL Technologies, Inc.
 * knapsack.c
 * This program provides a solution to the knapsack problem
 *
 * MIT License
 */

#include <stdio.h>
#include <string.h>

#define SIZE 3

float maxWeight = 10;
static float maxValue = 0;
float wt[] = { 100, 100, 30};
float val[] = { 10, 20, 30};

float max(float num1, float num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}

float knapsack(float value, float spaceLeft, int level) {

	float value1 = 0, value2 = 0;

	if (level == SIZE) {
		  return 0;
	}

    level++;
    if (spaceLeft - wt[level] >= 0) {
	    value1 = knapsack(val[level], spaceLeft - wt[level], level);
    }
	 value2 = knapsack( 0, spaceLeft, level);

	return value + max(value1, value2);
}

int main(void) {

	maxValue = knapsack( 0,10, -1);
	printf("Max value %f", maxValue);
	return 0;
}
