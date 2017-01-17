/*EW-cars.c*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int i,car=0, loop=3;
	for(i=0;i<loop;i++){
		printf("Semaphore: The road from east to west is open\n");
		sleep(rand()%2+1);
		printf("EW-Car: car %d passed\n",car++);
	}
	printf("EW: Time is up. %d cars passed.\n",car);
	return 0;
}
