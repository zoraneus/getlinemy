/*
** EPITECH PROJECT, 2019
** getlinemy
** File description:
** getline
*/

#include "my_getline.h"

static void my_strpush(char **target, char c)
{
    int size = my_strlen(*target);
    char *buffer = malloc(sizeof(char) * (size + 2));

    my_strcpy(buffer, *target);
    buffer[size] = c;
    buffer[size + 1] = '\0';
    free(*target);
    *target = buffer;
}

char *get_next_line(int fd)
{
    int size = 0;
    char c = '\0';
    char *buffer = my_strdup("");

    do {
        size = read(fd, &c, 1);
        if (size == 0) {
            free(buffer);
            return (NULL);
        }
        if (c != '\n')
            my_strpush(&buffer, c);
    } while (c != '\n');
    return (buffer);
}