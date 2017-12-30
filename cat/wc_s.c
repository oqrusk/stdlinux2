#include <stdio.h>
#include <stdlib.h>

static void do_wc(FILE *f);

int
main(int argc, char *argv[])
{
    int i;

    if (argc == 1) {
        do_wc(stdin);
    }
    else{
        for (i = 1; i < argc; i++) {
        FILE *f;
        f = fopen(argv[i], "r");

        if (!f) {
            perror(argv[i]);
            exit(1);
        }
        do_wc(f);
        fclose(f);
        }
    }

    exit(0);
}

static void
do_wc(FILE *f){
    int c;
    unsigned long count = 0;
    while ((c = fgetc(f)) != EOF ) {
        if (c == '\n') {
            count++;
        }        
    }
    printf("%lu\n", count);
}
