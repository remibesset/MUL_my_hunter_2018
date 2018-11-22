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
#include <SFML/System/Time.h>

typedef struct make_clock
{
    sfClock *clock_st;
    sfTime time_st;
    float second;
} make_clock_t;

typedef struct init_sp_tex
{
    sfTexture *texture;
    sfSprite *sprite;
} init_sp_tex_t;

typedef struct text_score_a
{
    sfText *text_score;
    int score;
} text_score_t;

typedef struct init_game
{
    sfRenderWindow *window;
    sfEvent event;
    init_sp_tex_t bird;
    init_sp_tex_t bg;
    init_sp_tex_t img_menu;
    init_sp_tex_t target;
    init_sp_tex_t heart;
    init_sp_tex_t defeat;
    init_sp_tex_t bg_grey;
    text_score_t text_s;
    make_clock_t clockanim;
    make_clock_t clockpos;
    sfVideoMode mode;
    sfIntRect rect;
    sfVector2f position;
    int run;
    int i;
    int die;
    float vitesse;
    float speed_anim;
    int health;
} game_t;

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
int analyse_events(sfRenderWindow *window, game_t game, int *score);
const char *conv_i_str(int nbr);
int manage_mouse_click(sfRenderWindow *window, game_t game,  
sfVector2f position, int *score);
void set_value(game_t *game, make_clock_t *clockanim, make_clock_t *clockpos, int run);
void draw_all(sfRenderWindow *window, game_t *game, sfText *text_score);
void set_texture_sprite(sfIntRect *rect, game_t *game);
void init_text(text_score_t *text_s);
void target_mouse(game_t *game);
void make_destroy(game_t game);
void do_animation(make_clock_t *clockanim, game_t *game, int *i, sfIntRect *rect);
void do_position(make_clock_t *clockpos, init_sp_tex_t *bird, sfVector2f *position, game_t *game);
void detect_position_die(sfVector2f *position, sfVideoMode *mode, game_t *game, sfIntRect *rect);
void target_mouse(game_t *game);
int play(game_t game);
int main(void);

#endif
