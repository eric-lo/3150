#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	if(open("temp", O_RDWR|O_CREAT,0664) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	if(unlink("temp")<0){
		perror("unlink");
		exit(EXIT_FAILURE);
	}
	printf("file unlinked\n");
	sleep(20);
	printf("done!\n");
	return 0;
}
