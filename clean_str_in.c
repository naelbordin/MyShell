/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** mini shell
*/
#include "a.h"

int while_tab_or_space(char *c, int i)
{
    while (c[i] == '\t' || c[i] == ' ') {
        i++;
    }
    return i;
}

int cpt_strin(char *c)
{
    int i = 0;

    while (c[i] != '\0') {
        if (c[i] == ' ' || c[i] == '\t')
            i = while_tab_or_space(c, i);
        i++;
    }
    return i;
}

char *clean_strin(char *c)
{
    char *res = malloc(sizeof(char) * cpt_strin(c));
    int i = 0;
    int v = 0;

    while (c[i] != '\0') {
        if (c[i] == ' ' || c[i] == '\t') {
            res[v] = ' ';
            i = while_tab_or_space(c, i) - 1;
            v++;
        } else {
            res[v] = c[i];
            v++;
        }
        i++;
    }
    return res;
}
