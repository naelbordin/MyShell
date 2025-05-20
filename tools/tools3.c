/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../include/a.h"

char **space_supr(char **argv)
{
    for (int z = 0; argv[z] != NULL; z++) {
    }
}

char **space_to_word_array(char *argv)
{
    int i = 0;
    int k = 0;
    int c = 0;
    char **data = malloc(sizeof(char *) * my_strlen(argv) + 2);

    data[0] = malloc(sizeof(char *) * my_strlen(argv) + 1);
    for (i; argv[c] != '\0'; i++){
            data[k][i] = argv[c];
        if (argv[c] == ' '){
            data[k][i] = '\0';
            k++;
            data[k] = malloc(sizeof(char *) * my_strlen(argv) + 1);
            i = -1;
        }
        if (argv[c] == '\n')
            data[k][i] = '\0';
        c++;
    }
    data[k + 1] = NULL;
    return data;
}

char *str_catb(char *c)
{
    char *bin = "/bin/";
    int len_fin = my_strlen(bin) + my_strlen(c) + 1;
    char *res = (char *)malloc(sizeof(char) * len_fin);

    for (int i = 0; i != len_fin; i++) {
        if (i < my_strlen(bin)) {
            res[i] = bin[i];
        } else {
            res[i] = c[i - my_strlen(bin)];
        }
        if (i > my_strlen(bin) && c[i - my_strlen(bin)] == '\n') {
            res[i] = '\0';
        }
    }
    return res;
}

int counter_env(char **env)
{
    int i = 0;

    for (i; env[i] != NULL; i++) {
    }
    return i;
}

int occ_env(char **env, char *search)
{
    int c = my_strlen(search);
    int i = 0;
    int verif = 0;
    int verif2 = 0;

    for (i; env[i] != NULL; i++) {
        for (int z = 0; search[z] != '\0'; z++) {
        verif = verif + occ_env_bis(i, z, env, search);
        }
        if (verif == my_strlen(search)) {
            verif2 = 1;
            break;
        }
        verif = 0;
    }
    if (verif2 == 1) {
        return i;
    } else {
        return -1;
    }
}
