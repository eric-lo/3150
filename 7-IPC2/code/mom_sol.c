/*mom_sol.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
int main(int argc, char * argv[]) {
	int fd; 
	int VALUE=1;
	sem_t * mutex;
	//If semaphore with name "mutex" does not exist, then create it with VALUE
	mutex = sem_open("mutex", O_CREAT, 0666, VALUE);
	printf("Mom comes home.\n");
	//wait on semaphore "mutex" and decrease it by 1
	sem_wait(mutex);
	printf("Mom checks the fridge.\n");
	//If file "fridge" does not exist, then create it, you can see manual pages for details
	fd=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
	//"fridge" is empty
	if(lseek(fd,0,SEEK_END)==0){
		printf("Mom goes to buy milk...\n");
		sleep(2);
     		write(fd,"milk ",5);
		printf("Mom puts milk in fridge and leaves.\n");
		//there is milk in "fridge" already 
		if(lseek(fd,0,SEEK_END)>5)
			printf("What a waste of food! The fridge can not hold so much milk!\n");
	}else{
		printf("Mom closes the fridge and leaves.\n");
	}
	//close file "fridge"
	close(fd);
	//add semaphore "mutex" by 1
	sem_post(mutex);
	//Befor exit, you need to close semaphore and unlink it, when all  processes have
	//finished using the semaphore, it can be removed from the system using sem_unlink
	sem_close(mutex);
	sem_unlink("mutex");
	return 0;
}
