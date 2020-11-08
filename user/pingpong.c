//
// Created by gughpatrik on 9/24/20.
//

#include "myHeaders.h"

int main(int argc, char* argv[]) {

    // file descriptors for pipe
    int fds[2];

    // message to send around
    const char* MSG = "O";

    // buffer to store the message
    char buf[1];

    // making the pipe
    int p = pipe(fds);

    // controlling if pipe was successful
    if (p == ERR_PIPE) {
        error(PIPE_ERR_MSG);
        exit(1);
    }

    // forking -> creating child process
    int pid = fork();

    // controlling if fork was successful
    if (pid == ERR_FORK) {
        error(FORK_ERR_MSG);
        exit(2);
    }

    // if child process
    if (pid == PID_CHILD) {
        // reading the message sent from parent
        int n = read(fds[0], buf, 1);

        // controlling if read was successful
        if (n == ERR_READ || n != 1) {
            error(READ_ERR_MSG);
            exit(4);
        }

        fprintf(STD_OUT, "%d: received ping\n", getpid());

        close(fds[0]);

        // sending message back to parent
        n = write(fds[1], MSG, 1);

        // controlling if write was successful
        if (n == ERR_WRITE || n != 1) {
            error(WRITE_ERR_MSG);
            exit(3);
        }

        close(fds[1]);
    }
    // else it's parent process
    else {
        // sending message to child
        int n = write(fds[1], MSG, 1);

        // controlling if write was successful
        if (n == ERR_WRITE || n != 1) {
            error(WRITE_ERR_MSG);
            exit(3);
        }

        close(fds[1]);

        // waiting for child process to terminate
        wait(NULL);

        // reading the message sent back from child
        n = read(fds[0], buf, 1);

        // controlling if read was successful
        if (n == ERR_READ || n != 1) {
            error(READ_ERR_MSG);
            exit(4);
        }

        fprintf(STD_OUT, "%d: received pong\n", getpid());

        close(fds[0]);
    }

    exit(0);
}
