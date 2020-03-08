/*
** EPITECH PROJECT, 2020
** nb_pipes.c
** File description:
** nb_pipes.c
*/

#include "include/my.h"

int pipes_line_player(map_t *map)
{
    int pipes = 0;

    for (int j = 0; j < map->size + 2; j++)
        if (map->buffer[map->line_enter][j] == '|')
            pipes++;
    return (pipes);
}

int matches_null(map_t *map)
{
    if (map->match_enter == 0) {
        if (map->error < 1000) {
            my_printf("Error: you have to remove at least one match\n");
            map->enter_match = NULL;
            map->error++;
            return (1);
        }
    }
    return (0);
}