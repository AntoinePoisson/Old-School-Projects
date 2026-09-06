##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

#carefull with g++ and gcc !

SRCDIR = src/

SRC_SRC	=	main.cpp

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

FILTERMAIN = $(filter-out src/main.cpp, $(SRC))

OBJ2	=	$(FILTERMAIN:.cpp=.o)

CPPFLAGS	+=	-I include -I include/Socket -I include/Exception -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME	=	graphic

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system

clean:
	@rm -f $(OBJ) $(OBJ2)
	@rm -rf *.gcda *.gcno

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: test graphic