/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"
#include <errno.h>

struct point *when_is_not_a_ttybis(struct point *st, char **env, __pid_t pid)
{
    st->cmd = space_to_word_array(st->line);
    *st = test_fbis(st, env, st->cmd);
    if (my_strcmp(st->cmd[0], "setenv") != 0 &&
    my_strcmp(st->cmd[0], "cd") != 0
    && my_strcmp(st->cmd[0], "unsetenv") != 0 && my_strcmp(st->cmd[0],
    "exit") != 0)
        *st = test_f(st, pid, st->cmd, env);
    return st;
}

struct point when_is_not_a_tty(struct point *st, char **env, __pid_t pid)
{
    int i = 0;
    char **virg;

    st->read = 0;
    st->line = NULL;
    while (st->read >= 0) {
        st->read = getline(&st->line, &st->bufsize, stdin);
        if (st->read == -1) {
            break;
        }
        i = semicolon_or_not(st->line);
        virg = my_virg_to_word_array(st->line, ";");
        for (int v = 0; v != i; v++) {
            st->line = virg[v];
            st = when_is_not_a_ttybis(st, env, pid);
            env = st->env_maj;
        }
        env = st->env_maj;
    }
    return *st;
}

struct point *when_is_a_ttybis(struct point *st, char **env, __pid_t pid)
{
    st->cmd = space_to_word_array(st->line);
    *st = test_fbis(st, env, st->cmd);
    if (my_strcmp(st->cmd[0], "setenv") != 0 &&
    my_strcmp(st->cmd[0], "cd") != 0 && my_strcmp(st->cmd[0], "unsetenv") != 0
    && my_strcmp(st->cmd[0], "exit") != 0)
        *st = test_f(st, pid, st->cmd, env);
    return st;
}

struct point when_is_a_tty(struct point *st, char **env, __pid_t pid)
{
    char **virg;
    int i = 0;

    if (occ_env(env, "HOME") != -1)
        start(env);
    st->read = getline(&st->line, &st->bufsize, stdin);
    i = semicolon_or_not(st->line);
    virg = my_virg_to_word_array(st->line, ";");
    for (int v = 0; v != i; v++) {
        st->line = virg[v];
        st = when_is_a_ttybis(st, env, pid);
        env = st->env_maj;
    }
    return *st;
}

struct point tty_is_not(struct point *st, char **env, __pid_t pid)
{
    while (1) {
        when_is_a_tty(st, env, pid);
        env = st->env_maj;
        if (isatty(0) != 1) {
            exit(1);
        }
        if (my_strcmp(st->cmd[0], "exit") == 0 || st->read == -1) {
            exit(st->error);
        }
    }
}
