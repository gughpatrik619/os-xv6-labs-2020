//
// Created by gughpatrik on 9/24/20.
//

#include "myHeaders.h"

void sieve(int);

int main(int argc, char *argv[]) {

    int fds[2];

    if (pipe(fds) == ERR_PIPE) {
        error(PIPE_ERR_MSG);
        exit(1);
    }

    int pid = fork();

    if (pid == ERR_FORK) {
        error(FORK_ERR_MSG);
        exit(2);
    }

    // child
    if (pid == PID_CHILD) {
        close(fds[1]);
        sieve(fds[0]);
    }
        // parent
    else {
        close(fds[0]);

        for (int i = 2; i <= 35; ++i) {
            write(fds[1], &i, SIZE_INT);
        }

        close(fds[1]);

        wait(NULL);
    }

    exit(0);
}

void sieve(int fd) {
    int prime;

    int r = read(fd, &prime, SIZE_INT);

    // if error occurred
    if (r == ERR_READ) {
        error(READ_ERR_MSG);
        exit(1);
    }

    // if no bytes received -> end of data stream
    if (r == 0) {
        exit(0);
    }

    // printing prime
    printPrime(prime);


    // next sieve
    int fds[2];

    if (pipe(fds) == ERR_PIPE) {
        error(PIPE_ERR_MSG);
        exit(2);
    }

    int pid = fork();

    if (pid == ERR_FORK) {
        error(FORK_ERR_MSG);
        exit(3);
    }

    // child
    if (pid == PID_CHILD) {
        close(fds[1]);
        sieve(fds[0]);
    }
        // parent
    else {
        close(fds[0]);

        int n;

        while ((r = read(fd, &n, SIZE_INT)) != 0) {
            if (r == ERR_READ) {
                error(READ_ERR_MSG);
                exit(4);
            }

            if (!isDivider(prime, n)) {
                write(fds[1], &n, SIZE_INT);
            }
        }

        close(fd);
        close(fds[1]);

        wait(NULL);
    }

    exit(0);
}
