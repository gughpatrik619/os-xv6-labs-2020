#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

char buf[512];

void cat(int fd) {
    int n;

    // while there are characters to read...
    while ((n = read(fd, buf, sizeof(buf))) > 0) {

        // if the number of bytes does not equal to the the number read previously (the number of bytes we want to write),
        // write error occurred
        if (write(1, buf, n) != n) {
            // informing the user about error (2: standard error output)
            fprintf(2, "cat: write error\n");
            exit(1);
        }
    }

    // if 'read' returned negative number, read error occurred
    if (n < 0) {
        fprintf(2, "cat: read error\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    int fd, i;

    // if no output file is specified as 2. argument after 'cat', than we're using '0' (standard input)
    if (argc <= 1) {
        cat(0);
        exit(0);
    }

    // iteratinh through the arguments and using them as input to read from
    for (i = 1; i < argc; i++) {
        if ((fd = open(argv[i], 0)) < 0) {
            fprintf(2, "cat: cannot open %s\n", argv[i]);
            exit(1);
        }

        // printing the content of file to standard output (console)
        cat(fd);

        // don't forget to close the file desriptor if not using it anymore
        close(fd);
    }

    // exiting gracefully
    exit(0);
}
