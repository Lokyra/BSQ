/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/algo.h"
#include "../includes/display.h"

int **char_to_int2(char **arr, int row, int column)
{
    for (int i = 0; i < row + 1; i++)
        for (int j = 0; j < column - 2; j++) {
            arr = assign_char(arr, i, j);
        }

    return arr;
}
