/*
** EPITECH PROJECT, 2018
** My hunter project
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdlib.h>
#include "../include/my.h"
#include <SFML/Audio.h>

int main(int ac, char **ag)
{
    if (ac == 2 && ag[1][0] == '-' && ag[1][1] == 'h') {
        my_putstr("-----------------------MY_HUNTER--------\
        ------------------\n\n");
        my_putstr("The goal of the my hunter is to kill\
many ducks as possible.\n");
        my_putstr("For that you just have to mouve your mouse\
and left-click on the duck.\n");
        my_putstr("You have the right to miss 10 ducks.\n");
        my_putstr("Every time you hit the bird, the score increases by 1\n");
        my_putstr("If you reach the score of 30 the duck take other\
trajectories\n");
        my_putstr("You can see too the best score make by other player with the\
high score \n");
        my_putstr("GOOD LUCK && GOOD GAME\n");
        my_putstr("\n \nYou can play with ./my_hunter\n");
    } else {
        menu();
    }
}