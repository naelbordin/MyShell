/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../include/a.h"

char *my_strsearch(char *v, int c)
{
    char *d;

    for (int i = 0; v[i] != '\0'; i++) {
        if (v[i] == c) {
            d = c + "";
            return d;
        }
    }
}

int verif_num_bis(char c, char b)
{
    if (c == b) {
        return 84;
    }
    return 0;
}

int verif_num(char *verif)
{
    char *verificator = "0123456789";
    int verifs = 0;

    for (int i = 0; verif[i] != '\0' && verifs != 84; i++) {
        for (int p = 0; verificator[p] != '\0' && verifs != 84; p++) {
            verifs = verif_num_bis(verif[i], verificator[p]);
        }
    }
    if (verifs == 84) {
        return 84;
    } else {
        return 0;
    }
}

int occ_env_bis(int i, int z, char **env, char *search)
{
    if (env[i][z] == search[z]) {
        return 1;
    } else {
        return 0;
    }
}
