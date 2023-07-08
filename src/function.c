/*
** EPITECH PROJECT, 2022
** mini-printf
** File description:
** module function
*/


#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "../includes/compil.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char* str)
{
    while (*str) {
        my_putchar(*str);
        str = str + 1;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0 && nb <= 9) {
        my_putchar(nb + 48);

    } else if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    return 0;
}

int my_strlen(char *str)
{
    int nb = 0;

    while (*str) {
        nb += 1;
        str += 1;
    }
    return nb;
}

int print_backspace(int j, int column)
{
    if (j == column - 3)
        my_putchar('\n');
    return 0;
}
