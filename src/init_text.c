/*
** EPITECH PROJECT, 2018
** init set make
** File description:
** init set make
*/

#include <SFML/Graphics.h>
#include <SFML/System/Time.h>
#include <stdlib.h>
#include "../include/my.h"

void init_text_score(text_score_t *text_s)
{
    sfFont *font;
    sfVector2f pos_text;

    text_s->score = 0;
    text_s->text_score = sfText_create();
    pos_text.x = 50;
    pos_text.y = 30;
    font = sfFont_createFromFile("include/discoduck3d.ttf");
    sfText_setFont(text_s->text_score, font);
    sfText_setCharacterSize(text_s->text_score, 50);
    sfText_setPosition(text_s->text_score, pos_text);
}

void init_text_high_score(text_score_t *text_highs)
{
    sfFont *font;
    sfVector2f pos_text;

    text_highs->score;
    text_highs->text_score = sfText_create();
    pos_text.x = 800;
    pos_text.y = 700;
    font = sfFont_createFromFile("include/discoduck3d.ttf");
    sfText_setFont(text_highs->text_score, font);
    sfText_setCharacterSize(text_highs->text_score, 50);
    sfText_setPosition(text_highs->text_score, pos_text);
}