#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#define SIZE 10

static int loop = 0;
void sigalarm(int s)
{
    loop = 1;
    alarm(1);
}


int main(int argc, char *argv[])
{

    int sfd;
    int dfd = 1;
    int pos;
    char buf[SIZE];
    int len;
    int ret;
    if (argc < 2) {
        printf("error param\n\r");
        exit(1);
    }

    signal(SIGALRM, sigalarm);
    alarm(1);

    do {
        sfd = open(argv[1], O_RDONLY);
        if (sfd < 0) {
            if (sfd != EINTR) {
                perror("open()");
                exit(1);
            }
        }
    } while (sfd < 0);

    while(1) {
        len = read(sfd, buf, SIZE);
        if (len < 0) {
            if (len != EINTR) {
                perror("read");
                break;
            }
        }
        if (len == 0) {
            break;
        }
        
        while(!loop) {
            pause();
        }

        loop = 0;
        pos = 0;

        while (len > 0) {
            ret = write(dfd, buf+pos, len);
            if (ret < 0) {
                if (ret != EINTR) {
                    perror("write");
                    exit(1);
                }
            }
            pos += ret;
            len -= ret;
        }

    }
    
    close(sfd);
    exit(0);
}
