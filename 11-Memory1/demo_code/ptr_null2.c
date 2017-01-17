#include <stdio.h>

int main(void) {
    int three = 3;
    int *ptr;

    ptr = &three;
    printf("Value of *ptr variable: %d\n", *ptr);
    
    ptr = NULL;
    *ptr = three; //occur segmentation fault
    /* ptr = &three; //avoid segmentation fault */
    printf("Value of *ptr variable: %d\n", *ptr); //null pointer dereference
    return 0;
}
