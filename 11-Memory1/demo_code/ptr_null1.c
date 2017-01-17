#include <stdio.h>

int main(void) {
    int *ptr;
    ptr = NULL;
    printf("Value of *ptr variable: %d\n", *ptr);//null pointer dereference
    return 0;
}
