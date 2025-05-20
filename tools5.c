/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"

char *strcatv(char *c, char *b)
{
    int i = my_strlen(c);
    char *v = (char *)malloc(sizeof(char) * (my_strlen(b) - i + 1));

    while (i != my_strlen(b)) {
        v[i - my_strlen(c)] = b[i];
        i++;
    }
    return v;
}

int verifpath(char *c, char *b)
{
    int t = 0;

    for (int i = 0; i != my_strlen(c); i++) {
        if (c[i] == b[i]) {
            t++;
        }
    }
    if (t == my_strlen(b)) {
        return 0;
    }
}

int *start_bis(char *buff, char *c, char **env)
{
    c = my_strcat(my_strcat("\033[1;38;2;35;209;139m",
        env_search(env, "LOGNAME=")), "\033[139m");
        my_putstr2(c);
        my_putstr("@");
        my_putstr3(buff);
        my_putstr(my_strcat("\033[0m", ":"));
}

char *start(char **env)
{
    char *c;
    char *cwd;
    int fich = open("/etc/hostname", O_RDONLY);
    char *buff = (char *)malloc(sizeof(char) * 100);

    cwd = getcwd(NULL, 0);
    read(fich, buff, 100);
    start_bis(buff, c, env);
    if (my_strcmp(cwd, "/home") == 84 && my_strcmp(cwd, "/") == 84 &&
    verifpath(cwd, "/home") == 0) {
        my_putstr(my_strcat("\033[1;38;2;59;142;234m", "~"));
        my_putstr(my_strcat("\033[1;38;2;59;142;234m",
        strcatv(env_search(env, "HOME="), cwd)));
        my_putstr("\033[0m$ \0");
    } else {
        my_putstr(my_strcat("\033[1;38;2;59;142;234m", cwd));
        my_putstr("\033[0m$ ");
    }
    free(buff);
}

int free_char(char **c)
{
    for (int i = 0; c[i] != NULL; i++) {
        free(c[i]);
    }
    free(c);
}
