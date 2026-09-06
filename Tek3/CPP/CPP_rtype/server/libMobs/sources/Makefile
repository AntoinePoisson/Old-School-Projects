##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			=	PlaneMob.cpp	\
    	../../../common/sources/Exception.cpp	\
    	../../../common/sources/ComponentAManager.cpp	\
    	../../../common/sources/EntityComponentManager.cpp	\
    	../../../common/sources/EntityAManager.cpp	\
    	../../../common/sources/SystemAManager.cpp	\
    	../../../common/sources/SingletonECManager.cpp	\

    	# ../../sources/SystemNetworkServer.cpp	\
    	# ../../sources/Mediator.cpp	\
    	# ../../sources/SystemNetwork.cpp	\
    	# ../../sources/SubSystems.cpp	\
    	# ../../sources/SystemNetworkServer.cpp	\
    	# ../../sources/GameEngine.cpp	\
    	# ../../sources/SystemMovementPlayerServer.cpp	\
    	# ../../sources/SystemCheckCollisionServer.cpp	\
    	# ../../sources/SystemInterpretCollisionServer.cpp	\
    	# ../../sources/SystemCheckEndGame.cpp	\
    	# ../../sources/SystemLoadMethodeMob.cpp	\
    	# ../../sources/SystemMobServer.cpp	\
    	# ../../sources/SystemTimerGame.cpp	\
    	# ../../sources/SubSystemServer.cpp	\
    	# ../../sources/Server.cpp	\
    	# ../../sources/Client.cpp	\


OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-fPIC -shared -I../ -I../../includes/ -I../../../common/includes/ -I../../../client/includes/

CFLAGS		=	-fPIC

CC			=	g++

NAME		=	libPlaneMob.so

RM			=	rm -f

MV			=	mv ./$(NAME) ../

all:	$(fclean) $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)
	@cp ./$(NAME) ../../../build/server/lib/
	@$(RM) $(OBJ)
	@$(RM) $(NAME)

clean:
	@$(RM) $(NAME)

fclean:		clean
	@$(RM) $(OBJ)

re:		fclean all

.PHONY:	all NAME clean fclean re