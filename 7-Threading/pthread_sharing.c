#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared = 10;

void * add(void *input) {
	
    int mylocal1 = shared;
    
    mylocal1 +=10;
    
    srand(time(NULL));
    sleep(rand()%6);
    
    shared = mylocal1;
    
	pthread_exit(NULL);
}

void * minus(void *input) {
    
    int mylocal2 = shared;
    
    mylocal2 -=10;
    
    srand(time(NULL));
    sleep(rand()%12);
    
    
    shared = mylocal2;
    
    pthread_exit(NULL);
}



int main(void) {
	pthread_t tid1, tid2;
    int input=0;
	pthread_create(&tid1, NULL, add, &input);
    pthread_create(&tid2, NULL, minus, &input);
	pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
	printf("main thread:\tshared\t= %d\n", shared);
	return 0;
}
