//
// Created by gughpatrik on 9/24/20.
//

#ifndef XV6_LABS_2020_MYFUNCTIONS_H
#define XV6_LABS_2020_MYFUNCTIONS_H

#endif //XV6_LABS_2020_MYFUNCTIONS_H

#include "myConstants.h"

void error(const char *msg) {
    fprintf(STD_ERR_OUT, "ERROR | %s\n", msg);
}

int isDivider(int divider, int of) {
    return of % divider == 0;
}

void printPrime(int p) {
    fprintf(STD_OUT, "prime %d\n", p);
}

void infoLine(int line) {
    fprintf(STD_OUT, "DEBUG | line: %d\n", line);
}

void info(const char *msg) {
    fprintf(STD_OUT, "INFO | %s\n", msg);
}

void debug(const char *msg) {
    fprintf(STD_OUT, "DEBUG | %s\n", msg);
}

char *trim(char *string) {
    char *p;

    // trim from afore
    for (p = string + strlen(string); p >= string && (*p == '\0' || *p == ' '); p--)
        *p = '\0';

    // trim from behind
    for (p = string; *p != '\0' && *p == ' '; p++)
        *p = '\0';

    return p;
}

char *basename(char *path) {
    static char buf[DIRSIZ + 1];
    char *p;

    // Find first character after last slash
    for (p = path + strlen(path); p >= path && *p != '/'; p--);
    p++;

    // Return blank-padded name
    if (strlen(p) >= DIRSIZ)
        return p;

    memmove(buf, p, strlen(p));
    memset(buf + strlen(p), '\0', DIRSIZ - strlen(p));

    return buf;
}

int isDirentEmpty(struct dirent de) {
    return de.inum == 0;
}

void printArgs(int argc, char *argv[]) {
    if (argc)
        for (int i = 0; i < argc; ++i)
            fprintf(STD_OUT, "[%d]: %s\n", i, argv[i]);

    else
        for (int i = 0; argv[i]; ++i)
            fprintf(STD_OUT, "[%d]: %s\n", i, argv[i]);
}

int isCharInString(char c, char *string) {
    for (int i = 0; i < strlen(string); ++i)
        if (c == string[i])
            return 1;

    return 0;
}

int strtok(char *string, char *token, char *buf[]) {

    int b = 0, len = strlen(string);
    for (int i = 0; i < len; ++i) {
        // removing whitespace
        while (i < len && isCharInString(string[i], token))
            string[i++] = '\0';

        if (i == len)
            return b;

        buf[b++] = &string[i];

        while (i < len && !isCharInString(string[i], token))
            i++;

        i--;
    }

    // error
    return -1;
}

