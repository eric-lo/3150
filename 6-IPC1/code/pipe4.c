#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int agrc, char* agrv[]){
	int pipefds[2];
	pid_t pid;

	if(pipe(pipefds)==-1){
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	pid = fork();
	if(pid == -1){
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if(pid != 0){
		//replace stdout with the write end of the pipe
		dup2(pipefds[1],STDOUT_FILENO);
		//close read to pipe, in child
		close(pipefds[0]);
		execlp("ls","ls",NULL);
		exit(EXIT_SUCCESS);
	}else{
		dup2(pipefds[0],STDIN_FILENO);
		close(pipefds[1]);
		execlp("less","less",NULL);
		exit(EXIT_SUCCESS);

	}
}
