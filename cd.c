/*
** EPITECH PROJECT, 2024
** star.c
** File description:
** make a star
*/
#include "a.h"

char **cd1(char **cmd, char **new_env, char **env)
{
    char *cwd2;
    char *cwd = getcwd(NULL, 0);
    int verif;
    char *cpt[] = {"DOG", "OLDPWD", cwd};
    char **cpt2 = malloc((3 + 1) * sizeof(char *));

    new_env = get_env(env);
    verif = chdir(cmd[1]);
    verif_fich_error(cmd[1], verif);
    cwd2 = getcwd(NULL, 0);
    cpt2[1] = "PWD";
    cpt2[2] = cwd2;
    cpt2[3] = NULL;
    new_env = setenvbis(cpt, new_env);
    new_env = setenvbis(cpt2, new_env);
    return new_env;
}

char **cd22(char *cwd2)
{
    char **cpt2 = malloc((3 + 1) * sizeof(char *));

    cpt2[1] = "PWD";
    cpt2[2] = cwd2;
    cpt2[3] = NULL;
    return cpt2;
}

char **cd2(char **cmd, char **new_env, char **env)
{
    char *cwd2;
    char *cwd = getcwd(NULL, 0);
    int verif;
    char *p;
    char *cpt[] = {"DOG", "OLDPWD", cwd};
    char **cpt2;

    new_env = get_env(env);
    if (occ_env(env, "OLDPWD=") != -1) {
        p = env_search(env, "OLDPWD=");
        verif = chdir(p);
        verif_fich_error(p, verif);
        cwd2 = getcwd(NULL, 0);
        cpt2 = cd22(cwd2);
        my_putstr(my_strcat(cwd2, "\n"));
        new_env = setenvbis(cpt, new_env);
        new_env = setenvbis(cpt2, new_env);
        return new_env;
    }
    return new_env;
}

char **cd3(char **new_env, char **env)
{
    char *cwd2;
    char *cwd;
    int verif;
    char *cpt[] = {"DOG", "OLDPWD", cwd};
    char **cpt2 = malloc((3 + 1) * sizeof(char *));

    cwd = getcwd(NULL, 0);
    new_env = get_env(env);
    verif = chdir(env_search(env, "HOME="));
    verif_fich_error(env_search(env, "HOME="), verif);
    cwd2 = getcwd(NULL, 0);
    return new_env;
}

char **file_go_to_open(char **cmd, char **env)
{
    char **new_env;

    if (my_strcmp(cmd[0], "cd") != 84 && cmd[1] == NULL || cmd[1][0] == '~') {
        new_env = cd3(new_env, env);
        return new_env;
    }
    if (cmd[1][0] != '-' && cmd[1][0] != '~') {
        new_env = cd1(cmd, new_env, env);
    }
    if (my_strcmp(cmd[1], "-") == 0 && cmd[1][0] == '-') {
        new_env = cd2(cmd, new_env, env);
    }
    if (new_env != NULL) {
        return new_env;
    } else {
        return env;
    }
}
