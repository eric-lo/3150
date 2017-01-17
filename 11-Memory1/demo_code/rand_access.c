#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t max_size = 1ULL<<24; // 2^24
int access_size = 1000000;

int main(void) {
    srand((int)123);
    // Generate an array
    int *tmp = (int *)malloc(sizeof(int) * max_size);
    for (size_t i = 0; i < max_size; i++) {
        tmp[i] = rand() % 10;
    }
    // Generate a list of elements to access randomly
    size_t *access = (size_t *)malloc(sizeof(size_t) * access_size);
    for (int i = 0; i < access_size; i++) {
        access[i] = rand() * 1024 % max_size;
    }
    // Read tmp randomly
    for (int i = 0; i < access_size; i++) {
        printf("num[%zu]=%d\n", access[i], tmp[access[i]]);
    }
    free(tmp);
    return 0;
}
