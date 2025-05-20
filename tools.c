/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int my_strlen(char *c)
{
    int i = 0;

    for (; c[i] != '\0'; i++);
    return i;
}

int my_putchar(char c)
{
    if (c != 0) {
        write(1, &c, 1);
        return 1;
    }
    return 0;
}

int my_putstr(char *c)
{
    int i;

    write(1, c, my_strlen(c));
    return i;
}

int my_putstr2(char *c)
{
    int i;

    write(1, c, (my_strlen(c)- 6));
    return i;
}

int my_putstr3(char *c)
{
    int i = 0;
    char b;

    while (c[i] != '\n') {
        b = c[i];
        my_putchar(b);
        i++;
    }
    return i;
}
