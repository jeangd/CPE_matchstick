/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ia_turn.c
*/

#include <stdlib.h>
#include "include/my.h"

int maj_ia(map_t *map)
{
    int i = map->first;

    for (; map->buffer[map->line_ia][i] !=  '|'; i--);
    for (int j = 0; j != map->nb_ia_rm; j++, i--)
        if (map->buffer[map->line_ia][i] == '|')
            map->buffer[map->line_ia][i] = ' ';
    display_map(map);
    return (0);
}

void ia_turn(map_t *map)
{
    int pipes = 0;
    map->line_ia = rand() % map->line_nb + 1;
    map->nb_ia_rm = rand() % map->matches;

    while (map->line_ia == 0)
        map->line_ia = rand() % map->line_nb + 1;
    pipes = pipes_in_line(map, pipes);
    while (pipes == 0) {
        map->line_ia = rand() % map->line_nb + 1;
        pipes = pipes_in_line(map, pipes);
    }
    while (map->nb_ia_rm > pipes || map->nb_ia_rm == 0)
        map->nb_ia_rm = rand() % map->matches;
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d ", map->nb_ia_rm);
    my_printf("match(es) from line %d\n", map->line_ia);
    maj_ia(map);
}