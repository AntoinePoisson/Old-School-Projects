##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile my_cat program
##

SRC     =	Modules/OperatingSysKer.cpp	    \
			Modules/HostUserName.cpp		\
			Modules/DateTime.cpp			\
			Modules/RAM.cpp     			\
			Modules/Module.cpp			    \
			Modules/CPU.cpp					\
			MonitorCore.cpp				    \
			Display/SFML/SFML.cpp			\
			Display/NCurses/NCurses.cpp		\
			main.cpp

SRCDIR  =       src/

OBJ     =       $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

CPPFLAGS=	-I./includes

CFLAGS	=	-Wall -Wextra -Werror -lsfml-graphics -lsfml-window -lsfml-system -lncurses

NAME	=	MyGKrellm

CC		= 	g++

all:		$(NAME)

$(NAME):    $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
