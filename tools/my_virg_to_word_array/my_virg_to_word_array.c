/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../../include/a.h"
#include <errno.h>

char *sup_last_char(char *c)
{
    char *v = malloc(sizeof(char) * (my_strlen(c)));
    int i = 0;

    for (; c[i + 1] != '\0'; i++)
        v[i] = c[i];
    v[i] = '\0';
    return v;
}

char **virg_cleaner(char **c, char const *separator)
{
    char **new_char = malloc(sizeof(char *) * counter_env(c));
    int i;

    for (i = 0; i < counter_env(c); i++) {
        if (c[i][my_strlen(c[i]) - 1] == separator[0] ||
        c[i][my_strlen(c[i]) - 1] == '\n') {
            new_char[i] = sup_last_char(c[i]);
        } else {
            new_char[i] = c[i];
        }
    }
    return new_char;
}

int counter_lword2(char *c, const char *separator)
{
    int i = 0;

    for (; c[i] != '\0' && c[i + 1] != '\0' &&
    c[i] != separator[0]; i++);
    return i;
}

int counter_ligne2(char *c, const char *separator)
{
    int counteur = 0;

    for (int i = 0; c[i] != '\0'; i++)
        if (c[i + 1] == '\0' || c[i] == separator[0])
            counteur++;
    return counteur;
}

char **my_virg_to_word_array(char *filepath, const char *separator)
{
    int compteur1 = 0;
    int compteur2 = 0;
    int lenw = counter_lword2(filepath, separator);
    int countw = counter_ligne2(filepath, separator);
    char **data = malloc(sizeof(char *) * (countw + 1));

    for (; compteur1 < countw; compteur1++) {
        data[compteur1] = malloc(sizeof(char) * (lenw + 2));
        for (compteur2 = 0; compteur2 < lenw + 1; compteur2++)
            data[compteur1][compteur2] = filepath[compteur2];
        data[compteur1][compteur2] = '\0';
        filepath += lenw + 1;
        lenw = counter_lword2(filepath, separator);
    }
    data[compteur1] = NULL;
    data = virg_cleaner(data, separator);
    data[compteur1] = NULL;
    data = clean_tab(data);
    return data;
}
