#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glob.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \t\n"

glob_t globres;

static void prompt(void)
{
    printf("myshell $ ");
}

static void parse(char *line)
{
    char *tok;
    int i = 0;
    while(1) {
        tok = strsep(&line, DELIM);
        if (tok == NULL) {
            break;
        }
        if (tok[0] == '\0') {
            continue;
        }
        
        glob(tok, GLOB_NOCHECK|GLOB_APPEND*i, NULL, &globres);
        i = 1;
    }
}

int main()
{
    char *linebuf = NULL;
    size_t size = 0;

    pid_t pid;

    while(1) {
        prompt();
        if(getline(&linebuf, &size, stdin) < 0) {
            break;
        }
        parse(linebuf);
        fflush(NULL);
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            if(execvp(globres.gl_pathv[0], globres.gl_pathv) < 0) {
                perror("execvp");
                exit(1);
            }

        }
        if (pid > 0) {
            wait(NULL);
        }

    }
    exit(0);
}
