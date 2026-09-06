##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile file's program
##


SRC			=	Main.cpp\
				loadingSave/LoadingSave.cpp\
				menu/MainMenu.cpp\
				menu/SelectMenu.cpp\
				menu/ModalMenu.cpp\
    			base/image.cpp\
				menu/SplashMenu.cpp\
				menu/AMenu.cpp\
				audio/Audio.cpp\
				map/Map.cpp\
				object/Box.cpp\
				object/PowerSpeedUp.cpp\
				object/Floor.cpp\
				object/Wall.cpp\
				object/Bomb.cpp\
				object/PowerMoreBomb.cpp\
				object/PowerPassBox.cpp\
				object/PowerUpRangeBomb.cpp\
				object/PlayerModel.cpp\
				object/WallInside.cpp\
				object/AObject.cpp\
				menu/SettingsMenu.cpp\
				menu/HTPMenu.cpp\
				throw/Error.cpp\
				throw/ImageError.cpp\
				throw/MeshError.cpp\
				throw/AudioError.cpp\
				GameLoop/GameLoop.cpp\
				GameLoop/Particles.cpp\
				EndGame/EndGame.cpp\
				irrlicht/Event.cpp\
				tools/Clock.cpp

SRCDIR  	=	./src/

OBJ			=	$(addprefix $(SRCDIR), $(SRC:.cpp=.o))

CPPFLAGS	=	-I./includes				\
				-I./includes/LoadingSave	\
				-I./includes/menu			\
				-I./includes/Irrlicht		\
				-I./includes/map			\
				-I./includes/Audio			\
				-I./includes/PositionEngine	\
                -I./includes/Players        \
				-I./includes/object			\
				-I./includes/throw			\
				-I./includes/GameLoop		\
				-I./includes/EndGame		\
				-I./libs/Irrlicht/include	\
				-I./libs/SFML/include		\

CFLAGS		=	-std=c++17

DLFLAGS		=	-lpthread -lIrrlicht -lGL -lsfml-audio

NAME		=	bomberman

CC			=	g++

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(OBJ) -lstdc++fs $(CFLAGS) $(DLFLAGS) $(CPPFLAGS) -o $@

%.o:	%.cpp
	$(CC) $(CFLAGS) $(DLFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f .log
	@rm -fr ./build/
	@rm -fr ./CMakeFiles/
	@rm -fr ./CMakeCache.txt
	@rm -fr ./cmake_install.cmake
	@rm -fr ./bomberman
	@rm -fr ./fclean
	@rm -fr vgcore.*
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re $(NAME)
