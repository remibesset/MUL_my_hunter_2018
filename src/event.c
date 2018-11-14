/*
** EPITECH PROJECT, 2018
** event csfml
** File description:
** csfml
*/

#include <SFML/Graphics.h>
#include <SFML/Window/Event.h>
#include <stdio.h>
#include <stdlib.h>

// char *convert_int_to_char(int nbr)
// {
//     char *result = malloc(sizeof(char) * (11 + 1));
//     int i = 0;

//     while (nbr != 0) {
//         result[i++] = nbr % 10 + '0';
//         nbr /= 10;
//     }
//     result[i] = '\0';
//     return (result);
// }

void close_window(sfRenderWindow *window, sfEvent event)
{  
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

int manage_mouse_click(sfRenderWindow *window, sfEvent event, sfVector2f position, int *score)
{
    sfVector2i mouse_position;

    if (event.type == sfEvtMouseButtonPressed && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        mouse_position = sfMouse_getPosition((const sfWindow *)window);
        if (mouse_position.x < position.x + 110 && mouse_position.x >= position.x && 
            mouse_position.y < position.y + 110 && mouse_position.y >= position.y) {
            (*score)++;
            return (1);
        }
    }
}

int analyse_events(sfRenderWindow *window, sfEvent event, sfVector2f position, int *score)
{
    sfMouseButtonEvent mouse_event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        close_window(window, event);
        return (manage_mouse_click(window, event, position, score));
    }
    return (0);
}