/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main.c
*/

#include <stdlib.h>
#include "include/my.h"

int create_map(map_t *map)
{
    int r = -1;

    if (first_line(map) == 84)
        return (84);
    for (; map->line <= map->line_nb; map->line++) {
        map->buffer[map->line] = malloc(sizeof(char) * (map->first + 2));
        if (map->buffer[map->line] == NULL)
            return (84);
        r++;
        map->middle = (map->first / 2) - 2 - r;
        map->stock = map->middle;
        map->buffer[map->line][0] = '*';
        map->size = (map->line * 2) - 1;
        print_pipes_spaces(map);
        map->e = 0;
        map->buffer[map->line][map->i + 1] = '\0';
    }
    if (end_line(map) == 84)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    map_t *map = malloc(sizeof(map_t));
    int win = 0;

    if (ac != 3)
        return (84);
    if (init(map, av[1], av[2]) == 84)
        return (84);
    number_pipes(map);
    win = loop(map);
    free_all(map);
    if (win == 12)
        return (0);
    if (win == 0) {
        my_printf("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else {
        my_printf("You lost, too bad...\n");
        return (2);
    }
}