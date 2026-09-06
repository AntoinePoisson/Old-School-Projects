##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			=	Main.cpp	\
				Core.cpp	\
				Error.cpp	\
				LoadHandling.cpp	\

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Wextra

LDFLAGS		=	-ldl

CC			=	g++

NAME		=	arcade

RM			=	rm -f

MV			=	mv ./$(NAME) ../

LN			=	$(shell ln -s ../lib/IGraphics.hpp . && ln -s ../games/IGames.hpp .)

all:	$(NAME)	

$(NAME): $(LN) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(CPPFLAGS)
	@$(MV)

clean:
	@$(RM) ../$(NAME)
	@$(RM) ./IGraphics.hpp
	@$(RM) ./IGames.hpp

fclean:		clean
	@$(RM) $(OBJ)
	@$(RM) vgcore.*

re:		fclean all

.PHONY:	all NAME clean fclean re