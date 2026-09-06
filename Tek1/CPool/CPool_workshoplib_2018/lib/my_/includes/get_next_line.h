/*
** EPITECH PROJECT, 2019
** get_next_line.h
** File description:
** get_next_line header
*/

#ifndef READ_SIZE
# define READ_SIZE (300)

char *is_end_algo(int ret_read, char *buffer, int read_y);
char *clear_buffer(char *reader, int *line);
char *is_end_algo_two(char *reader, int *nbr, int nbr_charac, char *buffer);
char *clear_reader(char *reader);

#endif /* !READ_SIZE  */
