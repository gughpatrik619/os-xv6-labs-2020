//
// Created by gughpatrik on 10/22/20.
//
#pragma once // https://docs.microsoft.com/en-us/cpp/preprocessor/once?view=vs-2019

#define bool  _Bool
#define true  1
#define false 0

#define NULL 0

// color codes
#define RED          "\033[0;31m"
#define BOLD_RED     "\033[1;31m"
#define GREEN        "\033[0;32m"
#define BOLD_GREEN   "\033[1;32m"
#define YELLOW       "\033[0;33m"
#define BOLD_YELLOW  "\033[01;33m"
#define BLUE         "\033[0;34m"
#define BOLD_BLUE    "\033[1;34m"
#define MAGENTA      "\033[0;35m"
#define BOLD_MAGENTA "\033[1;35m"
#define CYAN         "\033[0;36m"
#define BOLD_CYAN    "\033[1;36m"
#define COLOR_RESET  "\033[0m"

// debugging functions
#define DEBUG_DATA(type, color)  printf("%s%s | %s | %s/%s:%d |%s ", color, #type, __TIMESTAMP__, __FILE__, __FUNCTION__, __LINE__, COLOR_RESET)

#define LOG(msg, ...)   printf(msg, ##__VA_ARGS__)

#define DEBUG(msg, ...) DEBUG_DATA(DEBUG, YELLOW); LOG(msg, ##__VA_ARGS__)
#define INFO(msg, ...)  DEBUG_DATA(INFO, BLUE);    LOG(msg, ##__VA_ARGS__)
#define ERROR(msg, ...) DEBUG_DATA(ERROR, RED);    LOG(msg, ##__VA_ARGS__)
