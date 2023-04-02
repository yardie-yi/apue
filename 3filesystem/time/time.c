#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#define PATH "/tmp/out"
#define BUFSIZE 1024

int main()
{
    time_t t;
    struct tm *time_t = NULL;
    char data[BUFSIZE];
    int count  = 0;
    FILE *fp = NULL;
    fp = fopen(PATH, "a+");
    if (fp == NULL) {
        perror("fopen\n");
        exit(1);
    }

    while(fgets(data, BUFSIZE, fp) != NULL)
            count ++;

    while(1) {
        time(&t);
        time_t = localtime(&t);
        fprintf(fp, "%d : %d-%d-%d %d-%d-%d\n", count++, time_t->tm_year+1900, time_t->tm_mon+1, time_t->tm_mday, time_t->tm_hour, time_t->tm_min, time_t->tm_sec);
        sleep(1);
        fflush(fp);
    }
    fclose(fp);

    return 0;
}
