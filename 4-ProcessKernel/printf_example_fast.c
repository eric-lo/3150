#include <stdio.h>

#define MAX	1000000

int main(void) {
	int i = 0;
	for(i = 0; i < MAX / 5; i++) {
		printf("x\nx\nx\nx\nx\n");
	}

	return 0;
}
