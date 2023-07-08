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
#include "../includes/logic.h"

// print_S(S, row, column);
// create a function that print S

char **char_to_int(char **arr, int row, int column)
{
    for (int i = 1; i < row + 1; i++)
        for (int j = 0; j < column - 2; j++) {
            arr = assign_char(arr, i, j);
        }

    return arr;
}

char **buffer_to_array(char *buff, int row, int column)
{
    int index = 0;
    int n = 0;
    char **arr = malloc(sizeof(char *) * (row + 1));

    for (int i = 1; buff[i] != '\0'; i++) {
        if (buff[i] == '\n') {
            index = 0;
            n++;
            i++;
        }
        if (index == 0)
            arr[n] = malloc(sizeof(char) * (column + 1));
        arr[n][index] = buff[i];
        index++;
    }

    arr[row + 1] = NULL;
    return arr;
}

void bsq(char *buff, char **arr, int row, int column)
{
    arr = buffer_to_array(buff, row, column);
    arr = char_to_int(arr, row, column);
    int **S = get_max_values(arr, row, column);
    S = generate_biggest_square(S, row, column);
    S = set_value(S, row, column);
    display_char(S, row, column);
}

int main(int ac, char **av)
{
    int fd;

    if (ac > 2)
        map_generation(av, ac);
    else {
        fd = open(av[1], O_RDONLY);
        if (fd == -1)
            return 84;
        int error = run_algorithm(av, fd);
        if (error == 84)
            return 84;
        close(fd);
    }
    return 0;
}
