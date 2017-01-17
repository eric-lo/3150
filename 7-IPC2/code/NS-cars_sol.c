/*NS-cars_sol.c*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

int main(int argc, char *argv[])
{
	int i,car=0, loop=3;
	sem_t *ns, *ew;
	ns = sem_open("ns", O_CREAT,0666,1);
	ew = sem_open("ew", O_CREAT, 0666, 0);
	for(i=0;i<loop;i++){
		sem_wait(ns);
		printf("Semaphore: The road from north to south is open\n");
		sleep(1);
		printf("NS-Car: car %d passed\n",car++);
		sem_post(ew);
	}
	printf("NS: Time is up. %d cars passed.\n",car);

	sem_close(ns);
	sem_close(ew);
	sem_unlink("ns");
	sem_unlink("ew");

	return 0;
}
