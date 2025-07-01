#ifndef READ_INPUT_H
#define READ_INPUT_H

#include <stdio.h>
#include <stddef.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#endif