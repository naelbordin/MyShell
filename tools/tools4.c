/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../include/a.h"

char *env_search(char **env, char *search)
{
    int c = occ_env(env, search);
    int len_debut = my_strlen(search);
    int len_fin = my_strlen(env[c]);
    char *res = (char *)malloc(sizeof(char) * (len_fin - len_debut));

    for (int i = len_debut; i != len_fin; i++) {
        res[i - len_debut] = env[c][i];
    }
    return res;
}

char **get_env(char **env)
{
    int i = 0;
    char **c = malloc(sizeof(char *) * counter_env(env) + 1);

    for (i; i != counter_env(env) + 1; i++) {
        if (i != counter_env(env)) {
            c[i] = (char *)malloc(sizeof(char) * my_strlen(env[i]));
            c[i] = env[i];
        }
        if (i == counter_env(env) + 1) {
            c[i + 1] = NULL;
        }
    }
    return c;
}

char **set_env2(char **new_env, char *name, char *s)
{
    int c = occ_env(new_env, s);

    new_env[c] = (char *)malloc(sizeof(char) * my_strlen(name));
    new_env[c] = name;
    return new_env;
}

int tab_len(char **c)
{
    int i = 0;
    int b = 0;

    for (i; c[i] != NULL; i++) {
        b++;
    }
    if (b == 0) {
        i = 1;
    }
    return i;
}

int verif_fich_error(char *fich, int sort)
{
    if (sort == -1) {
        my_putstr("bash: cd: ");
        perror(fich);
    }
}
