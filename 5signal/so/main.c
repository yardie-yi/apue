#include "lingpaitong.h"

#define BUFSIZE 100


int main(int argc, char **argv)
{
    int fd;
    int buf_s;
    ssize_t ret;
    ssize_t len;
    int pos = 0;
    char buf[BUFSIZE];
    if (argc != 2) {
        printf("param error!\n");
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if(fd < 0) {
        perror("open");
        exit(1);
    }

    ptf *my_ptf;
    my_ptf = init_ptf(BUFSIZE, 1024);

    do {
        buf_s = fetch_ptf(my_ptf, BUFSIZE);
        ret = read(fd, buf, buf_s);
        if (ret < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("read");
            exit(1);
        }
        if (buf_s - ret > 0) {
            return_ptf(my_ptf, buf_s - ret);
        }
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

    destory_ptf(my_ptf);
    close(fd);
    exit(0);
}
