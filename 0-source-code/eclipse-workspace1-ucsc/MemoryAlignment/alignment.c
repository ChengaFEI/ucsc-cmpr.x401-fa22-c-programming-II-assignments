
#include <stdio.h>
#include <stdint.h>

// define Data according to requirements
typedef struct {
	uint8_t id1;
	uint8_t id2;
	uint64_t id3;
	uint64_t id4;

} Data;


typedef struct  {
	uint8_t id1 __attribute__ ((aligned (16)));
	uint8_t id2 __attribute__ ((aligned (16)));
	uint64_t id3 __attribute__ ((aligned (16)));
	uint64_t id4 __attribute__ ((aligned (16)));
} Data_align ;


/*typedef struct  {
	uint8_t id __attribute__ ((packed));
	uint8_t id1 __attribute__ ((packed));
	uint64_t ssid __attribute__ ((packed));
	uint64_t ssid1 __attribute__ ((packed));
} Data_align ;*/

int main(void) {
	Data data;
	printf("Unaligned addresses:\n");
	printf("The address of the struct data is %p \n", &data);
	printf("The address of the field id1 is %p \n", &data.id1);
	printf("The address of the field id2 is %p \n", &data.id2);
	printf("The address of the field id3 is %p \n", &data.id3);
	printf("The address of the field id4 is %p \n", &data.id4);

	printf("\n Aligned addresses:\n");

	Data_align data_align;
	printf("The address of the struct data_align is %p \n", &data_align);
	printf("The address of the field id1 is %p \n", &data_align.id1);
	printf("The address of the field id2 is %p \n", &data_align.id2);
	printf("The address of the field id3 is %p \n", &data_align.id3);
	printf("The address of the field id4 is %p \n", &data_align.id4);



}
