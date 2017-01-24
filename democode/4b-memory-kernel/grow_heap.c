#include <stdio.h>
#include <stdlib.h>	// malloc();
#include <string.h>	// memset();
#include <unistd.h>	// getpid();

#define ONE_MEG	(1024 * 1024)
#define COUNT	3072

int main(void) {
	int i;
	char *ptr[COUNT];

	printf("PID = %d\n", getpid());

	for(i = 0; i < COUNT; i++)
		ptr[i] = malloc(ONE_MEG);

	printf("malloc finished\n");

	for(i = 0; i < COUNT; i++) {
//		while(getchar() != '\n');
		memset(ptr[i], 0, ONE_MEG);
	}

	printf("return 0");
	return 0;
}
