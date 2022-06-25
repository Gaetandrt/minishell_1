/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_strtowordaray
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);

int count_space(char *str)
{
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    return (i);
}

char **str_init(char *str, int cpt, int j, int x)
{
    char **result = malloc(sizeof(char *) * cpt);

    for (int i = 0; i < cpt; i++)
        result[i] = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++) {
        result[j][x] = str[i];
        x++;
        if (str[i + 1] == '\0')
            result[j][x] = '\0';
        else if (str[i] == ' ') {
            result[j][x - 1] = '\0';
            i += count_space(str + i) - 1;
            j++;
            x = 0;
        }
    }
    result[cpt - 1] = NULL;
    return (result);
}

int one_word(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ')
            return (1);
    }
    return (0);
}

char **my_str_to_word_array(char *str)
{
    char **result = malloc(sizeof(char *) * 2);
    int cpt = 2;
    int j = 0;
    int x = 0;

    if (one_word(str) == 0) {
        result[0] = str;
        result[1] = NULL;
        return (result);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != '\t' && str[i + 1] != ' ')
            cpt++;
    }
    return (str_init(str, cpt, j, x));
}
