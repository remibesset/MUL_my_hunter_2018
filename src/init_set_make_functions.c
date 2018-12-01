/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void set_value(game_t *game, make_clock_t *clockanim,
make_clock_t *clockpos, int run)
{
    clockanim->clock_st = sfClock_create();
    clockpos->clock_st = sfClock_create();
    game->mode = (sfVideoMode) {1280, 768, 32};
    game->rect = (sfIntRect) {0, 0, 330, 110};
    game->position = (sfVector2f) {-110, 200};
    game->text_s.score = 0;
    game->i = 1;
    game->die = 0;
    game->run = run;
    game->vitesse = 0.015;
    game->speed_anim = 0.2;
    game->health = 10;
    game->direction = 1;
    game->text_highs.text_char = load_file_in_memo("include/score.txt", game);
    game->text_highs.score = char_to_int(game->text_highs.text_char);
    if (game->run == 0)
        game->window = sfRenderWindow_create(game->mode, "MyHunter",
        sfDefaultStyle, NULL);
    init_music(game);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void set_texture_sprite(sfIntRect *rect, game_t *game)
{
    game->bird.texture = sfTexture_createFromFile("include/duck.png", rect);
    game->bird.sprite = sfSprite_create();
    sfSprite_setTexture(game->bird.sprite, game->bird.texture, sfTrue);
    rect->width = 110;
    sfSprite_setTextureRect(game->bird.sprite, (*rect));
    game->bg.texture = sfTexture_createFromFile("include/backgroud.png", NULL);
    game->bg.sprite = sfSprite_create();
    sfSprite_setTexture(game->bg.sprite, game->bg.texture, sfTrue);
    game->target.texture = sfTexture_createFromFile("include/vise_W.png", NULL);
    game->target.sprite = sfSprite_create();
    sfSprite_setTexture(game->target.sprite, game->target.texture, sfTrue);
    game->heart.texture = sfTexture_createFromFile("include/heart.png", NULL);
    game->heart.sprite = sfSprite_create();
    sfSprite_setTexture(game->heart.sprite, game->heart.texture, sfTrue);
    game->defeat.texture = sfTexture_createFromFile("include/def.png", NULL);
    game->defeat.sprite = sfSprite_create();
    sfSprite_setTexture(game->defeat.sprite, game->defeat.texture, sfTrue);
    game->bg_grey.texture = sfTexture_createFromFile("include/bg_G.png", NULL);
    game->bg_grey.sprite = sfSprite_create();
    sfSprite_setTexture(game->bg_grey.sprite, game->bg_grey.texture, sfTrue);
}

void draw_all(sfRenderWindow *window, game_t *game, sfText *text_score)
{
    sfVector2f pos_hearth = {game->mode.width - 50, 50};
    sfVector2f pos_defeat = {game->mode.width / 2 - 270,
        game->mode.height / 2 - 280};

    sfRenderWindow_drawSprite(window, game->bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->bird.sprite, NULL);
    for (int i = 0; i < game->health && game->run == 1; i++) {
        pos_hearth.x = pos_hearth.x - 50;
        sfSprite_setPosition(game->heart.sprite, pos_hearth);
        sfRenderWindow_drawSprite(window, game->heart.sprite, NULL);
    }
    sfRenderWindow_drawText(window, game->text_highs.text_score, NULL);
    game_over(game, pos_defeat);
    if (game->run == 0)
        sfRenderWindow_drawSprite(window, game->img_menu.sprite, NULL);
    sfRenderWindow_drawText(window, text_score, NULL);
    sfRenderWindow_drawSprite(window, game->target.sprite, NULL);
    sfRenderWindow_display(window);
}

void make_destroy(game_t game)
{
    sfMusic_destroy(game.img_menu.song);
    sfMusic_destroy(game.heart.song);
    sfMusic_destroy(game.target.song);
    sfMusic_destroy(game.bird.song);
    sfSprite_destroy(game.bird.sprite);
    sfSprite_destroy(game.bg.sprite);
    sfSprite_destroy(game.bg_grey.sprite);
    sfSprite_destroy(game.target.sprite);
    sfSprite_destroy(game.heart.sprite);
    sfSprite_destroy(game.defeat.sprite);
    sfClock_destroy(game.clockanim.clock_st);
    sfClock_destroy(game.clockpos.clock_st);
    if (game.run == 1) {
        sfText_destroy(game.text_s.text_score);
        sfText_destroy(game.text_highs.text_score);
    }
    sfRenderWindow_destroy(game.window);
}