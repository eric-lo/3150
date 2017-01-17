# unlink file
Any file can have multiple directory entries pointing to its i-node. Only when the link count reaches 0 can the contents of the file be deleted. Apart from that, as long as some process has the file open, its contents will not be delete. When a file is unlinked, the kernel first checks the count of the number of processes that have the file open. If this count is 0 then kernel checks the link count. If the link count is 0, the file's contents are deleted. See the following program [`unlink.c`](/code/unlink.c). Please download file [`temp`](/code/temp) before you run the program.
```c
/*unlink.c*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int main(int argc, char * argv[]){
	if(open("temp", O_RDWR) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}
	if(unlink("temp")<0){
		perror("unlink");
		exit(EXIT_FAILURE);
	}
	printf("file unlinked\n");
	sleep(20);
	printf("done!\n");
	return 0;
}
```
![](/pic/unlink.png)   
**Analysis**: First we check how much free space is available using `df` command. Then run `unlink.c` in background. After the file is unlinked, we could see that the file is not in the directory already. Check the free space again and we find the free space do not increase. After the program is done, we check the free space and see the available space increase. That's because when unlink, the process still has the file open, so its contents will not delete until process either closes the file or terminates.   
