/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/algo.h"
#include "../includes/compil.h"
#include "../includes/display.h"
#include "../includes/generated.h"
#include "../includes/compil_second.h"

char **transform_map(char **arr, int value)
{
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < value; j++) {
            arr = transform_map_condition(arr, i, j);
        }
    }

    return arr;
}

int **generate_biggest_square_map(int **S, int value)
{
    int max = S[1][0];
    int *pos = malloc(sizeof(int) * 2);
    for (int i = 0; i < value * value; i++) {
        int idx = i / value;
        int col = i % value;
        if (S[idx][col] > max) {
            max = S[idx][col];
            pos[0] = idx;
            pos[1] = col;
        }
    }
    S[pos[0]][pos[1]] = 'x';
    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            S[pos[0] - i][pos[1] - j] = 'x';
            S[pos[0] - j][pos[1] - i] = 'x';
        }
    }
    return S;
}

int **swap_value(int **S, int i, int j)
{
    if (S[i][j] != 0 && S[i][j] != 'x')
        S[i][j] = '.';
    if (S[i][j] == 0)
        S[i][j] = 'o';
    if (S[i][j] == 'x')
        S[i][j] = 'x';

    return S;

}

int **set_value(int **S, int row, int column)
{
    for (int i = 1; i < row + 1; i++) {
        for (int j = 0; j < column - 2; j++) {
            S = swap_value(S, i, j);
        }
    }
    return S;
}

int **set_value_map(int **S, int value)
{
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < value; j++) {
            S = swap_value(S, i, j);
        }
    }
    return S;
}
