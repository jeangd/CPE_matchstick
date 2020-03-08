/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** player.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int check_letter_line(map_t *map)
{
    for (int i = 0; i != my_strlen(map->enter) - 1; i++) {
        if (map->enter[i] < '0' || map->enter[i] > '9') {
            map->enter_match = NULL;
            map->error += 100;
            return (84);
        }
    }
    return (0);
}

int check_letter_match(map_t *map)
{
    for (int i = 0; i != my_strlen(map->enter_match) - 1; i++) {
        if (map->enter_match[i] < '0' || map->enter_match[i] > '9') {
            map->enter = NULL;
            map->error += 1000;
            return (84);
        }
    }
    return (0);
}

int number_line(map_t *map)
{
    if (map->enter_match == NULL && map->error == 0)
            my_printf("\nYour turn:\n");
        map->error = 0;
        my_printf("Line: ");
        if (getline(&map->enter, &map->len, stdin) == -1)
            return (1);
        check_letter_line(map);
        if (map->error == 0)
            map->line_enter = my_getnbr(map->enter);
        map->error = error_line(map);
    return (0);
}

int pipes_in_line(map_t *map, int pipes)
{
    for (int j = 0; j < map->size + 2; j++)
        if (map->buffer[map->line_ia][j] == '|')
            pipes++;
    return (pipes);
}

void pipes(map_t *map)
{
    int z = 0;
    map->cmt = 0;

    for (; z != map->first; z++)
        if (map->buffer[map->line_enter][z] ==  '|')
            map->cmt++;
}