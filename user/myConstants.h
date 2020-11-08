//
// Created by gughpatrik on 9/24/20.
//

#ifndef XV6_LABS_2020_MYCONSTANTS_H
#define XV6_LABS_2020_MYCONSTANTS_H

#endif //XV6_LABS_2020_MYCONSTANTS_H


#define ERR_OPEN   -1
#define ERR_CLOSE  -1
#define ERR_READ   -1
#define ERR_WRITE  -1
#define ERR_FORK   -1
#define ERR_PIPE   -1
#define ERR_DUP    -1
#define ERR_STAT   -1

#define STR_CMP_SUCCESS 0

#define OPEN_ERR_MSG          "Open error"
#define CLOSE_ERR_MSG         "Close error"
#define READ_ERR_MSG          "Read error"
#define WRITE_ERR_MSG         "Write error"
#define FORK_ERR_MSG          "Fork error"
#define PIPE_ERR_MSG          "Pipe error"
#define DUP_ERR_MSG           "Dup error"
#define STAT_ERR_MSG          "Stat error"
#define PATH_TOO_LONG_ERR_MSG "Path too long"
#define EXEC_ERR_MSG          "Exec error"

#define STD_IN      0
#define STD_OUT     1
#define STD_ERR_OUT 2

#define PID_CHILD   0

#define NULL        0

#define CUR_DIR    "."
#define PARENT_DIR ".."

#define SIZE_INT  sizeof(int)
#define SIZE_CHAR sizeof(char)

#define SH_STR_DELIM " \n\r\t\a"

typedef struct {
    char entry[50];
} Map;
