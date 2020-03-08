/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** loop.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int error_match(map_t *map)
{
    if (map->match_enter < 0 || map->matches < map->match_enter) {
        if (map->error < 1000) {
            my_printf("Error: you cannot remove more than %d ", map->matches);
            my_printf("matches per turn\n");
            map->enter_match = NULL;
            map->error++;
            return (1);
        }
    }
    if (matches_null(map) == 1)
        return (1);
    if (map->match_enter <= 0 || map->matches < map->match_enter) {
        if (map->error >= 1000) {
            my_printf("Error: invalid input (positive number expected)\n");
            map->enter_match = NULL;
            map->error++;
            return (1);
        }
    }
    return (0);
}

int error_line(map_t *map)
{
    if (map->line_enter <= 0 || map->line_enter > map->line_nb) {
        if (map->error < 100) {
            map->enter = NULL;
            my_printf("Error: this line is out of range\n");
            map->error++;
            return (1);
        }
    }
    if (map->line_enter <= 0 || map->line_enter > map->line_nb) {
        if (map->error == 100) {
            map->enter = NULL;
            my_printf("Error: invalid input (positive number expected)\n");
            map->error++;
            return (1);
        }
    }
    return (0);
}

int maj_player(map_t *map)
{
    int i = map->first;

    pipes(map);
    for (; map->buffer[map->line_enter][i] !=  '|'; i--);
    if (map->cmt >= map->match_enter) {
        for (int j = 0; j != map->match_enter; j++, i--)
            if (map->buffer[map->line_enter][i] == '|')
                map->buffer[map->line_enter][i] = ' ';
    } else {
        my_printf("Error: not enough matches on this line\n");
        map->error++;
        return (84);
    }
    display_map(map);
    return (0);
}

int player_turn(map_t *map)
{
    map->enter_match = NULL;
    if (map->enter == NULL)
        if (number_line(map) == 1)
            return (1);
    if (map->enter_match == NULL && map->enter != NULL) {
        my_printf("Matches: ");
        if (getline(&map->enter_match, &map->len, stdin) == -1)
            return (1);
        map->error = 0;
        check_letter_match(map);
        if (map->error == 0)
            map->match_enter = my_getnbr(map->enter_match);
        free(map->enter_match);
        error_match(map);
        if (map->error == 0 && pipes_line_player(map) >= map->match_enter) {
            my_printf("Player removed %d ", map->match_enter);
            my_printf("match(es) from line %d\n", map->line_enter);
        } } if (map->error == 0)
        maj_player(map);
    return (0);
}

int loop(map_t *map)
{
    int play = 0;

    while (map->pipes_nb > 0) {
        if (play == 0 && map->pipes_nb > 0) {
            map->len = 0;
            if (player_turn(map) == 1)
                return (12);
            number_pipes(map);
            if (map->error == 0)
                play++;
        }
        if (play == 1 && map->pipes_nb > 0 && map->error == 0) {
            ia_turn(map);
            number_pipes(map);
            play = 0;
        }
    }
    return (play);
}