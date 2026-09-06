##
## EPITECH PROJECT, 2020
## cpp
## File description:
## Makefile cpp with Unit tests
##

#carefull with g++ and gcc !

SRCDIR = src/

SRC_SRC	=	main.cpp		\
			Cell.cpp		\
			Graphic.cpp		\
			Client.cpp		\
			Interpreter.cpp	\
			Controller.cpp	\

EXTERNAL	=	include/Exception/Exception.cpp	\

HELPER =	helpers/main.cpp	\
			src/Server.cpp		\

SRC =	$(addprefix $(SRCDIR), $(SRC_SRC))

OBJ	=	$(SRC:.cpp=.o)		\
		$(EXTERNAL:.cpp=.o)	\

FILTERMAIN = $(filter-out src/main.cpp, $(SRC))

OBJ2	=	$(FILTERMAIN:.cpp=.o)	\
			$(EXTERNAL:.cpp=.o)		\
			$(HELPER:.cpp=.o)		\

CPPFLAGS	+=	-I include -I include/Socket -I include/Exception -lsfml-graphics -lsfml-window -lsfml-system

CRITDIR = tests/

CRT_SRC	=	redirect.c		\
			Cell_test.cpp	\

CRT = $(addprefix $(CRITDIR), $(CRT_SRC))

NAME	=	graphic

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

test:	clean $(OBJ2)
	g++  -o test $(OBJ2) $(CPPFLAGS)

tests_run:
	g++  -o unit_tests $(CRT) $(EXTERNAL) src/Server.cpp $(FILTERMAIN) $(CPPFLAGS) --coverage -lcriterion
	./unit_tests
	gcovr
	rm -rf *.gcda *.gcno

clean:
	@rm -f $(OBJ) $(OBJ2)
	@rm -rf *.gcda *.gcno

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: test graphic