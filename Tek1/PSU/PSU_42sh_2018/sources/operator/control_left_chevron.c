/*
** EPITECH PROJECT, 2019
** control_left_chevron.c
** File description:
** control left chevron execution
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_shell.h"

static void management_left_chevron_son(int fd, int pipe_fd[])
{
    int count = 0;

    close(pipe_fd[0]);
    for (char buf; read(fd, &buf, 1) > 0; count++)
        write(pipe_fd[1], &buf, 1);
    close(pipe_fd[1]);
}

static int management_left_chevron_parent(variable_t *var, tree_t *tree,
    int pipe_fd[])
{
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    if (check_element_is_operator(tree->left))
        return (chose_good_operator(var, tree->left));
    else
        return (exec_arg(var, tree->left->data));
    return (0);
}

static int management_left_chevron(variable_t *var, tree_t *tree, char *file)
{
    int fd = open(file, O_RDONLY);
    int pipe_fd[2];
    pid_t pid;
    int wstatus = 0;
    int save = dup(0);

    if ((file == NULL) || (fd == -1) || pipe(pipe_fd) == -1
        || ((pid = fork()) == -1))
        return (my_printf("%s: No such file or directory.\n", file));
    if (pid == 0) {
        management_left_chevron_son(fd, pipe_fd);
        my_exit(var, "0", 0);
    } else {
        wstatus = management_left_chevron_parent(var, tree, pipe_fd);
        dup2(save, 0);
    }
    close(fd);
    free(file);
    return (wstatus);
}

int control_left_chevron(variable_t *var, tree_t *tree)
{
    char *two = NULL;

    if (tree == NULL)
        return (84);
    if (tree->right != NULL && tree->right->operator == -1)
        two = tree->right->data;
    else if (tree->right != NULL && tree->right->operator != -1 &&
        tree->right->left != NULL && tree->right->left->operator == -1)
        two = tree->right->left->data;
    return (management_left_chevron(var, tree, purge_name_file(two)));
}