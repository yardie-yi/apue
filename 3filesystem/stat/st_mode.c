#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
char *file_mode(const char *file_name) 
{
    struct stat file_stat;
    int fd = open(file_name, O_RDONLY);
    if (fd < 0) {
        perror("open false: \n");
        exit(1);
    }

    if (stat(file_name, &file_stat) < 0)  {
        perror("stat false: \n");
        exit(1);
    }

    if (S_ISDIR(file_stat.st_mode)) {
        return "d";
    }

    if (S_ISREG(file_stat.st_mode)) {
        return "r";
    }

    return "-";

}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("para error!\n");
        exit(1);
    }

    printf("%s\n", file_mode(argv[1]));
}
