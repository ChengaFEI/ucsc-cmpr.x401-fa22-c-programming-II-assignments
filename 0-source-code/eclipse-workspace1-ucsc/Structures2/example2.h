#ifndef EXAMPLE2_H_
#define EXAMPLE2_H_

typedef struct {
	char nameOfDay[10];
	int temperatures[2];  /* pointer to array storing temperatures at 2 different times */
	} Record;

void noChange(Record r);  /* Has an argument of type struct */
void change(Record *r);    /* Has an argument of type pointer to a struct */
void print(Record r);          /* Prints out the data in Record r */

#endif /* EXAMPLE2_H_ */
