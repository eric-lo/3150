#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Generate data
    const unsigned arraySize = 32768;
    int data[arraySize];
    srand((int)123);

    for (unsigned c = 0; c < arraySize; ++c)
        data[c] = rand() % 256;
    
    // Test
    clock_t start = clock();
    long long sum = 0;
    long long sum1 = 0, sum2=0, sum3=0, sum4=0;

    for (unsigned i = 0; i < 100000; ++i) {
        // Primary loop
        for (unsigned c = 0; c < arraySize; c+=4) {
                sum1 += data[c+0];
                sum2 += data[c+1];
                sum3 += data[c+2];
                sum4 += data[c+3];
        }
    }
    sum = sum1 + sum2 + sum3 + sum4; 

    double elapsedTime = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    printf("elapsedTime = %f\n", elapsedTime);
    printf("sum = %llu\n", sum);
}
