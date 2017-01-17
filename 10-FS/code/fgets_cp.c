/*fgets_cp.c*/
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[] ){
	FILE * originfile;
	FILE * copyfile;
	char line [256];

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


	while ( fgets ( line, sizeof(line), originfile ) != NULL ){
		fputs ( line, stdout );
		fprintf (copyfile ,"%s", line);
	}

	fclose (copyfile);
	fclose ( originfile );
	return 0;
}
