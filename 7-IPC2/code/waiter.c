/*waiter.c*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>

int main()
{
	const char *name = "shared_memory";
	const char *sema1= "fill";
	const char *sema2= "avail";
	const char *sema3="mutex";
	int shm_fd; //file descriptor of
	int *shelf;
	int loop=6;
	sem_t *fill, *avail, *mutex;
	/* open the shared memory segment */
	shm_fd = shm_open(name, O_RDWR, 0666);
	/* now map the shared memory segment in the address space of the process */
	shelf = mmap(0,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

	/*open semaphores*/
	fill = sem_open(sema1, O_CREAT,0666,0);
	avail = sem_open(sema2, O_CREAT, 0666, 3);
	mutex = sem_open(sema3,O_CREAT,0666,1);
	while(loop--){
		sem_wait(fill);
		sleep(rand()%2+1);
		sem_wait(mutex);
		(*shelf)--;
		sem_post(mutex);
		printf("Waiter: I pick up a pizza\n");
		sem_post(avail);
	}
 	 /*remove semaphores*/
	sem_close(fill);
	sem_close(avail);
	sem_close(mutex);
	sem_unlink(sema1);
	sem_unlink(sema2);
	sem_unlink(sema3);
	/*remove shared memory segment*/
	munmap(shelf, sizeof(int));
	close(shm_fd);
	shm_unlink(name);
	return 0;
}
