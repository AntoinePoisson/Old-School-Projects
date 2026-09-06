##
## EPITECH PROJECT, 2020
## Zappy
## File description:
## Makefile Zappy with Unit tests
##

CC			=	gcc

RM			=	rm -f

BIN_SERVER	=	zappy_server

SRC_SERVER	=	main.c\
				server.c\
				check_error/check_arg.c\
				check_error/check_arg_norme.c\
				handle/ctrl_c.c\
				handle/new_client.c\
				handle/handle_cmd.c\
				handle/handle_split_multi_cmd.c\
				handle/condition_game.c\
				tools/print_map.c\
				tools/generate_uuid.c\
				tools/str_to_word_array.c\
				graphic_client/communication.c\
				map/create_map.c\
				map/management_map.c\
				map/regene_resources.c\
				map/regene_resources_norme.c\
				map/research_player_in_map.c\
				map/remove_player_to_cell.c\
				map/tools_map.c\
				server/close.c\
				server/reply.c\
				server/execute_cmd.c\
				server/init.c\
				server/launch.c\
				server/loop.c\
				server/read_input.c\
				server/tools.c\
				server/special_case_egg.c\
				server/special_case_ritual.c\
				commands/commands_function_extension.c\
				commands/broadcast_handling.c\
				commands/take_object.c\
				commands/set_object.c\
				commands/right.c\
				commands/left.c\
				commands/incantation.c\
				commands/forward.c\
				commands/eject.c\
				commands/connect_nbr.c\
				commands/inventory.c\
				commands/look.c\
				commands/death.c\
				commands/fork_cmd.c\

TEST_SERVER =	server.c\
				check_error/check_arg.c\
				check_error/check_arg_norme.c\
				handle/ctrl_c.c\
				handle/new_client.c\
				handle/handle_cmd.c\
				handle/handle_split_multi_cmd.c\
				handle/condition_game.c\
				tools/print_map.c\
				tools/generate_uuid.c\
				tools/str_to_word_array.c\
				graphic_client/communication.c\
				map/create_map.c\
				map/management_map.c\
				map/regene_resources.c\
				map/regene_resources_norme.c\
				map/research_player_in_map.c\
				map/remove_player_to_cell.c\
				map/tools_map.c\
				server/close.c\
				server/reply.c\
				server/execute_cmd.c\
				server/init.c\
				server/launch.c\
				server/loop.c\
				server/read_input.c\
				server/tools.c\
				server/special_case_egg.c\
				server/special_case_ritual.c\
				commands/commands_function_extension.c\
				commands/broadcast_handling.c\
				commands/take_object.c\
				commands/set_object.c\
				commands/right.c\
				commands/left.c\
				commands/incantation.c\
				commands/forward.c\
				commands/eject.c\
				commands/connect_nbr.c\
				commands/inventory.c\
				commands/look.c\
				commands/death.c\
				commands/fork_cmd.c\

DIR_SERVER 	= 	./server/src/

OBJ_SERVER	=	$(addprefix $(DIR_SERVER), $(SRC_SERVER:.c=.o))

CPPFLAGS	+=	-I ./server/includes

CFLAGS		+=	-W -Wextra -Wall -luuid -lm


BIN_CLIENT	=	zappy_ai


BIN_CLI_GRA	=	graphic


BIN_UT		=	unit_tests

DIR_CRIT 	= 	./tests/

SRC_CRIT	=	test.c\
				test1.c\
				read_tab.c\

OBJ_CRT		=	$(addprefix $(DIR_CRIT), $(SRC_CRIT:.c=.o))


all:	zappy_server zappy_ai

zappy_server: $(OBJ_SERVER)
	@$(CC) -o $(BIN_SERVER) $(OBJ_SERVER) $(CFLAGS)
	@echo -e "\033[32mSuccess Compile SERVER\033[0m"

client_graphic:
	@$(MAKE) -C client_graphic/ re
	@mv client_graphic/$(BIN_CLI_GRA) .

zappy_ai: client_graphic
	@$(shell echo -e "#!/bin/bash\npython3 client/main.py \$${*:1}" > '$(BIN_CLIENT)')
	@$(shell chmod 775 '$(BIN_CLIENT)')
	@echo -e "\033[32mSuccess Compile CLIENT\033[0m"

debug: $(OBJ_SERVER)
	@$(CC) -o $(BIN_SERVER) $(OBJ_SERVER) $(CFLAGS)
	@echo -e "\033[32mSuccess Compile DEBUG\033[0m"

tests_run:
	@$(RM) ./*.gcda ./*.gcno
	@gcc $(addprefix $(DIR_SERVER), $(TEST_SERVER)) ./tests/test_error.c ./tests/test_working.c $(CRT) $(CLAGS) $(CPPFLAGS) -o unit_tests --coverage -lcriterion -lm -luuid
	@echo -e "\033[32mSuccess Compile unit_test\033[0m"

clean:
	@$(RM) $(BIN_SERVER)
	@$(RM) $(BIN_CLIENT)
	@$(RM) $(BIN_UT)
	@$(RM) $(BIN_CLI_GRA)
	@$(RM) ./*.gcda ./*.gcno

fclean:	clean
	@$(MAKE) -s -C client_graphic/ fclean
	@$(RM) $(OBJ_SERVER)
	@$(RM) $(OBJ_CRT)
	@$(RM) -r *.gc*
	@$(RM) vgcore.*

re:	fclean all

.PHONY:	all clean fclean re zappy_server zappy_ai tests_run debug client_graphic
