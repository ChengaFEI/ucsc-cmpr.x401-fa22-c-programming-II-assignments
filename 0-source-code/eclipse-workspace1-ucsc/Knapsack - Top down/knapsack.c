/* Copyright SPEL Technologies, Inc.
 * knapsack.c
 * This program provides a solution to the knapsack problem
 *
 * MIT License
 */


#include <stdio.h>
#include <string.h>


// generates 3 digit binary numbers
#define SIZE 3

int weight[] = {10, 2, 3};
int value[] = {20, 6, 15};

int maxAllowedWeight = 11;
int maxValue = 0;

typedef struct {
	char str[SIZE+1];
} Seq;


void knapsack(int index, int currentValue, int currentWeight, Seq seq) {

	printf("Knapsack: %s current value: %d  current weight: %d\n", seq.str, currentValue, currentWeight);

	// backtracking
	if (currentWeight > maxAllowedWeight)
		return;

	if (currentValue > maxValue)
		maxValue = currentValue;

	if (index == SIZE-1) {
		printf("%s \n", seq.str);
		return;
	}

	index++;
	Seq seq1, seq0;
	strcpy(seq1.str, seq.str);
	strcpy(seq0.str, seq.str);
	strcat(seq1.str, "1");
	strcat(seq0.str, "0");

	knapsack(index, currentValue + value[index], currentWeight + weight[index], seq1);
	knapsack(index, currentValue, currentWeight, seq0);
}

int main(void) {
	Seq seq;
	strcpy(seq.str, "\0");
	int index = -1;
	int currentValue = 0;
	int currentWeight = 0;
	knapsack(index, currentValue, currentWeight, seq);
	printf("Maximum value is: %d", maxValue);
	return 0;
}
