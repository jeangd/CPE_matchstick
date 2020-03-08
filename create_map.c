/*
** EPITECH PROJECT, 2020
** CPS_matchstick_2019
** File description:
** create_map.c
*/

#include "include/my.h"
#include <stdlib.h>

void print_pipes_spaces(map_t *map)
{
    map->i = 1;
    for (map->i = 1; map->middle >= 0; map->i++) {
        map->buffer[map->line][map->i] = ' ';
        map->middle--;
    }
    while (map->e != map->size) {
        map->buffer[map->line][map->i] = '|';
        map->e++;
        map->i++;
    }
    while (map->stock >= 0) {
        map->buffer[map->line][map->i] = ' ';
        map->stock--;
        map->i++;
    }
    map->buffer[map->line][map->i] = '*';
}

int first_line(map_t *map)
{
    int j = 0;

    map->buffer[map->line] = malloc(sizeof(char) * (map->first + 2));
    if (map->buffer[map->line] == NULL)
        return (84);
    for (j = 0; j < map->first; j++)
        map->buffer[map->line][j] = '*';
    map->buffer[map->line][j] = '\0';
    map->line++;
    return (0);
}

int end_line(map_t *map)
{
    int j = 0;

    map->buffer[map->line] = malloc(sizeof(char) * (map->first + 1));
    if (map->buffer[map->line] == NULL)
        return (84);
    for (j = 0; j < map->first; j++)
        map->buffer[map->line][j] = '*';
    map->buffer[map->line][j] = '\0';
    display_map(map);
    return (0);
}

void number_pipes(map_t *map)
{
    map->pipes_nb = 0;
    map->enter = NULL;
    map->enter_match = NULL;
    for (int i = 0; i < map->line_nb + 2; i++)
        for (int j = 0; j < map->size + 2; j++)
            if (map->buffer[i][j] == '|')
                map->pipes_nb++;
}

void display_map(map_t *map)
{
    for (int i = 0; i < map->line_nb + 2; i++) {
        my_printf("%s\n", map->buffer[i]);
    }
}