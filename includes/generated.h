/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** header
*/

#ifndef __GENERATED_H__
    #define __GENERATED_H__

    void map_generation(char **av, int ac);
    void print_generated_map(int **arr, int value);
    char **init_board(char **arr, char *str, int value);
    char **generation_condition(char **arr, char **av, int i, int j);
    char **transform_map_condition(char **arr, int i, int j);

#endif
