/*
** EPITECH PROJECT, 2022
** function for env command
** File description:
** env_functions
*/

#include "minishell1.h"
#include <stdlib.h>

void unsetenv_function(node **env_l, char **av)
{
    node *tmp = *env_l;
    node *prev = NULL;

    while (tmp != NULL) {
        if (my_strncmp(tmp->name, av[1], my_strlen(av[1])) == 0) {
            if (prev == NULL) {
                *env_l = tmp->next;
                return;
            }
            tmp = prev;
            tmp->next = tmp->next->next;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void setenv_function(node **env_l, char **av)
{
    node *newnode = malloc(sizeof(node));
    newnode->next = NULL;
    newnode->name = my_strcat(av[1], "=");
    newnode->value = av[2];
    node *tmp = *env_l;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = newnode;
}
