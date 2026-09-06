##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile file's program
##

## CPPFLAGS	=	-I./includes

SRC     =	main.cpp					\
			Tools/Errors.cpp			\
			Parsing/Parsing.cpp			\
			Factory/Factory.cpp			\
			Components/AComponent.cpp	\
			Components/C_2716.cpp		\
			Components/C_4001.cpp		\
			Components/C_4008.cpp		\
			Components/C_4011.cpp		\
			Components/C_4013.cpp		\
			Components/C_4017.cpp		\
			Components/C_4030.cpp		\
			Components/C_4040.cpp		\
			Components/C_4069.cpp		\
			Components/C_4071.cpp		\
			Components/C_4081.cpp		\
			Components/C_4094.cpp		\
			Components/C_4514.cpp		\
			Components/C_4801.cpp		\
			Components/Clock.cpp		\
			Components/False.cpp		\
			Components/Input.cpp		\
			Components/Output.cpp		\
			Components/True.cpp			\

SRCDIR  =       src/

OBJ     =       $(addprefix $(SRCDIR), $(SRC:.cpp=.o))

CFLAGS	=	-Wall -Wextra -W

NAME	=	nanotekspice

CC		= 	g++

all:	$(NAME)

$(NAME):    $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re
