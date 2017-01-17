#include <stdio.h>
#include <stdlib.h>
int main(void){
	FILE *fp;
	fp = fopen("testfile", "w");
	if (fp == NULL) {
		printf("Can't open file!\n");
		exit(EXIT_FAILURE);
	}	
	printf("Open file successfully!\n");	
	fclose(fp);
	return 0;
}
