/*
** EPITECH PROJECT, 2022
** minishell 1 header file
** File description:
** minishell1
*/

#ifndef MINISHELl1_H_
    #define MINISHELl1_H_

typedef struct node {
    char *name;
    char *value;
    struct node *next;
} node;

node *init_env(char **env);
void print_list(node **head);
void setenv_function(node **env_l, char **av);
void unsetenv_function(node **env_l, char **av);
char **my_path_to_word_array(char *str);
char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
char *my_strncpy(char *dest , char const *src, int n);
void command_test(char **buf, char **path, char **env);
char *my_strcat(char *dest, char *src);
int line_count(char *src);
char **path_parse(char *src);
char *find_path(char **env);
char *path_concatenate(char **buf, char *pwd);
char *find_old(char **env);
void cd_function(char **buf, char *pwd, char **env);
void my_putstr(char const *str);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int x);
void my_putchar(char c);
int my_arraylen(char **av);

#endif /* !MINISHELl1_H_ */
