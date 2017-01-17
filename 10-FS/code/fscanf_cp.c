#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  FILE *originfile, *copyfile;
  char sid[11];  
  int score;

  originfile = fopen("inputlist", "r");

  if (originfile == NULL) {
    perror("Can't open input file!\n");
    exit(EXIT_FAILURE);
  }

  copyfile = fopen("copyfile", "w");

  if (copyfile == NULL) {
    perror("Can't open output file!\n");
    exit(EXIT_FAILURE);
  }

  while (fscanf(originfile, "%s %d", sid, &score) == 2) {
    fprintf(copyfile, "%s %d\n", sid, score);
  }

  fclose(originfile);
  fclose(copyfile);

  return 0;
}
