##
## EPITECH PROJECT, 2020
## CNA_trade_2019
## File description:
## Makefile
##

NAME	=	trade

RM		=	rm -fr

CACHE	=	./src/__pycache__

all:	fclean $(NAME)

$(NAME):
    ##pip install -r requirements.txt
	@test ! -f ./src/trade || mv ./src/trade .
	@chmod 775 ./trade
	@echo -n ''

clean:
	@test ! -f ./trade || mv ./trade ./src
	@echo -n ''

fclean: clean
	@$(RM) $(CACHE)

re: all

.PHONY:	$(NAME) clean fclean re
