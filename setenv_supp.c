/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"
struct point set(struct point *st)
{
    st->bufsize = 0;
}

int supp_verif(char *supp)
{
    for (int i = 0; supp[i] != '\0'; i++) {
        if (supp[i] == '=') {
            return 84;
        }
    }
}

char **unsatenv(char **env, char *supp)
{
    int supp_int;
    char **new_env = malloc(sizeof(char *) * tab_len(env) - 1);
    int n = 0;

    if (supp_verif(supp) == 84) {
        return env;
    }
    supp = my_strcat(supp, "=");
    supp_int = occ_env(env, supp);
    for (int i = 0; env[i] != NULL; i++) {
        if (i == supp_int) {
            n = n - 1;
        }
        if (i != supp_int) {
            new_env[n] = env[i];
        }
        n++;
    }
    new_env[n] = NULL;
    return new_env;
}
