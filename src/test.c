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
#include "../include/a.h"
#include <errno.h>
#include <signal.h>

int path_or_not_path(char *argv)
{
    int i = 0;

    while (argv[i] != '\0') {
        if (argv[i] == '/') {
            return 84;
        }
        i++;
    }
    return 0;
}

char *path_or_not_pathbis(char *command, char **cmd)
{
    if (path_or_not_path(cmd[0]) == 0) {
        command = str_catb(cmd[0]);
        return command;
    } else {
        command = cmd[0];
        return command;
    }
}

struct point test_fbis(struct point *st, char **env, char **cmd)
{
    if (my_strcmp(cmd[0], "setenv") == 0) {
        env = set_env(env, cmd);
        st->env_maj = env;
        return *st;
    } else if (my_strcmp(cmd[0], "unsetenv") == 0 && cmd[1] != NULL) {
        env = unsatenv(env, cmd[1]);
        st->env_maj = env;
        return *st;
    }
    if (my_strcmp(cmd[0], "cd") != 84 && cmd[0][0] == 'c' &&
    cmd[0][1] == 'd' && cmd[2] == NULL) {
        env = file_go_to_open(cmd, env);
        st->env_maj = env;
        return *st;
    }
    st->env_maj = env;
    return *st;
}

struct point test_f(struct point *st, __pid_t pid, char **cmd, char **env)
{
    char *command;

    command = path_or_not_pathbis(command, cmd);
    pid = fork();
    if (pid == 0) {
        test_f_extansion(st, command, cmd, env);
        exit(st->error);
    } else {
        wait(&st->error);
        if (st->error != 0) {
            st->env_maj = env;
            return *st;
        }
    }
    st->env_maj = env;
    return *st;
}

char *main(int argc, char **argv, char **env)
{
    struct point st;
    __pid_t pid;

    st.error = 0;
    if (env[0] == NULL) {
        exit(84);
    }
    if (isatty(0) != 1) {
        st = when_is_not_a_tty(&st, env, pid);
        env = st.env_maj;
        if (st.error == 139) {
            my_putstr("Segmentation fault\n");
            exit(139);
        }
        if (st.error != 0)
            exit(WIFEXITED(st.error));
        exit(st.error);
    } else {
        st = tty_is_not(&st, env, pid);
    }
}
