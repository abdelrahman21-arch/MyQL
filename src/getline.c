#include "include/read_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream)
{
    if (lineptr == NULL || n == NULL || stream == NULL)
    {
        return -1;
    }
    size_t position = 0;
    int c;
}