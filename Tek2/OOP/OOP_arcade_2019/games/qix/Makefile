##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			=	Qix.cpp	\

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra -fPIC -shared

CFLAGS		=	-fPIC

CC			=	g++

NAME		=	lib_arcade_qix.so

LN			=	$(shell  ln -s ../IGames.hpp .)

RM			=	rm -f

MV			=	mv ./$(NAME) ../

all:	$(NAME)	

$(NAME): $(LN) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@$(MV)

clean:
	@$(RM) IGames.hpp
	@$(RM) $(NAME)

fclean:		clean
	@$(RM) $(OBJ)
	@$(RM) *.vg*

re:		fclean all

.PHONY:	all NAME clean fclean re