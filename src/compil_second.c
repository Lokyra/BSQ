/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** header
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

int **get_map_value_condition(int **matrix, char **arr, int i, int j)
{
    if (arr[i][j] == 1)
        matrix[i][j] = min(matrix[i][j - 1], matrix[i - 1][j],
                            matrix[i -1][j -1]) + 1;
    else
        matrix[i][j] = 0;

    return matrix;
}

int min(int vertical, int horizontal, int diagonal)
{
    int max = vertical;

    if (max > horizontal)
        max = horizontal;

    if (max > diagonal)
        max = diagonal;

    return max;
}

int get_size_number(int nb)
{
    int size = 0;

    while (nb > 0) {
        nb = nb / 10;
        size++;
    }
    return size;
}

int check_map(char *buff, int nb)
{
    int len = my_strlen(buff);

    if (nb == 0)
        return 84;

    if (len == 0)
        return 84;

    return 0;
}

int run_algorithm(char **av, int fd)
{
    char *buff;
    char **arr;
    int size = get_size(av);
    buff = map_to_buffer(av, fd, size);
    int n = get_lastindex(buff, size);
    int nb = my_getnbr(buff);

    if (check_map(buff, nb) == 84)
        return 84;

    bsq(buff, arr, nb, n);

    return 0;
}
