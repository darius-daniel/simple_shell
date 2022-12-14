#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* maximum tokens allowed */
#define MAX_TOKENS 10

char *_strtok(char *BUFFER_STR, const char *delims);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
#endif
