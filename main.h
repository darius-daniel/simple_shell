#ifndef __MAIN_H__
#define __MAIN_H__

#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

/* maximum tokens allowed */
#define MAX_TOKENS 10

char *_strtok(char *BUFFER_STR, const char *delims);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
