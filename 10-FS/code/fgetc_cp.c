/*fgetc_cp.c*/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	FILE * originfile, * copyfile;
	int c;

	if(argc!=2){
		printf("Useage: ./cp fileName\n");
		return 1;
	}
	originfile = fopen(argv[1], "r");

	if (originfile == NULL) {
		perror("fopen!\n");
		exit(EXIT_FAILURE);
	}

	copyfile = fopen("copyfile", "w");

	if (copyfile == NULL) {
		perror("fopen\n");
		exit(EXIT_FAILURE);
	}
	while ( (c=fgetc (originfile)) != EOF ){
		printf("%c",c);
		fputc (c, copyfile);
	}

	fclose (copyfile);
	fclose ( originfile );
	return 0;
}
