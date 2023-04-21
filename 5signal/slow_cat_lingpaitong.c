#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

#define BUFSIZE 10
#define TOKENSIZE 1024
static int token = 0;

void sighandler(int s) 
{
    token++;
    if (token >= TOKENSIZE) {
        token = TOKENSIZE;
    }
    alarm(1);
}

int main(int argc, char **argv)
{
    int fd;
    ssize_t ret;
    ssize_t len;
    int pos = 0;
    char buf[BUFSIZE];
    if (argc != 2) {
        printf("param error!\n");
        exit(1);
    }

    signal(SIGALRM, sighandler);
    alarm(1);
    fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        perror("open");
        exit(1);
    }

    do {
        ret = read(fd, buf, BUFSIZE);
        if (ret < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            exit(1);
        }
        while(token <= 0)
            pause();
        token--;
        pos = 0;
        while(1) {
            len = write(1, buf, ret);
            if (len < 0) {
                if (errno == EINTR) {
                    continue;
                }
                perror("write");
                exit(1);
            }
            pos += len;
            if (pos == ret)
                break;
        }
    } while(ret != 0);

    close(fd);
    exit(0);
}
