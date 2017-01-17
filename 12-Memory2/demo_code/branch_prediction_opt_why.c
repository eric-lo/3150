#include <stdio.h>
#include <stdlib.h>

int main() {
    // Get to know the above lines
    int testdata[3];
    testdata[0] = 129;
    testdata[1] = 128;
    testdata[2] = 127;
    for (int i =0; i < 3; i++) {
        int t = (testdata[i] - 128) >> 31;
        printf("t = %d\n", t);
        printf("~t = %d\n", ~t);
        printf("testdata[i] = %d\n", testdata[i]);
        printf("~t & testdata[i] = %d\n", ~t & testdata[i]);
    }
}
