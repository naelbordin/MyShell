/*
** EPITECH PROJECT, 2023
** B-PSU-200 : minishell2
** File description:
** bootstrap.h
*/

#ifndef BOOTSTRAP_H
    #define BOOTSTRAP_H
    #include <stdlib.h>
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
int my_putstr3(char *c);
int my_putstr2(char *c);
int my_putstr(char *c);
int my_putchar(char c);
int my_strlen(char *c);
int my_strcmp2(char *s1, char *s2);
int my_strcmp(char const *s1, char const *s2);
int counter_space(char *arg_c);
void print_arg(char **arg);
char *my_strcat(char *c1, char *c2);
int occ_env(char **env, char *search);
int counter_env(char **env);
char *str_catb(char *c);
char **space_to_word_array(char *argv);
char **space_supr(char **argv);
int verif_fich_error(char *fich, int sort);
int tab_len(char **c);
char **set_env2(char **new_env, char *name, char *s);
char **get_env(char **env);
char *env_search(char **env, char *search);
int verifpath(char *c, char *b);
char *strcatv(char *c, char *b);
char **file_go_to_open(char **cmd, char **env);
char *start(char **env);
int free_char(char **c);
int occ_env_bis(int i, int z, char **env, char *search);
char **unsatenv(char **env, char *supp);
char **set_env(char **env, char **cmd);
int supp_verif(char *supp);
int verif_num(char *verif);
char **space_to_word_array2(char *argv);
char *my_strsearch(char *v, int c);
struct point when_is_not_a_tty(struct point *st, char **env, __pid_t pid);
struct point test_f(struct point *st, __pid_t pid, char **cmd, char **env);
struct point when_is_a_tty(struct point *st, char **env, __pid_t pid);
char **setenvbis(char **cmd, char **env);
char **set_envnew2(char **env, char *env_change, char *env_change2);
char **set_envnew(char **env, char *env_change);
char **set_envd(char **env, char *env_change, char *env_change2);
char **set_enva(char **env, char *env_change);
struct point test_fbis(struct point *st, char **env, char **cmd);
struct point tty_is_not(struct point *st, char **env, __pid_t pid);
struct point test_f_extansion(struct point *st, char *command, char **cmd,
    char **env);
int semicolon_or_not(char *c);
char *sup_last_char(char *c);
int counter_lword2(char *c, const char *separator);
int counter_ligne2(char *c, const char *separator);
char **my_virg_to_word_array(char *filepath, const char *separator);
char **clean_tab(char **c);
char **my_virg_to_word_array2(char *filepath, const char *separator);
char **virg_cleaner(char **c, char const *separator);
char *clean_strin(char *c);
typedef struct point {
    char *line;
    ssize_t bufsize;
    ssize_t read;
    char **cmd;
    char **cmdb;
    char **env_maj;
    int error;
} point_t;
#endif /* BOOTSTRAP_H */
