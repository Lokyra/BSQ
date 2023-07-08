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

int set_negative(char *buff, int negative, int i)
{
    if (buff[i] == 45)
        negative *= (-1);

    return negative;
}

int nbr_condition(char *buff, int number, int i)
{
    if (buff[i] >= 48 && buff[i] <= 57)
        number = number * 10 + (buff[i] - 48);

    return number;
}

int my_getnbr(char const *buff)
{
    long number = 0;
    int negative = 1;

    for (int i = 0; buff[i] != '\0'; i++) {

        negative = set_negative(buff, negative, i);

        if ((buff[i] >= 48 && buff[i] <= 57) &&
        (buff[i + 1] < 48 || buff[i + 1] > 57)) {
            number = number * 10 + (buff[i] - 48);
            break;
        }
        number = nbr_condition(buff, number, i);

        if (number < -2147483648 || number > 2147483647)
            return 0;
    }

    return number * negative;
}

char *map_to_buffer(char **av, int fd, int size)
{
    char *buff = malloc(sizeof(char) * size);

    read(fd, buff, size);

    return buff;
}
