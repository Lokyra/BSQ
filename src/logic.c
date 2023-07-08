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
#include "../includes/compil.h"
#include "../includes/display.h"


char **assign_char(char **arr, int i, int j)
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

void display_char(int **arr, int row, int column)
{
    for (int i = 1; i < row + 1; i++) {
        for (int j = 0; j < column - 2; j++) {
            my_putchar(arr[i][j]);
        }
        my_putchar('\n');
    }
}

int **draw_square(int **S, int max, int *pos)
{
    S[pos[0]][pos[1]] = 'x';
    for (int i = 1; i < max; i++) {
        for (int j = 0; j < max; j++) {
            S[pos[0] - i][pos[1] - j] = 'x';
            S[pos[0] - j][pos[1] - i] = 'x';
        }
    }
    return S;
}

int **generate_biggest_square(int **S, int row, int column)
{
    int max = S[1][0];
    int *pos = malloc(sizeof(int) * 2);
    for (int i = 1; i < row * column; i++) {
        int idx = i / column;
        int col = i % column;
        if (S[idx][col] > max) {
            max = S[idx][col];
            pos[0] = idx;
            pos[1] = col;
        }
        if (S[idx][col] == max && col < pos[1]) {
            pos[0] = idx;
            pos[1] = col;
        }
    }
    S = draw_square(S, max, pos);
    return S;
}
