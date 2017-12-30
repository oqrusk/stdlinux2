#include <stdio.h>
#include <stdlib.h>

static void do_cat(FILE *f);

int
main(int argc, char *argv[])
{
    int i;

    if (argc == 1) {
        do_cat(stdin);
    }
    else{
        for (i = 1; i < argc; i++) {
        FILE *f;
        f = fopen(argv[i], "r");

        if (!f) {
            perror(argv[i]);
            exit(1);
        }
        do_cat(f);
        fclose(f);
        }
    }

    exit(0);
}

#define BUFFER_SIZE 2048

static void
do_cat(FILE *f){
    int c;
    unsigned char buf[BUFFER_SIZE];

    for(;;){
        size_t n_read = fread(buf, 1, sizeof buf, f);
        size_t n_written = fwrite(buf, 1, n_read, stdout);
        if(n_written<n_read) exit(1);
        if(n_read < sizeof buf) break;
    }
}
