/*EW-cars_sol.c*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
	int i,car=0, loop=3;
	sem_t *ns, *ew;

	ns = sem_open("ns", O_CREAT,0666,0);
	ew = sem_open("ew", O_CREAT, 0666, 1);
	for(i=0;i<loop;i++){
		sem_wait(ew);
		printf("Semaphore: The road from east to west is open\n");
		sleep(rand()%2+1);
		printf("EW-Car: car %d passed\n",car++);
		sem_post(ns);
	}
	printf("EW: Time is up. %d cars passed.\n",car);

	sem_close(ns);
	sem_close(ew);
	sem_unlink("ns");
	sem_unlink("ew");

	return 0;
}
