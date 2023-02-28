/*
 * From Algorithms in C, 3rd edition
 * by Robert Sedgewick
 *
 */
#include <stdbool.h>

#define M 8  //  tree order

typedef struct STnode * link;
typedef int Key;

// data in data nodes
typedef struct {
	Key key;
	float value1;
	float value2;
} Item;

// key and pointer in index node
typedef struct {
	Key key;
	union {
		link next; // pointer to next nodes, used in index nodes
		Item item; // actual record, used in data nodes
	} ref ;
} entry;

// index node
struct STnode {
	entry b[M]; // array of M (pointer) key pairs
	int m;     // number of entries
};

static link head;
static int height, N;
static Item NULLItem = {0, 0};

void STinit();
link newLink();
Item searchR(link h, Key v, int height);
Item STsearch(Key v);
link split(link h);

void display(link h, int height);
void STprint() ;

bool eq(Key v1, Key v2);
bool less(Key v1, Key v2);



