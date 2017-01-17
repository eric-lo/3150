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
    char *map;
    struct stat fileInfo;
    // Usage of running this program
    if (argc != 1) {
        fprintf(stderr, "usage: mmap_vs\n");
        fprintf(stderr, "       e.g., mmap_vs\n");
        exit(1);
    }
    // Before mapping a file to memory, we need to get a file descriptor for it
    // by using the open() system call
    if ((fd = open("mmap_vs.c", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
    if (stat("mmap_vs.c", &fileInfo) == -1) {
        perror("stat");
        exit(1);
    }

    offset = 1000;
    
    // mmap to read
    clock_t start = clock();
    map = mmap(0, fileInfo.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (map == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
    printf("Byte at offset %d is '%c'\n", 0, map[0]);
    double elapsedTime = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    printf("elapsedTime of mmap() = %f\n", elapsedTime);
   
    // Free the mmapped memory
    if (munmap(map, fileInfo.st_size) == -1) {
        close(fd);
        perror("Error un-mmapping the file");
        exit(1);
    }
   
    // Un-mmaping doesn't close the file, so we still need to do that
    close(fd);

    return 0;
}
