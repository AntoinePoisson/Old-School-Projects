##
## EPITECH PROJECT, 2020
## NWP_myteams_2019
## File description:
## Makefile
##

CC			=	gcc

RM			=	rm -f

BIN_SERVER	=	myteams_server

BIN_CLIENT	=	myteams_cli

SERV_DIR	=	./src/server/

CLI_DIR		=	./src/client/

SRC_SERV	=	events.c\
				loop.c\
				get_cmd.c\
				conn.c\
				init.c\
				commands/nothing.c\
				commands/handle_cmd.c\
				commands/help.c\
				commands/login.c\
				commands/send.c\
				commands/subscribe.c\
				commands/subscribed.c\
				commands/unsubscribe.c\
				commands/use.c\
				commands/create.c\
				commands/create_norme.c\
				commands/messages.c\
				commands/list.c\
				commands/logout.c\
				commands/info.c\
				commands/users.c\
				commands/user.c\
				tools/reply_server.c\
				tools/management_multi_cmd.c \
				tools/str_to_word_array.c\
				data_base/channel.c\
				data_base/client.c\
				data_base/comment.c\
				data_base/data_base.c\
				data_base/discussions.c\
				data_base/team.c\
				data_base/thread.c\
				data_base/save/channel.c\
				data_base/save/client.c\
				data_base/save/comment.c\
				data_base/save/discussions.c\
				data_base/save/team.c\
				data_base/save/thread.c\

SRC_CLI		=	str_to_word_array.c 	\
				parser_input.c 			\
				management_multi_cmd.c 	\
				handle_input.c 			\
				handle_server.c 		\
				tools.c 				\
				commands/client_channel_print_threads.c\
				commands/client_error_already_exist.c\
				commands/client_error_unauthorized.c\
				commands/client_error_unknown_channel.c\
				commands/client_error_unknown_team.c\
				commands/client_error_unknown_thread.c\
				commands/client_error_unknown_user.c\
				commands/client_event_channel_created.c\
				commands/client_event_loggedin.c\
				commands/client_event_loggedout.c\
				commands/client_event_private.c\
				commands/client_event_team_created.c\
				commands/client_event_thread.c\
				commands/client_event_thread_created.c\
				commands/client_print_channel.c\
				commands/client_print_channel_created.c\
				commands/client_print_reply_created.c\
				commands/client_print_subscribed.c\
				commands/client_print_team.c\
				commands/client_print_team_created.c\
				commands/client_print_teams.c\
				commands/client_print_team_two.c\
				commands/client_print_thread.c\
				commands/client_print_thread_created.c\
				commands/client_print_unsubscribed.c\
				commands/client_print_user.c\
				commands/client_print_users.c\
				commands/client_private_message.c\
				commands/client_team_print_channels.c\
				commands/client_thread_print_replies.c

TSRC		=	tests/unit_tests.c

CRITERION	=	--coverage -lcriterion

TEST		=	unit_tests

OBJ_SERV	=	$(addprefix $(SERV_DIR), $(SRC_SERV:.c=.o))

OBJ_CLI		=	$(addprefix $(CLI_DIR), $(SRC_CLI:.c=.o))

LDFLAGS		+=	-W -Wall -Wextra

CFLAGS		+=	-luuid -L./libs/myteams/ -lmyteams

CPPFLAGS	+=	-I ./includes -I ./libs/myteams/

all:	server client

server:	$(OBJ_SERV)
	@$(CC) src/server/main.c $(CPPFLAGS) -o $(BIN_SERVER) $(OBJ_SERV) $(CFLAGS)

client:	$(OBJ_CLI)
	@$(CC) src/client/main.c $(CPPFLAGS) -o $(BIN_CLIENT) $(OBJ_CLI) $(CFLAGS)

tests_run:
	$(CC) -o $(TEST) $(TSRC) $(addprefix $(SERV_DIR), $(SRC_SERV)) $(CPPFLAGS) $(CRITERION) $(CFLAGS)
	LD_LIBRARY_PATH=./libs/myteams ./$(TEST)
	gcovr

clean:
	@$(RM) $(BIN_SERVER)
	@$(RM) $(BIN_CLIENT)
	@$(RM) ./.data_base/*
	@$(RM) *.gcda
	@$(RM) *.gcno

fclean:	clean
	@$(RM) $(OBJ_SERV)
	@$(RM) $(OBJ_CLI)
	@$(RM) vgcore.*
	@$(RM) $(TEST)

re: fclean all

.PHONY:	all clean fclean re server client
