#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <errno.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int fd, offset;
    struct stat fileInfo;
    // Usage of running this program
    if (argc != 1) {
        fprintf(stderr, "usage: read_vs\n");
        fprintf(stderr, "       e.g., read_vs\n");
        exit(1);
    }
    // Before mapping a file to memory, we need to get a file descriptor for it
    // by using the open() system call
    if ((fd = open("read_vs.c", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
    if (stat("read_vs.c", &fileInfo) == -1) {
        perror("stat");
        exit(1);
    }

    offset = 1000;
    char buf[offset];
    // read()
    clock_t start = clock();
    if (read(fd, buf, (size_t)offset) == -1) {
        perror("open");
        exit(1);
    } 
    printf("Byte at offset %d is '%c'\n", 0, buf[0]);
    double elapsedTime = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("elapsedTime of read() = %f\n", elapsedTime);
    
    // Un-mmaping doesn't close the file, so we still need to do that
    close(fd);

    return 0;
}
