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
#include <SFML/Audio.h>

void do_animation(make_clock_t *clockanim, game_t *game, int *i,
sfIntRect *rect)
{
    clockanim->time_st = sfClock_getElapsedTime(clockanim->clock_st);
    clockanim->second = clockanim->time_st.microseconds / 1000000.0;
    if (clockanim->second > game->speed_anim) {
        (*rect).left = 110 * (*i)++;
        *i = (*i > 2) ? 0 : *i;
        sfSprite_setTextureRect(game->bird.sprite, *rect);
        sfClock_restart(clockanim->clock_st);
    }
}

void do_position(make_clock_t *clockpos, game_t *game)
{
    float speed_x = 6;
    float speed_y = 6;

    clockpos->time_st = sfClock_getElapsedTime(clockpos->clock_st);
    clockpos->second = clockpos->time_st.microseconds / 1000000.0;
    if (clockpos->second > game->vitesse) {
        game->position.x += speed_x;
        if (game->text_s.score >= 30) {
            game->direction = (game->position.y <= 0) ? 1 : game->direction;
            game->direction = (game->position.y >= 768 - 110)
            ? -1 : game->direction;
            game->position.y += speed_y * game->direction;
        }
        sfSprite_setPosition(game->bird.sprite, game->position);
        sfClock_restart(clockpos->clock_st);
    }
}

void detect_position_die(sfVector2f *position, sfVideoMode *mode, game_t *game,
sfIntRect *rect)
{
    if ((*position).x >= (*mode).width + (*rect).height) {
        (*position).x = -110;
        (*position).y = rand() % ((*mode).height - ((*rect).height + 200) / 2);
        if (game->run == 1) {
            game->health -= 1;
            sfMusic_play(game->heart.song);
        }
    }
    if (game->die == 1) {
        if (game->text_s.score == 30)
            game->vitesse = 0.015;
        else
            game->vitesse /= 1.03;
        position->x = -110;
        position->y = rand() % ((*mode).height - ((*rect).height + 200) / 2);
    }
}

void target_mouse(game_t *game)
{
    sfVector2i pos_mouse;
    sfVector2f mouse_pos;

    pos_mouse = sfMouse_getPosition((const sfWindow *)game->window);
    mouse_pos.x = pos_mouse.x - 40;
    mouse_pos.y = pos_mouse.y - 40;
    sfSprite_setPosition((*game).target.sprite, mouse_pos);
}

int play(game_t game)
{
    sfMusic_play(game.bird.song);
    sfMusic_setLoop(game.bird.song, 1);
    set_value(&game, &game.clockanim, &game.clockpos, 1);
    set_texture_sprite(&game.rect, &game);
    init_text_score(&game.text_s);
    init_text_high_score(&game.text_highs);
    while (sfRenderWindow_isOpen(game.window) == 1) {
        do_animation(&game.clockanim, &game, &game.i, &game.rect);
        do_position(&game.clockpos, &game);
        game.die = analyse_events(game.window, game, &game.text_s.score);
        detect_position_die(&game.position, &game.mode, &game, &game.rect);
        sfText_setString(game.text_highs.text_score, game.text_highs.text_char);
        sfText_setString(game.text_s.text_score,
        mem_alloc("SCORE : ", my_revstr(conv_i_str(game.text_s.score))));
        target_mouse(&game);
        sfRenderWindow_clear(game.window, sfBlack);
        draw_all(game.window, &game, game.text_s.text_score);
    }
    make_destroy(game);
    return (0);
}
