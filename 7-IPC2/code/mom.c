/*mom.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
int main(int argc, char * argv[]) {
	int fd;
	printf("Mom comes home.\n");
	printf("Mom checks the fridge.\n");
	fd=open("fridge", O_CREAT|O_RDWR|O_APPEND, 0777);
	if(lseek(fd,0,SEEK_END)==0){
		printf("Mom goes to buy milk...\n");
		sleep(2);
     		write(fd,"milk ",5);
		printf("Mom puts milk in fridge and leaves.\n");
		if(lseek(fd,0,SEEK_END)>5)
			printf("What a waste of food! The fridge can not hold so much milk!\n");
	}else{
		printf("Mom closes the fridge and leaves.\n");
	}
	close(fd);
	return 0;
}
