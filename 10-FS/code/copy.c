/*copy.c */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#define BUFF_SIZE 1024
int main(int argc, char *argv[])
{
	int src_fd,dest_fd,readByte,writeByte;
	char *buff[BUFF_SIZE];
	/* Check the input*/
	if(argc != 3)
	{
		printf("\nUsage: ./copy source_file destination_file\n");
		exit(EXIT_FAILURE);
	}
	/* Open source file with read only flag*/
	src_fd = open(argv[1],O_RDONLY);
	if(src_fd == -1)
	{
		perror("Source file open");
		exit(EXIT_FAILURE);
	}
	/* Open destination file with write only flag, if it is not existed, creat it with permission 666*/
	dest_fd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if(dest_fd == -1)
	{
		perror("Destination file open");
		exit(EXIT_FAILURE);
	}
	/* Start data transfer from src file to dest file untill it reaches EOF*/
	while((readByte = read(src_fd,buff,BUFF_SIZE)) > 0)
	{
		if(write(dest_fd,buff,readByte) != readByte){
			perror("Write");
			exit(EXIT_FAILURE);
		}
	}
	if(readByte == -1){
		perror("Read");
		exit(EXIT_FAILURE);
	}
	close(src_fd);
	close(dest_fd);
	exit(EXIT_SUCCESS);
}
