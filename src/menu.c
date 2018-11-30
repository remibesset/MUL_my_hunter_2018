/*
** EPITECH PROJECT, 2018
** menu My Hunter
** File description:
** Menu
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdlib.h>
#include "../include/my.h"

void manage_mouse_click_menu(sfRenderWindow *window, game_t game)
{
    sfVector2i mouse_position;

    if (game.event.type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        mouse_position = sfMouse_getPosition((const sfWindow *)window);
        if (mouse_position.x >= game.mode.width / 2 - 250 + 5 &&
        mouse_position.x <= game.mode.width / 2 - 250 + 200 &&
        mouse_position.y > game.mode.height / 2
        + 80 && mouse_position.y <= game.mode.height / 2 + 130) {
            play(game);
        }
        else if (mouse_position.x >= game.mode.width / 2 - 250 + 250 &&
        mouse_position.x <= game.mode.width / 2 - 250 + 444 &&
        mouse_position.y > game.mode.height / 2
        + 80 && mouse_position.y <= game.mode.height / 2 + 130) {
            sfRenderWindow_close(window);
        }
    }
}

void close_window_menu(sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtClosed || (event->type == sfEvtKeyPressed &&
        event->key.code == sfKeyEscape))
        sfRenderWindow_close(window);
}

void analyse_events_menu(game_t game)
{
    sfMouseButtonEvent mouse_event;

    while (sfRenderWindow_pollEvent(game.window, &game.event)) {
        close_window_menu(game.window, &game.event);
        manage_mouse_click_menu(game.window, game);
    }
}

void set_texture_sprite_menu(game_t *game)
{
    sfVector2f pos_menu = {game->mode.width / 2 - 250,
        game->mode.height / 2 - 250};

    game->img_menu.texture = sfTexture_createFromFile("include/menu.png",
    NULL);
    game->img_menu.sprite = sfSprite_create();
    sfSprite_setTexture(game->img_menu.sprite, game->img_menu.texture, sfTrue);
    sfSprite_setPosition(game->img_menu.sprite, pos_menu);
}

int main(void)
{
    game_t game;

    set_value(&game, &game.clockanim, &game.clockpos, 0);
    game.run = 0;
    set_texture_sprite(&game.rect, &game);
    set_texture_sprite_menu(&game);
    init_text_score(&game.text_s);
    init_text_high_score(&game.text_highs);
    while (sfRenderWindow_isOpen(game.window) == 1) {
        do_animation(&game.clockanim, &game, &game.i, &game.rect);
        do_position(&game.clockpos, &game);
        analyse_events_menu(game);
        detect_position_die(&game.position, &game.mode, &game, &game.rect);
        target_mouse(&game);
        draw_all(game.window, &game, game.text_s.text_score);
        sfRenderWindow_clear(game.window, sfBlack);
    }
    make_destroy(game);
    return (0);
}