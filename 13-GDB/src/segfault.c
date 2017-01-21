#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *buf = NULL;

    buf = malloc(1<<31);

    fgets(buf, 1024, stdin);
    printf("%s\n", buf);

    free(buf);
    buf = NULL;

    return 1;
}
