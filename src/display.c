/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** display
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/algo.h"
#include "../includes/display.h"
#include "../includes/compil.h"

//
/*
void display_arr_int(char **arr, int row, int column)
{
    for (int i = 1; i < row + 1; i++)
        for (int j = 0; j < column - 2; j++) {
            printf("%d", arr[i][j]);
            if (j == column - 3)
                printf("\n");
        }
}
*/

int get_size(char **av)
{
    struct stat st;
    int size = 0;
    if (stat(av[1], &st) == -1) {
        return 84;
    }
    size = st.st_size;
    return size;

}

int get_lastindex(char *buff, int size)
{
    int tmp = 0;
    int i;
    int last = 0;
    for (i = 0; i < my_strlen(buff); i++) {
        if (buff[i] == '.' || buff[i] == 'o') {
            last = i;
            break;
        }
    }
    while (last < size) {
        if (buff[last] == '\n') {
            tmp = last;
            break;
        }
        last++;
    }
    if (i <= 2)
        return tmp;
    return tmp - i;
}

void display_arr_char(char **arr, int row, int column)
{
    for (int i = 1; i < row + 1; i++)
        for (int j = 0; j < column - 2; j++) {
            my_putchar(arr[i][j]);
            print_backspace(j, column);
        }
}

char **convert_to_final_map(char **arr, int i, int j)
{
    if (arr[i][j] == 9)
        arr[i][j] = 120;

    if (arr[i][j] == 1)
        arr[i][j] = 46;

    if (arr[i][j] == 0)
        arr[i][j] = 111;

    return arr;
}

void draw_final_map(char **arr, int row, int column)
{

    for (int i = 1; i < row + 1; i++) {
        for (int j = 0; j < column; j++) {
            arr = convert_to_final_map(arr, i, j);
        }
    }

    display_arr_char(arr, row, column);
}
