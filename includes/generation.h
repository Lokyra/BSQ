/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** generation.h
*/

#ifndef __GENERATION_H__
    #define __GENERATION_H__

    int **get_map_value(char **arr, int value);
    char **fill_map(char **av, int value);
    int  **generate_biggest_square_map(int **S, int value);
    char **transform_map(char **arr, int value);
    char **convert_generated_map(char **arr, int value);

#endif
