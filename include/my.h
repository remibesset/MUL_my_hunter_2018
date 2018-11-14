/*
** EPITECH PROJECT, 2018
** my
** File description:
** .h
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <SFML/Graphics.h>

void my_putchar(char c);
int my_strlen(char const *str);
const char *my_revstr(const char *str);
int get_the_sign(char const *str);
char *my_getnbr(char const *str);
void my_putstr(char *str);
void my_putstr_i(char *str, int max);
int my_put_nbr_print(int nb);
int my_put_nbr(int nb);
void close_window(sfRenderWindow *window, sfEvent event);
int analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f position, int *score);
int manage_mouse_click(sfMouseButtonEvent event);

#endif
