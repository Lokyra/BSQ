/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** generated.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/compil.h"
#include "../includes/algo.h"
#include "../includes/display.h"
#include "../includes/generation.h"
#include "../includes/generated.h"
#include "../includes/logic.h"



char **transform_map_condition(char **arr, int i, int j)
{

    if (arr[i][j] == '.') {
        arr[i][j] = 1 + '0';
        arr[i][j] = arr[i][j] - '0';
    }

    if (arr[i][j] == 'o') {
        arr[i][j] = 0 + '0';
        arr[i][j] = arr[i][j] - '0';
    }

    return arr;
}

void print_generated_map(int **arr, int value)
{
    for (int i = 0; i < value; i++) {
        for (int j = 0; j < value; j++) {
            my_putchar(arr[i][j]);
        }
        printf("\n");
    }
}

int resest_index(int idx, char *pat)
{
    if (idx == my_strlen(pat))
        idx = 0;

    return idx;
}

char **init_board(char **av, char *str, int value)
{
    int idx = 0;
    char *pat = malloc(sizeof(char) * 100);
    pat = av[2];
    char **arr = malloc(sizeof(char *) * value);
    for (int i = 0; i < value + 1; i++)
        arr[i] = malloc(sizeof(char) * value);

    for (int i = 0; i < value; i++) {
        for (int j = 0; j < value; j++) {
            arr[i][j] = pat[idx];
            idx++;
            idx = resest_index(idx, pat);
        }
    }

    return arr;
}

void map_generation(char **av, int ac)
{
    char *str = malloc(sizeof(char) * 100);
    str = av[1];
    int value = my_getnbr(str);
    char **arr = init_board(av, str, value);
    arr = transform_map(arr, value);
    int **S = get_max_values_map(arr, value);
    S = generate_biggest_square_map(S, value);
    S = set_value_map(S, value);
    print_generated_map(S, value);
}
