/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** mini shell
*/
#include "../../include/a.h"

int whas_last_letter(char *c, int i)
{
    while (c[i] != '\0') {
        if (c[i] != ' ' && c[i] != '\t')
            return i;
        i++;
    }
    return i;
}

int cpt_torm(char *c)
{
    int i = 0;
    int cpt = 0;

    while (c[i] == ' ' || c[i] == '\t')
        i++;
    while (c[i] != '\0') {
        if (c[whas_last_letter(c, i)] != '\0')
            cpt++;
        i++;
    }
    return cpt;
}

char *clean_space_bandaf(char *c)
{
    int i = 0;
    int a = 0;
    char *res = malloc(sizeof(char) * cpt_torm(c));

    while (c[i] == ' ' || c[i] == '\t')
        i++;
    while (c[i] != '\0') {
        if (c[whas_last_letter(c, i)] != '\0') {
            res[a] = c[i];
            a++;
        }
        i++;
    }
    return res;
}

char **clean_tab(char **c)
{
    char **res = malloc(sizeof(char *) * tab_len(c));
    int i = 0;

    while (i != tab_len(c)) {
        res[i] = clean_space_bandaf(c[i]);
        res[i] = clean_strin(res[i]);
        i++;
    }
    res[i + 1] = NULL;
    return res;
}

char **my_virg_to_word_array2(char *filepath, const char *separator)
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
    return data;
}
