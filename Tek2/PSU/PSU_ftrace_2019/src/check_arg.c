/*
** EPITECH PROJECT, 2020
** PSU_ftrace_2019
** File description:
** check_arg
*/

#include "ftrace.h"

void display_help(void)
{
    fprintf(stdout, "USAGE: ftrace <command>\n");
    exit(0);
}

bool check_binary_within_directory(char *binary,
    char *path, size_t size, char **av)
{
    char *tmp = NULL;
    int fd = 0;
    struct stat stats;

    if ((tmp = malloc(sizeof(char) * size)) == NULL)
        exit(84);
    memset(tmp, 0, size);
    strcpy(tmp, path);
    strcat(tmp, "/");
    strcat(tmp, binary);
    if ((fd = open(tmp, O_RDONLY)) == -1)
        return (false);
    close(fd);
    if (access(tmp, R_OK) != 0)
        return (false);
    stat(tmp, &stats);
    if ((stats.st_mode & S_IFMT) != S_IFREG)
        return (false);
    set_program(tmp, av);
    return (true);
}

bool check_binary_within_path(char *binary, char **env, char **av)
{
    char *tmp = NULL;
    char **path = NULL;
    size_t size = 0;

    for (int i = 0; env && env[i]; i++) {
        if (!strncmp(env[i], "PATH=", 5))
            tmp = env[i];
    }
    if (!tmp)
        return (false);
    if ((path = my_str_to_word_array(tmp, "=:")) == NULL)
        return (false);
    for (int i = 1; path[i - 1] && path[i]; i++) {
        size = strlen(path[i]) + strlen("/") + strlen(binary) + 1;
        if (check_binary_within_directory(binary, path[i], size, av))
            return (true);
    }
    return (false);
}

bool check_binary(char *binary, char **env, char **av)
{
    int fd = 0;
    int i = 0;
    struct stat stats;

    for (; binary[i] && binary[i] != '/'; i++);
    if (binary[i] == '/') {
        if ((fd = open(binary, O_RDONLY)) == -1)
            return (false);
        close(fd);
        if (access(binary, R_OK) != 0)
            return (false);
        stat(binary, &stats);
        if ((stats.st_mode & S_IFMT) != S_IFREG)
            return (false);
        set_program(binary, av);
    } else
        return (check_binary_within_path(binary, env, av));
    return (true);
}

bool check_arg(int ac, char **av, char **env, ftrace_t *ftrace)
{
    if (ac < 2)
        return (false);
    if (!strcmp(av[1], "--help"))
        display_help();
    ftrace->av_one = av[1];
    if (!check_binary(av[1], env, av))
        return (false);
    ftrace->program_arguments = set_program(NULL, NULL);
    return (true);
}