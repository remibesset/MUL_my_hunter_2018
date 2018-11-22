##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## TasK02 day10
##

SRC = src/main.c \
	src/my_lib.c \
	src/event.c \
	src/init_set_make_functions.c \
	src/menu.c \

OBJ = $(SRC:.c=.o)

NAME = my_hunter

LIBFLAG = gcc -o

GRAPHIC = -lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(LIBFLAG) $(NAME) $(OBJ) -g $(GRAPHIC) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
