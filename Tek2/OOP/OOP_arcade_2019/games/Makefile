##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

PACMAN		=	./pacman/

NIBBLER		=	./nibbler/

QIX			=	./qix/

CENTIPEDE	=	./centipede/

SOLARFOX	=	./solarfox/

RM			=	rm -f lib_arcade_*.so


all:	NAME

NAME:
	@make -C $(NIBBLER)
	@make -C $(PACMAN)
	@make -C $(QIX)
	@make -C $(CENTIPEDE)
	@make -C $(SOLARFOX)
clean:
	@$(RM) 
	@make clean -C $(NIBBLER)
	@make clean -C $(PACMAN)
	@make clean -C $(QIX)
	@make clean -C $(CENTIPEDE)
	@make clean -C $(SOLARFOX)

fclean:		clean
	@make fclean -C $(NIBBLER)
	@make fclean -C $(PACMAN)
	@make fclean -C $(QIX)
	@make fclean -C $(CENTIPEDE)
	@make fclean -C $(SOLARFOX)

re:		fclean all

.PHONY:	all NAME clean fclean re