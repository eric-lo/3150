#include <stdio.h>

int main(void) {
	void *ptr = main;
	unsigned char c = *((unsigned char *) ptr);
	printf("Read  : 0x%x\n", c);
    printf("Read  : %p\n", ptr);
	printf("Write : \n");
	*((unsigned char *) ptr) = 0xff;
	printf("done\n");
	return 0;
}
