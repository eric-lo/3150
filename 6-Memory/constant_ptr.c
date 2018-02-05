#include <stdio.h>

int main(void) {
	char *string  = "hello"; // you get a pointer to a constant
	printf("\"hello\"      = %p\n", "hello");
	printf("String pointer = %p\n", string);
	string[4] = '\0';
	printf("Go to %s\n", string);
	return 0;
}
