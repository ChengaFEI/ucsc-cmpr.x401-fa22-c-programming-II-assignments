/* Copyright SPEL Technologies, Inc.
 * enumerate.c
 * This program generate n-bit binary numbers with n = SIZE
 *
 *
 */

#include <stdio.h>
#include <string.h>

// generates 3 digit binary numbers
#define SIZE 3


typedef struct {
	char str[SIZE+1];
} Seq;

void enumerate(int index, Seq seq) {

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

	enumerate(index, seq1);
	enumerate(index, seq0);
}

int main(void) {
	Seq seq;
	strcpy(seq.str, "\0");
	int index = -1;
	enumerate(index, seq);
	return 0;
}
