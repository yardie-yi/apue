#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>
#include <crypt.h>
#include <string.h>
#define _GNU_SOURCE
int main(int argc, char **argv)
{
    char *pass = NULL;
    char *pass_crypt = NULL;
    struct spwd *spwd_line;
    if (argc != 2) {
        printf("param error \n");
        exit(1);
    }

    pass = getpass("passwd is :");
    
    spwd_line = getspnam(argv[1]);

    pass_crypt = crypt(pass, spwd_line->sp_pwdp);

    if (strcmp(pass_crypt, spwd_line->sp_pwdp) == 0) {
        printf("R\n");
    } else {
        printf("N\n");
    }
    



    return 0;
}
