##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

LIBCACA		=	./libcaca/

AALIB		=	./aalib/

SFML		=	./sfml/

RM			=	rm -f lib_arcade_*.so


all:	NAME

NAME:
	@make -C $(SFML)
	@make -C $(AALIB)
	@make -C $(LIBCACA)

clean:
	@$(RM) 
	@make clean -C $(SFML)
	@make clean -C $(AALIB)
	@make clean -C $(LIBCACA)

fclean:		clean
	@make fclean -C $(SFML)
	@make fclean -C $(AALIB)
	@make fclean -C $(LIBCACA)

re:		fclean all

.PHONY:	all NAME clean fclean re