/*
** EPITECH PROJECT, 2019
** CPool_Day07_2019
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
    return (str);
}
