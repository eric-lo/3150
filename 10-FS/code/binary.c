#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE *fp;
    int buffer[4096];
    int i;
    /*open binary file*/
    fp = fopen("a.out", "rb");
    if (fp == NULL) {
        perror("fopen\n");
        exit(EXIT_FAILURE);
    }
    else {
        fread(buffer, sizeof(int), 4096, fp);
        for (i = 0; i < 4096; i++) {
            printf("%d ", buffer[i]);
        }
        putchar('\n');
    }
    fclose(fp);
    return 0;
}
