#include <stdio.h>

int main(void)
{
	printf("fd of stdin  = %d\n", fileno(stdin));
	printf("fd of stdout = %d\n", fileno(stdout));
	printf("fd of stderr = %d\n", fileno(stderr));
	printf("%d\n", fileno(fopen("/tmp/a.txt", "w")));
    
    int input;
    int counter = 0;
    while(1) {
        scanf("%d", &input);
        counter++;
        printf("counter = %d\n", counter);
        printf("%d\n", input);
    }

    
	return 0;
}
