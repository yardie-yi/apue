#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>


off_t get_size(const char *pathname) 
{
    struct stat stat_info;

    if(stat(pathname, &stat_info) < 0) {
        perror("stat fail\n");
    }

    return stat_info.st_size;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "para error\n");
        exit(1);
    }

    printf("%lld\n",(long long)get_size(argv[1]));
    return 0;
}
