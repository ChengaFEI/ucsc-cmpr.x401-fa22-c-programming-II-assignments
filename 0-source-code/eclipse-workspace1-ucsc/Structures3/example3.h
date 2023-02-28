#ifndef EXAMPLE3_H_
#define EXAMPLE3_H_

typedef struct {
	char nameOfDay[10];
	int temperatures[2];  /* pointer to array storing temperatures at 2 different times */
	} Record;

void change(Record *r);    /* Has an argument of type pointer to a struct */
void print(Record r);          /* Prints out the data in Record r */

#endif /* EXAMPLE3_H_ */
