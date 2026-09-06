##
## EPITECH PROJECT, 2021
## python
## File description:
## Makefile
##

TU_NAME	=	unit_tests

all:	run

run:
	cp ex01/hex_to_base64.py ./challenge01
	cp ex02/challenge02.py ./challenge02
	-cp ex03/challenge03.py ./challenge03
	-cp ex04/challenge04.py ./challenge04
	-cp ex05/challenge05.py ./challenge05
	-cp ex06/challenge06.py ./challenge06
	-cp ex07/challenge07.py ./challenge07
	-cp ex08/challenge08.py ./challenge08
	-cp ex09/challenge09.py ./challenge09
	-cp ex10/challenge10.py ./challenge10
	-cp ex11/challenge11.py ./challenge11
	-cp ex12/challenge12.py ./challenge12
	-cp ex13/challenge13.py ./challenge13
	-cp ex14/challenge14.py ./challenge14

tests_run:
	rsync -av --progress src/* . --exclude src/main.py
	rsync -av --progress tests/functionTest/main.py .
	mv main.py $(TU_NAME)

clean:
	@find . -name "*~" -print0 | xargs -0 /bin/rm -fr
	@find . -name "\#*#" -print0 | xargs -0 /bin/rm -fr
	@find . -name ".#*" -print0 | xargs -0 /bin/rm -fr

fclean:	clean
	@rm -f challenge??
	@find . -name "__pycache__" -print0 | xargs -0 /bin/rm -fr

re:	fclean all
