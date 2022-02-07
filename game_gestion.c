/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the file that contain functions to launch my game
*/

#include "includes/sokoban.h"

void check_inversion(positions *pos_map)
{
    pos_map->in_o = 2;
    pos_map->change = 0;
    check_inversion2(pos_map);
    if (pos_map->map[pos_map->cible] == 'X' && pos_map->map\
[pos_map->obstacle] != '#' && pos_map->map[pos_map->obstacle] != 'X') {
        if (pos_map->map[pos_map->obstacle] == 'O') {
            pos_map->in_o = 1;
            pos_map->change = 1;
        }
        pos_map->map[pos_map->cible] = pos_map->map[pos_map->player];
        pos_map->map[pos_map->player] = ' ';
        pos_map->map[pos_map->obstacle] = 'X';
    }
    replace_o(pos_map);
    o_gestion(pos_map);
}

void move_p(int my_char, positions *pos_map, int size_line)
{
    for (pos_map->player = 1; pos_map->map[pos_map->player] != 'P'; \
         pos_map->player += 1);
    if (my_char == KEY_LEFT) {
        pos_map->cible = pos_map->player - 1;
        pos_map->obstacle = pos_map->player - 2;
        check_inversion(pos_map);
    } if (my_char == KEY_RIGHT) {
        pos_map->cible = pos_map->player + 1;
        pos_map->obstacle = pos_map->player + 2;
        check_inversion(pos_map);
    } if (my_char == KEY_UP) {
        pos_map->cible = pos_map->player - size_line;
        pos_map->obstacle = pos_map->player - 2 * size_line;
        check_inversion(pos_map);
    } if (my_char == KEY_DOWN) {
        pos_map->cible = pos_map->player + size_line;
        pos_map->obstacle = pos_map->player + 2 * size_line;
        check_inversion(pos_map);
    }
}

void init_struct(positions *pos_map, char *map)
{
    pos_map->copy_map = malloc(sizeof(char *) * 100);
    for (int cmpt = 0; map[cmpt] != '\0'; cmpt += 1)
        pos_map->copy_map[cmpt] = map[cmpt];
    pos_map->map = map;
    pos_map->pos_end = -1;
    pos_map->pos_caisse = -1;
    for (pos_map->size_line = 0; map[pos_map->size_line] != '\n'; \
         pos_map->size_line += 1);
}

int draw_all(positions *pos_map, int my_char, int stop)
{
    if (my_char == ' ') {
        for (int cmpt = 0; pos_map->map[cmpt] != '\0'; cmpt += 1)
            pos_map->map[cmpt] = pos_map->copy_map[cmpt];
    } else
        move_p(my_char, pos_map, pos_map->size_line + 1);
    if (check_end(pos_map->map) == 0 && pos_map->pos_end == -1)
        stop = 0;
    else if (check_defeat(pos_map, pos_map->size_line) == 0)
        stop = 1;
    return (stop);
}

int launch_game(char *map)
{
    WINDOW *win = initscr();
    int stop = 2;
    int my_char;
    positions *pos_map = malloc(sizeof(positions));

    init_struct(pos_map, map);
    while (stop == 2) {
        keypad(stdscr, TRUE);
        test_size(map);
        refresh();
        my_char = getch();
        stop = draw_all(pos_map, my_char, stop);
        clear();
    }
    endwin();
    return (stop);
}
