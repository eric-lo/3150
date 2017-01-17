/*NS-cars.c*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i, car=0, loop=3;
	for(i=0;i<loop;i++){
		printf("Semaphore: The road from north to south is open\n");
		sleep(1);
		printf("NS-Car: car %d passed\n",car++);
	}
	printf("NS: Time is up. %d cars passed.\n",car);
	return 0;
}
