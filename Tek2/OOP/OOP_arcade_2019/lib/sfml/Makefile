##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			=	Sfml.cpp	\

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -fPIC -shared

CFLAGS		=	-fPIC

LDFLAGS		=	-lsfml-graphics -lsfml-window -lsfml-system

CC			=	g++

NAME		=	lib_arcade_sfml.so

LN			=	$(shell  ln -s ../IGraphics.hpp .)

RM			=	rm -f

MV			=	mv ./$(NAME) ../

all:	$(NAME)	

$(NAME): $(LN) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS)
	@$(MV)

clean:
	@$(RM) IGraphics.hpp
	@$(RM) $(NAME)

fclean:		clean
	@$(RM) $(OBJ)

re:		fclean all

.PHONY:	all NAME clean fclean re