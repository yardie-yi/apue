#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

int main()
{
    char time_buf[SIZE];
    time_t now_time_t;
    struct tm *now_time_st;

    now_time_t = time(NULL);

    now_time_st = localtime(&now_time_t);
    
    strftime(time_buf, SIZE, "NOW: %Y-%m-%d", now_time_st);
    puts(time_buf);
    now_time_st->tm_mday += 100;
    (void)mktime(now_time_st);
    strftime(time_buf, SIZE, "NOW: %Y-%m-%d", now_time_st);
    puts(time_buf);


    return 0;
}
