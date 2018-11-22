/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void set_value(game_t *game, make_clock_t *clockanim, make_clock_t *clockpos, int run)
{
    clockanim->clock_st = sfClock_create();
    clockpos->clock_st = sfClock_create();
    game->mode = (sfVideoMode) {1280, 768, 32};
    game->rect = (sfIntRect) {0, 0, 330, 110};
    game->position = (sfVector2f) {-110, 200};
    game->i = 1;
    game->die = 0;
    game->run = run;
    game->vitesse = 0.001;
    game->speed_anim = 0.2;
    game->health = 10;
    if (game->run == 0)
        game->window = sfRenderWindow_create(game->mode, "MyHunter", sfDefaultStyle, NULL);
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void set_texture_sprite(sfIntRect *rect, game_t *game)
{
    game->bird.texture = sfTexture_createFromFile("include/duck.png",rect);
    game->bird.sprite = sfSprite_create();
    sfSprite_setTexture(game->bird.sprite, game->bird.texture, sfTrue);
    (*rect).width = 110;
    sfSprite_setTextureRect(game->bird.sprite, (*rect));
    game->bg.texture = sfTexture_createFromFile("include/backgroud.png", NULL);
    game->bg.sprite = sfSprite_create();
    sfSprite_setTexture(game->bg.sprite, game->bg.texture, sfTrue);
    game->target.texture = sfTexture_createFromFile("include/vise_write.png", NULL);
    game->target.sprite = sfSprite_create();
    sfSprite_setTexture(game->target.sprite, game->target.texture, sfTrue);
    game->heart.texture = sfTexture_createFromFile("include/heart.png", NULL);
    game->heart.sprite = sfSprite_create();
    sfSprite_setTexture(game->heart.sprite, game->heart.texture, sfTrue);
    game->defeat.texture = sfTexture_createFromFile("include/defeat.png", NULL);
    game->defeat.sprite = sfSprite_create();
    sfSprite_setTexture(game->defeat.sprite, game->defeat.texture, sfTrue);
    game->bg_grey.texture = sfTexture_createFromFile("include/bg_G.png", NULL);
    game->bg_grey.sprite = sfSprite_create();
    sfSprite_setTexture(game->bg_grey.sprite, game->bg_grey.texture, sfTrue);
}

void init_text(text_score_t *text_s)
{
    sfFont *font;
    sfVector2f pos_text;

    text_s->score = 0;
    text_s->text_score = sfText_create();
    pos_text.x = 50;
    pos_text.y = 30;
    font = sfFont_createFromFile("include/discoduck3d.ttf");
    sfText_setFont(text_s->text_score, font);
    sfText_setCharacterSize(text_s->text_score, 70);
    sfText_setPosition(text_s->text_score, pos_text);
}

void draw_all(sfRenderWindow *window, game_t *game, sfText *text_score)
{
    sfVector2f pos_hearth = {game->mode.width - 50, 50};
    sfVector2f pos_defeat = {game->mode.width / 2 - 270, game->mode.height / 2 - 280};

    sfRenderWindow_drawSprite(window, game->bg.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->bird.sprite, NULL);
    for (int i = 0; i < game->health && game->run == 1; i++) {
        pos_hearth.x = pos_hearth.x - 50;
        sfSprite_setPosition(game->heart.sprite, pos_hearth);
        sfRenderWindow_drawSprite(window, game->heart.sprite, NULL);
    }
    sfRenderWindow_drawText(window, text_score, NULL);
    if (game->health <= 0) {
        sfSprite_setPosition(game->defeat.sprite, pos_defeat);
        sfRenderWindow_drawSprite(window, game->bg_grey.sprite, NULL);
        sfRenderWindow_drawSprite(window, game->defeat.sprite, NULL);
        game->vitesse = 3600;
        game->speed_anim = 3600;
    }
    if (game->run == 0)
        sfRenderWindow_drawSprite(window, game->img_menu.sprite, NULL);
    sfRenderWindow_drawSprite(window, game->target.sprite, NULL);
    sfRenderWindow_display(window);
}

void make_destroy(game_t game)
{
    sfSprite_destroy(game.bird.sprite);
    sfSprite_destroy(game.bg.sprite);
    sfClock_destroy(game.clockanim.clock_st);
    sfClock_destroy(game.clockpos.clock_st);
    if (game.run == 1)
        sfText_destroy(game.text_s.text_score);
    sfRenderWindow_destroy(game.window);
}