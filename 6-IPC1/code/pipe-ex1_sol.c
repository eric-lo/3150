#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static int pipefd1[2],pipefd2[2];
void TELL_WAIT(void){
	if(pipe(pipefd1)<0 || pipe(pipefd2)<0){
		perror("pipe");
		exit(EXIT_FAILURE);
	}
}

void TELL_PARENT(void){
	if(write(pipefd2[1],"c",1)!=1){
		perror("write");
		exit(EXIT_FAILURE);
	}

	printf("Child send message to parent!\n");
}

void WAIT_PARENT(void){
	char c;
	if(read(pipefd1[0],&c,1)!=1){
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("Child receive message from parent!\n");
}

void TELL_CHILD(void){
	if(write(pipefd1[1],"p",1)!=1){
		perror("write");
		exit(EXIT_FAILURE);
	}

	printf("Parent send message to child!\n");
}

void WAIT_CHILD(void){
	char c;
	if(read(pipefd2[0],&c,1)!=1){
		perror("read");
		exit(EXIT_FAILURE);
	}
	printf("Parent receive message from child!\n");
}

int main(int argc, char *argv[]){
	TELL_WAIT();
	pid_t pid;
	pid = fork();
	alarm(10);
	if(pid!=0){
		while(1){
			sleep(rand()%2+1);		
			TELL_CHILD();
			WAIT_CHILD();
		}
	}else{
		while(1){
			sleep(rand()%2+1);
			WAIT_PARENT();
			TELL_PARENT();
		}
  	}
	return 0;
}
