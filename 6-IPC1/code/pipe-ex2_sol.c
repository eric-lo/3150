#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include <sys/types.h>

int main(int argc, char *argv[]){
	int pipefds[2];
	pid_t pid;
	
	if(argc != 3){
		printf("Usage: %s command command\n",argv[0]);
		exit(EXIT_FAILURE);
	}	
	
	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if(pid == 0){
		dup2(pipefds[1],STDOUT_FILENO);
		close(pipefds[0]);
		execlp(argv[1],argv[1],NULL);
		exit(EXIT_SUCCESS);
	}else{
		dup2(pipefds[0],STDIN_FILENO);
		close(pipefds[1]);
		execlp(argv[2],argv[2],NULL);
		exit(EXIT_SUCCESS);

	}
}

	
