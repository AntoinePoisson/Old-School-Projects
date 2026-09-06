##
## EPITECH PROJECT, 2020
## PSU_imageCompressor_2019
## File description:
## Makefile
##

NAME	=	imageCompressor

SRC	=	./src/main.hs

SRC_TEST	=	./pasPush/.test_file.hs

CPPFLAG	=	-Wall -W -Wextra

RM	=	rm -f

CC	=	ghc


all:	name

name:
	stack build --copy-bins --local-bin-path ./test/
	stack path --local-install-root
	mv ./test/imageCompressor-exe ./$(NAME)

test:
	ghc -o b.out $(SRC_TEST)

clean:
	@$(RM) $(NAME)
	@$(RM) ./text/imageCompressor-exe

fclean:	clean
	@$(RM) vgcore.*
	@$(RM) ./app/*.o
	@$(RM) ./app/*.hi

re: fclean all

.PHONY:	all clean fclean re name test
