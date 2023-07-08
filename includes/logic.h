/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** header
*/

#ifndef __LOGIC_H__
    #define __LOGIC_H__

    int **assign_char(char **arr, int i, int j);
    int **set_value(int **S, int row, int column);
    int **set_value_map(int **S, int value);
    int **swap_value(int **S, int i, int j);
    void display_char(int **S, int row, int column);
    int **generate_biggest_square(int **S, int row, int column);

#endif
