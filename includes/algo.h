/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** hedear
*/

#ifndef __ALGO_H__
    #define __ALGO_H__


int **assign_value(char **arr, int **S, int row, int column);
int **assign_value_map(char **arr, int **S, int value);
int **get_max_values(char **arr, int row, int column);
int **get_max_values_map(char **arr, int value);
char **find_biggest_square(int **S, char **arr, int row, int column);
int min(int a, int b, int c);

#endif
