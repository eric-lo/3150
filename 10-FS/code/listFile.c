/*listFile.c*/
#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <dirent.h>
int main(void){
	char *curr_dir = NULL;
	DIR *dp = NULL;
	struct dirent *dptr = NULL;
	int count = 0;
	curr_dir = getenv("PWD");
	if(curr_dir == NULL){
		perror("getenv");
		exit(EXIT_FAILURE);
	}
	if(dp == opendir((const char*)curr_dir)){
		perror("opendir");
		exit(EXIT_FAILURE);
	}
	for(count = 0; (dptr = readdir(dp)) != NULL ; count++){
		printf("%s  ",dptr->d_name);
	}
	printf("\nTotal files %u \n", count);
	return 0;
}
