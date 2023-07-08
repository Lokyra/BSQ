/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** header
*/

#ifndef __DISPLAY_H__
    #define __DISPLAY_H__

void display_arr_int(char **arr, int row, int column);
void display_arr_char(char **arr, int row, int column);
void draw_final_map(char **arr, int row, int column);
int get_size(char **av);
int get_lastindex(char *buff, int size);

#endif
