#ifndef EXAMPLE4_H_
#define EXAMPLE4_H_

typedef struct {
	char nameOfDay[10];
	int temperatures[2];  /* pointer to array storing temperatures at 2 different times */
	} Record;

Record readRecord(void);

#endif /* EXAMPLE4_H_ */
