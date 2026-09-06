##
## EPITECH PROJECT, 2020
## Rust
## File description:
## Makefile
##

SRC		=	./tmp/src/main.rs

NAME	=	groundhog

RM		=	rm -f

all:	fclean $(NAME)

$(NAME): fclean
	cargo build
	mv ./target/debug/CNA_groundhog_2019 $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: all

.PHONY:	$(NAME) clean fclean re
