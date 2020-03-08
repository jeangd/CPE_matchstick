/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** initial.c
*/

#include <stdlib.h>
#include "include/my.h"

int check_nb(char *nb_one, char *nb_two)
{
    for (int i = 0; i != my_strlen(nb_one); i++)
        if (nb_one[i] < '0' || nb_one[i] > '9')
            return (84);
    for (int i = 0; i != my_strlen(nb_two); i++)
        if (nb_two[i] < '0' || nb_two[i] > '9')
            return (84);
    return (0);
}

int init(map_t *map, char *nb_one, char *nb_two)
{
    if (check_nb(nb_one, nb_two) == 84)
        return (84);
    map->line_nb = my_getnbr(nb_one);
    map->matches = my_getnbr(nb_two);
    map->e = 0;
    map->size = 1;
    map->enter_match = NULL;
    map->line = 0;
    map->error = 0;
    map->first = 1 + (map->line_nb * 2);
    map->buffer = malloc(sizeof(char *) * (map->line_nb + 2));
    if (map->buffer == NULL)
        return (84);
    if (map->line_nb <= 1 || map->line_nb >= 100)
        return (84);
    if (create_map(map) == 84)
        return (84);
    return (0);
}

void free_all(map_t *map)
{
    for (int i = 0; i != (map->line_nb + 2); i++)
        free(map->buffer[i]);
    free(map->buffer);
    free(map->enter_match);
    free(map->enter);
    free(map);
}