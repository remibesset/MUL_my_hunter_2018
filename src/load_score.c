/*
** EPITECH PROJECT, 2018
** Load score
** File description:
** score
*/

#include <stdarg.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "../include/my.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *my_strcpy(char *dest, char const *src, int i)
{
    int j = 0;

    while (src[j] != '\0')
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}

char *mem_alloc(char const *a, char const *b)
{
    char *new_char = malloc(sizeof(char) * (my_strlen(a) + my_strlen(b) + 1));

    new_char = my_strcpy(new_char, a, 0);
    new_char = my_strcpy(new_char, b, my_strlen(a));
    return (new_char);
}

char *load_file_in_memo(char const *filepath, game_t *game)
{
    struct stat fileinfo;
    int status = stat(filepath, &fileinfo);
    int size = fileinfo.st_size;
    char *buff = malloc(sizeof(char) * (size + 14 + 1));
    int fd = open(filepath, O_RDWR);
    int j = 0;

    for (int i = 0; i < size + 15; i++)
        buff[i] = '\0';
    if (game->text_s.score > 0)
        write(fd, my_revstr(conv_i_str(game->text_s.score)),
        my_strlen(conv_i_str(game->text_s.score)));
    read(fd, buff, size);
    buff = mem_alloc("High Score : ", buff);
    close(fd);
    return (buff);
}

void game_over(game_t *game, sfVector2f pos_defeat)
{
    sfVector2f pos_score = {game->mode.width / 2 - 500 / 2 + 100,
        game->mode.height / 2};

    if (game->health <= 0) {
        if (game->text_s.score > game->text_highs.score && game->health == 0)
            load_file_in_memo("include/score.txt", game);
        sfText_setPosition(game->text_s.text_score, pos_score);
        sfSprite_setPosition(game->defeat.sprite, pos_defeat);
        sfRenderWindow_drawSprite(game->window, game->bg_grey.sprite, NULL);
        sfRenderWindow_drawSprite(game->window, game->defeat.sprite, NULL);
        game->vitesse = 3600;
        game->speed_anim = 3600;
        game->health = -1;
    }
}
