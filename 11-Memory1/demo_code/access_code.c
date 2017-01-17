#include <stdio.h>
int main(void) {
    void *ptr = main;
    unsigned char c = *((unsigned char *) ptr); //cast ptr to sth readable
    printf("Read  : 0x%x\n", c); // %x, Unsigned hexadecimal integer
    printf("Read  : %p\n", ptr); // %p, address stored in pointer(point address)
    printf("Write : \n");
    *((unsigned char *) ptr) = 0xff; //segmentation fault
    printf("done\n");
    return 0;
}
