/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../include/a.h"

void print_arg(char **arg)
{
    int i = 0;

    while (*arg) {
        my_putstr(*arg);
        my_putchar('\n');
        arg++;
        i++;
    }
}

int counter_space(char *arg_c)
{
    int b = 0;
    int c = 0;

    for (b; arg_c[b] != '\0'; b++) {
        if (arg_c[b] == ' ') {
            c++;
        }
    }
    return c + 1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;

    if (s1[0] == '\0' || s2[0] == '\0') {
        return 84;
    }
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            j++;
        }
        i++;
    }
    if (i == j) {
        return (0);
    } else {
        return (84);
    }
}

int my_strcmp2(char *s1, char *s2)
{
    int i = 0;
    int j = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        i++;
        if (s1[i] == s2[i]) {
            j++;
        }
    }
    if (i == j) {
        return (0);
    } else {
        return (84);
    }
}

char *my_strcat(char *c1, char *c2)
{
    int len_fin = my_strlen(c1) + my_strlen(c2);
    char *res = (char *)malloc(sizeof(char) * len_fin + 2);
    int i = 0;

    for (i; i <= len_fin; i++) {
        if (i < my_strlen(c1)) {
            res[i] = c1[i];
        } else {
            res[i] = c2[i - my_strlen(c1)];
        }
    }
    res[i] = '\0';
    return res;
}
