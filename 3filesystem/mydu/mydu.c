#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#define PATHSIZE 1024

bool loop(const char *path)
{
    char *pos;
    pos = strrchr(path, '/');
    if(pos == NULL)
        exit(1);
    if(strcmp(pos+1, ".") == 0 || strcmp(pos+1, "..") == 0)
        return false;
    return true;
}

int64_t size(const char *path)
{
    int64_t num;
    struct stat statbuf;
    if(lstat(path, &statbuf) != 0) {
        perror("lstat error \n");
        return -1;
    }

    if (!S_ISDIR(statbuf.st_mode)) {
        return statbuf.st_blocks;
    }

    char nextpath[PATHSIZE];
    glob_t pglob;
    strncpy(nextpath, path, PATHSIZE);
    strncat(nextpath, "/*", PATHSIZE);
    if(glob(nextpath, 0, NULL, &pglob) != 0) {
        perror("glob\n");
        return -1;
    }

    strncpy(nextpath, path, PATHSIZE);
    strncat(nextpath, "/.*", PATHSIZE);
    if(glob(nextpath, GLOB_APPEND, NULL, &pglob) != 0) {
        perror("glob 2 \n");
        return -1;
    }

    num = statbuf.st_blocks;

    for(int i = 0; i < pglob.gl_pathc; i++) {
        if(loop(pglob.gl_pathv[i]))
            num += size(pglob.gl_pathv[i]);
    }

    return num;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "param error!\n");
    }

    printf("%ld\n", size(argv[1])/2);

    return 0;
}


