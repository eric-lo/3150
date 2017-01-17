#include <stdio.h>

int main(void) {
    char *string  = "hello"; //a pointer to a constant
    printf("\"hello\"      = %p\n", "hello");
    printf("String pointer = %p\n", string);
    printf("String  = %s\n", string);
    printf("Before update string!\n");
    string[4] = '\0'; //segmentation fault
    printf("After update string!\n");
    printf("Go to %s\n", string);
    return 0;
}
