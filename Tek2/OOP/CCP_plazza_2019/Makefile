##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile file's program
##


SRC			=	Main.cpp\
				shell/Shell.cpp\
				throw/Error.cpp\
				throw/QueueMessage.cpp\
				reception/Reception.cpp\
				encrypt/Encrypt.cpp\
				kitchen/Order.cpp\
				kitchen/Kitchen.cpp\
				kitchen/Pizza.cpp\
				kitchen/Ingredient.cpp\
				kitchen/pizza/Americana.cpp\
				kitchen/pizza/Fantasia.cpp\
				kitchen/pizza/Margarita.cpp\
				kitchen/pizza/Regina.cpp\
				kitchen/Cooker.cpp\
				thread/Mutex.cpp\
				thread/SafeQueue.cpp\
				ipc/QueueMessage.cpp\
				ncurses/NCurses.cpp

SRCDIR  	=	./src/

OBJ			=	$(addprefix $(SRCDIR), $(SRC:.cpp=.o))

CPPFLAGS	=	-I./includes

CFLAGS		=	-Wall -Wextra -W

DLFLAGS		=	-lncurses -lpthread

NAME		=	plazza

CC			=	g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(DLFLAGS)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -f $(OBJ)
	@rm -f .log

re: fclean $(NAME)

.PHONY: all clean fclean re $(NAME)
