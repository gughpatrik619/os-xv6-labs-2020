//
// Created by gughpatrik on 9/24/20.
//

#include "myHeaders.h"

int isDirentEmpty(struct dirent);

void find(char *, char *);

int main(int argc, char *argv[]) {

    if (argc <= 1) {
        fprintf(STD_OUT, "Usage: find <path> <file_1> [file_2, ...]\n");
        exit(1);
    }

    if (argc == 2) {
        find(CUR_DIR, argv[1]);
        exit(1);
    }

    for (int i = 2; i < argc; ++i)
        find(argv[1], argv[i]);

    exit(0);
}

void find(char *path, char *file) {

    char buf[512];
    char *p;
    struct dirent de;
    struct stat st;

    int fd = open(path, 0);

    if (fd == ERR_OPEN) {
        error(OPEN_ERR_MSG);
        exit(1);
    }

    if (fstat(fd, &st) == ERR_STAT) {
        error(STAT_ERR_MSG);
        close(fd);
        exit(2);
    }

    switch (st.type) {
        case T_FILE:
            if (strcmp(basename(path), file) == STR_CMP_SUCCESS)
                fprintf(STD_OUT, "%s\n", path);
            break;

        case T_DIR:
            if (strlen(path) + 1 + DIRSIZ + 1 > sizeof buf) {
                error(PATH_TOO_LONG_ERR_MSG);
                break;
            }

            strcpy(buf, path);
            p = buf + strlen(buf);
            *p++ = '/';

            while (read(fd, &de, sizeof(de)) == sizeof(de)) {
                if (de.inum == 0)
                    continue;

                memmove(p, de.name, DIRSIZ);
                p[DIRSIZ] = 0;

                if (stat(buf, &st) == ERR_STAT) {
                    error(STAT_ERR_MSG);
                    continue;
                }

                // exclude '.' and '..'
                if (strcmp(basename(buf), CUR_DIR) != STR_CMP_SUCCESS
                    && strcmp(basename(buf), PARENT_DIR) != STR_CMP_SUCCESS) {

                    // search through all directory entries
                    find(buf, file);
                }
            }
            break;
    }

    close(fd);
    return;
}





