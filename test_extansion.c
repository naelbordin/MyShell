/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** mini shell
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include "a.h"
#include <errno.h>
#include <signal.h>

int semicolon_or_not(char *c)
{
    int cpt = 0;

    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == ';')
            cpt++;
    }
    if (cpt != 0)
        return cpt + 1;
    return 1;
}

struct point test_f_extansion(struct point *st, char *command, char **cmd,
    char **env)
{
    char **path = my_virg_to_word_array2(env_search(env, "PATH="), ":");

    for (int i = 0; path[i] != NULL; i++) {
            execve(my_strcat(my_strcat(path[i], "/"), cmd[0]), &cmd[0], env);
            st->env_maj = env;
    }
    execve(cmd[0], &cmd[0], env);
    if (cmd[0][0] != '\0') {
        my_putstr(cmd[0]);
        my_putstr(": Command not found.\n");
        st->error = 1;
        return *st;
    }
}
