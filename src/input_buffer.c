#include <stdio.h>
#include <stdlib.h>
#include "include/input_buffer.h"

InputBuffer *new_input_buffer()
{
    InputBuffer *input_buffer = (InputBuffer *)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;
    return input_buffer;
}

void print_prompt()
{
    printf("db > ");
}

void read_input(InputBuffer *input_buffer)
{
    ssize_t bytes_read = getline(&input_buffer->buffer, &input_buffer->buffer_length, stdin);
    if (bytes_read <= 0)
    {
        perror("Error reading input");
        exit(EXIT_FAILURE);
    }
    input_buffer->input_length = bytes_read;

    // Remove trailing newline character
    if (input_buffer->buffer[bytes_read - 1] == '\n')
    {
        input_buffer->buffer[bytes_read - 1] = '\0';
        input_buffer->input_length--;
    }
}

void flush_input_buffer(InputBuffer *input_buffer)
{
    if (input_buffer->buffer != NULL)
    {
        free(input_buffer->buffer);
        free(input_buffer);
        input_buffer = NULL;
    }
}