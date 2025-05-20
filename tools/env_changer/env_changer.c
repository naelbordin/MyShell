/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "../../include/a.h"


char **set_enva(char **env, char *env_change)
{
    int supp_int;
    char **new_env = malloc(sizeof(char *) * tab_len(env) + 1);
    int n = 0;

    env_change = my_strcat(my_strcat(env_change, "="), "\0");
    supp_int = occ_env(env, env_change);
    for (int i = 0; env[i] != NULL; i++) {
        if (i == supp_int) {
            new_env[n] = env_change;
        }
        if (i != supp_int) {
            new_env[n] = env[i];
        }
        n++;
    }
    return new_env;
}

char **set_envd(char **env, char *env_change, char *env_change2)
{
    int supp_int;
    char **new_env = malloc(sizeof(char *) * tab_len(env) + 2);
    int n = 0;

    env_change = my_strcat(env_change, "=");
    supp_int = occ_env(env, env_change);
    for (int i = 0; env[i] != NULL; i++) {
        if (i == supp_int) {
            new_env[n] = my_strcat(my_strcat(env_change, env_change2), "\0");
        }
        if (i != supp_int) {
            new_env[n] = env[i];
        }
        n++;
    }
    return new_env;
}

char **set_envnew(char **env, char *env_change)
{
    char **new_env = malloc(sizeof(char *) * tab_len(env) *
    my_strlen(env_change));
    int n = 0;

    env_change = my_strcat(my_strcat(env_change, "="), "\0");
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i + 1] != NULL) {
            new_env[n] = env[i];
        } else {
            new_env[n] = env[i];
            new_env[n + 1] = env_change;
        }
        n++;
    }
    new_env[n + 1] = NULL;
    return new_env;
}

char **set_envnew2(char **env, char *env_change, char *env_change2)
{
    char **new_env = malloc(sizeof(char *) * tab_len(env) *
    my_strlen(env_change));
    int n = 0;

    env_change = my_strcat(my_strcat(env_change, "="), "\0");
    for (int i = 0; env[i] != NULL; i++) {
        if (env[i + 1] != NULL) {
            new_env[n] = env[i];
        } else {
            new_env[n] = env[i];
            new_env[n + 1] = my_strcat(env_change, env_change2);
        }
        n++;
    }
    new_env[n + 1] = NULL;
    return new_env;
}

char **set_env(char **env, char **cmd)
{
    if (cmd[1] == NULL){
        print_arg(env);
        return env;
    }
    if (cmd[3] != NULL) {
        my_putstr("setenv: Too many arguments.\n");
        return env;
    } else if (verif_num(cmd[1]) == 84) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return env;
    }
    env = setenvbis(cmd, env);
    return env;
}
