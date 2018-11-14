/*
** EPITECH PROJECT, 2018
** My hunter project
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

const char *convert_int_to_char(int nbr)
{
    char *result = malloc(sizeof(char) * (11 + 1));
    int i = 0;

    while (nbr != 0) {
        result[i++] = nbr % 10 + '0';
        nbr /= 10;
    }
    result[i] = '\0';
    return (result);
}

int main(void) {
    sfRenderWindow *window;
    sfVideoMode mode = {1280, 769, 32};
    sfIntRect rect = {0, 0, 330, 110};
    sfTexture *texture = sfTexture_createFromFile("include/bootstrap_my_hunter.png", &rect);
    sfTexture *bg_tex = sfTexture_createFromFile("include/bg_duck_hunt.png", NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite *bg_sp = sfSprite_create();
    sfClock *clock_animation = sfClock_create();
    sfTime time_animation;
    float seconds_anim;
    sfClock *clock_pos = sfClock_create();
    sfTime time_pos;
    float seconds_pos;
    int i = 1;
    int sens = 3;
    int score = 1;
    int die = 0;
    sfEvent event;
    sfVector2f position;
    sfVector2f pos_text;
    sfText *text_score = sfText_create();
    sfFont *font;

    pos_text.x = 50;
    pos_text.y = 30;
    font = sfFont_createFromFile("include/discoduck3d.ttf");
    position.x = -110;
    position.y = 200;
    window = sfRenderWindow_create(mode, "My Hunter", sfDefaultStyle, NULL);
    sfSprite_setTexture(bg_sp, bg_tex, sfTrue);
    sfSprite_setTexture(sprite, texture, sfTrue);
    rect.width = 110;
    sfSprite_setTextureRect(sprite, rect);
    sfText_setFont(text_score, font);
    sfText_setCharacterSize(text_score, 70);
    sfText_setPosition(text_score, pos_text);
    while (sfRenderWindow_isOpen(window) == 1) {
        time_animation = sfClock_getElapsedTime(clock_animation);
        seconds_anim = time_animation.microseconds / 1000000.0;
        if (seconds_anim > 0.2) {
            rect.left = 110 * i++;
            i = (i > 2) ? 0 : i;
            position.x += sens;
            sfSprite_setTextureRect(sprite, rect);
            sfClock_restart(clock_animation);
        }
        time_pos = sfClock_getElapsedTime(clock_pos);
        seconds_pos = time_pos.microseconds / 1000000.0;
        if (seconds_pos > 0.005) {
            position.x += sens;
            sfSprite_setPosition(sprite, position);
            sfClock_restart(clock_pos);
        }
        die = analyse_events(window, event, position, &score);
        if (position.x >= mode.width + rect.height || die == 1) {
            position.x = -110;
            position.y = rand() % (mode.height - (rect.height + 200) / 2);
        }
        sfText_setString(text_score, my_revstr(convert_int_to_char(score)));
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, bg_sp, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_drawText(window, text_score, NULL);
        sfRenderWindow_display(window);
        die = 0;
    }
    sfRenderWindow_destroy(window);
    return 0;
}