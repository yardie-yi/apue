#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "para error\n");
        exit(1);
    }
    int fd;
    fd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0600);
    if (fd < 0) {
        perror("open false\n");
        exit(1);
    }

    if(lseek(fd, 5L*1024L*1024L-1, SEEK_SET) < 0) {
        perror("lseek fail\n");
        exit(1);
    }
    write(fd, "", 1);

    close(fd);
    return 0;
}
