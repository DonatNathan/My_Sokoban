/*
** EPITECH PROJECT, 2022
** SOKOBAN
** File description:
** It's the .h of my sokoban
*/

#ifndef SOKOBAN_H_
    #define SOKOBAN_H_

    #include "my.h"
    #include <stdlib.h>
    #include <curses.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <locale.h>
    #include <sys/ioctl.h>

typedef struct char_map {
    int cmpt_x;
    int cmpt_o;
    int cmpt_p;
    int cmpt_return;
} char_map;

typedef struct positions {
    int *cible;
    int *player;
    int *obstacle;
    char **map;
    int *pos_end;
    int *pos_caisse;
    int what_is;
    int change;
    int in_o;
    char **copy_map;
    char **pos_o;
    char *line;
    char *chara;
} positions;

char *get_map(char **argv, struct stat *my_file);
int launch_game(char **map, int stop);
int draw_all(positions *pos_map, int my_char);
void replace_o(positions *pos_map);
void o_gestion(positions *pos_map);
int check_defeat(positions *pos_map);
int check_end(char **map);
void reset_line_chara(positions *pos_map);
void get_line_chara(positions *pos_map, char *pos_o);
int check_pos_p(positions *pos_map);
int get_height(char *map);
int get_o(positions *pos_map, int cmpt_o, int line);
void stock_o(positions *pos_map);
void test_stop(positions *pos_map, int stop);
int get_o_little(positions *pos_map, int cmpt, int nb_o);
void restart_map(positions *pos_map);
void is_p(positions *pos_map, int line);

#endif /* SOKOBAN_H_ */
