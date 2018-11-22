/*
** EPITECH PROJECT, 2018
** event csfml
** File description:
** csfml
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdlib.h>
#include "../include/my.h"

const char *conv_i_str(int nbr)
{
    char *result = malloc(sizeof(char) * (11 + 1));
    int i = 0;

    if (nbr > 0) {
        while (nbr != 0) {
            result[i++] = nbr % 10 + '0';
            nbr /= 10;
        }
    } else
        result[i++] = '0';
    
    result[i] = '\0';
    return (result);
}

void close_window(sfRenderWindow *window, sfEvent event)
{  
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && 
    event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void event_menu_defeat(game_t game)
{
    sfVector2i mp;

    if (game.event.type == sfEvtMouseButtonPressed && 
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        mp = sfMouse_getPosition((const sfWindow *)game.window);
        if (mp.x > 372 && mp.x < 502 && mp.y > 558 && mp.y < 595) {
            sfRenderWindow_close(game.window);
        } else if (mp.x > 744 && mp.x < 866 && mp.y > 554 && mp.y < 593) {
            sfRenderWindow_close(game.window);
            main();
        }  else if (mp.x > 480 && mp.x < 769 && mp.y > 484 && mp.y < 538) {
            play(game);
        }    
    }
}

int manage_mouse_click(sfRenderWindow *window, game_t game,  
sfVector2f pos_bird, int *score)
{
    sfVector2i mp;

    if (game.event.type == sfEvtMouseButtonPressed && 
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        mp = sfMouse_getPosition((const sfWindow *)window);
        if (mp.x < pos_bird.x + 110 && mp.x >= pos_bird.x && mp.y < pos_bird.y
        + 110 && mp.y >= pos_bird.y) {
            (*score)++;
            game.vitesse /= 1.03;
            return (1);
        } else if (game.health <= 0) {
            event_menu_defeat(game);
        }
    }
    return (0);
}

int analyse_events(sfRenderWindow *window, game_t game, int *score)
{
    sfMouseButtonEvent mouse_event;

    while (sfRenderWindow_pollEvent(window, &game.event)) {
        close_window(window, game.event);
        return (manage_mouse_click(window, game, game.position, score));
    }
    return (0);
}