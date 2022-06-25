/*
** EPITECH PROJECT, 2022
** main file of minishell_1 project.
** File description:
** main
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minishell1.h"

void command_pars_bis(char **path, char **buf, char **env, node **env_l)
{
    if (my_strcmp(buf[0], "env") == 0) {
        print_list(env_l);
        return;
    } else if (my_strcmp(buf[0], "setenv") == 0) {
        if (my_arraylen(buf) < 3) {
            my_putstr("setenv: Too few arguments.\n");
            return;
        }
    } else if (my_strcmp(buf[0], "setenv") == 0) {
        setenv_function(env_l, buf);
        return;
    } else if (my_strcmp(buf[0], "unsetenv") == 0) {
        if (my_arraylen(buf) < 2) {
            my_putstr("unsetenv: Too few arguments.\n");
            return;
        } else {
            unsetenv_function(env_l, buf);
            return;
        }
    } else
        command_test(buf, path, env);
}

void command_pars(char **path, char **buf, char **env, node **env_l)
{
    char pwd[1024];
    getcwd(pwd, sizeof(pwd));

    if (my_strcmp(buf[0], "pwd") == 0) {
        my_putstr(pwd);
        my_putchar('\n');
    } else if (my_strcmp(buf[0], "cd") == 0) {
        if (my_arraylen(buf) > 2) {
            my_putstr("cd: Too many arguments.\n");
            return;
        }
        if (my_arraylen(buf) == 1) {
            my_putstr("cd: No argument given.\n");
            return;
        }
        cd_function(buf, pwd, env);
    } else {
        command_pars_bis(path, buf, env, env_l);
    }
}

char *buffer_init(char *buffer)
{
    buffer[my_strlen(buffer) - 1] = '\0';
    return (buffer);
}

void getprompt()
{
    if (isatty(0) == 0)
        return;
    my_putstr("$> ");
}

int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **env)
{
    node *env_l = init_env(env);
    size_t BUF_SIZE = 512;
    char *buffer = malloc(sizeof(char) * 512);
    char **buf;
    char **path;

    path = path_parse(find_path(env));
    getprompt();
    while (getline(&buffer, &BUF_SIZE, stdin) != -1) {
        buf = my_str_to_word_array(buffer_init(buffer));
        if (my_strcmp(buf[0], "exit") == 0)
            exit(0);
        command_pars(path, buf, env, &env_l);
        getprompt();
    }
    return (0);
}
