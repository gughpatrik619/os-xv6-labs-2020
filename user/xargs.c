//
// Created by gughpatrik on 9/25/20.
//

#include "myHeaders.h"

#define BUF_SIZE 512

void readArgsFromPipeIntoBuffer(char *);

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        fprintf(STD_OUT, "Usage: xargs <command> [params, ...]\n");
        exit(1);
    }

//    printArgs(argc, argv);

    char buf[BUF_SIZE];
    readArgsFromPipeIntoBuffer(buf);

    char* bufArgs[16];

    // tokenizing received arguments & storing them in a map
    int mapped = strtok(buf, " \n", bufArgs);

    char *_argv[20];

    // passing args from 'xargs'
    int i;
    for (i = 1; i < argc; ++i)
        _argv[i - 1] = argv[i];

    // passing args from standard input
    for (int j = 0; j < mapped; ++j)
        _argv[i++ - 1] = bufArgs[j];

    int pid = fork();

    if (pid == ERR_FORK) {
        error(FORK_ERR_MSG);
        exit(2);
    }

    // child
    if (pid == PID_CHILD) {
        exec(_argv[0], _argv);

        // error occurred, as 'exec' didn't terminated
        error(EXEC_ERR_MSG);
        exit(3);
    }
        // parent
    else {
        wait(NULL);
    }

    exit(0);
}

void readArgsFromPipeIntoBuffer(char buf[]) {
    char c;
    int r, q = 0;

    while ((r = read(STD_IN, &c, SIZE_CHAR)) != 0 && (c != '\0') && (q < BUF_SIZE - 1)) {
        if (r == ERR_READ) {
            error(READ_ERR_MSG);
            exit(2);
        }
        buf[q++] = c;
    }

    buf[q] = '\0';
}