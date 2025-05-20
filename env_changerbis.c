/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"

char **setenvbis2(char **env, char **cmd)
{
    if (cmd[1] != NULL && cmd[2] == NULL &&
        occ_env(env, my_strcat(cmd[1], "=")) == -1) {
        env = set_envnew(env, cmd[1]);
        return env;
    }
    if (cmd[1] != NULL && cmd[2] != NULL &&
        occ_env(env, my_strcat(cmd[1], "=")) == -1) {
        env = set_envnew2(env, cmd[1], cmd[2]);
        return env;
    }
    return env;
}

char **setenvbis(char **cmd, char **env)
{
    if (supp_verif(cmd[1]) == 84) {
        return env;
    } else if (cmd[1] != NULL && cmd[2] == NULL &&
        occ_env(env, my_strcat(cmd[1], "=")) != -1) {
        env = set_enva(env, cmd[1]);
        return env;
    }
    if (cmd[1] != NULL & cmd[2] != NULL &&
        occ_env(env, my_strcat(cmd[1], "=")) != -1) {
        env = set_envd(env, cmd[1], cmd[2]);
        return env;
    }
    env = setenvbis2(env, cmd);
    return env;
}
