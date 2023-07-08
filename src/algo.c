/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** algo
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/algo.h"
#include "../includes/compil.h"



int **assign_value(char **arr, int **matrix, int row, int column)
{
    for (int i = 1; i < row; i++)
        matrix[i][0] = arr[i][0];

    for (int j = 0; j < column; j++)
        matrix[1][j] = arr[1][j];

    return matrix;
}

int **assign_value_map(char **arr, int **matrix, int value)
{
    for (int i = 0; i < value; i++)
        matrix[i][0] = arr[i][0];

    for (int j = 0; j < value; j++)
        matrix[0][j] = arr[0][j];

    return matrix;
}

int **get_min(int **matrix, char **arr, int i, int j)
{
    if (arr[i][j] == 1)
        matrix[i][j] = min(matrix[i][j - 1], matrix[i - 1][j],
                            matrix[i -1][j -1]) + 1;
    else
        matrix[i][j] = 0;

    return matrix;
}

int **get_max_values(char **arr, int row, int column)
{

    int **matrix = (int**)malloc((row) * sizeof(int *));

    for (int i = 0; i < row + 1; i++)
        matrix[i] = (int*)malloc((column) * sizeof(int));

    matrix = assign_value(arr, matrix, row, column);

    for (int i = 1; i < row + 1; i++) {
        for (int j = 0; j < column; j++) {
            matrix = get_min(matrix, arr, i, j);
        }
    }
    return matrix;
}

int **get_max_values_map(char **arr, int value)
{

    int **matrix = (int**)malloc((value) * sizeof(int *));

    for (int i = 0; i < value + 1; i++)
        matrix[i] = (int*)malloc((value) * sizeof(int));

    matrix = assign_value_map(arr, matrix, value);

    for (int i = 1; i < value + 1; i++) {
        for (int j = 0; j < value; j++) {
            matrix = get_min(matrix, arr, i, j);
        }
    }
    return matrix;
}
