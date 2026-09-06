/*
** EPITECH PROJECT, 2019
** control_pipe.c
** File description:
** control pipe execution
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_shell.h"

static void management_pipe_son(variable_t *var, tree_t *tree, int pipe_fd[])
{
    close(pipe_fd[0]);
    dup2(pipe_fd[1], 1);
    close(pipe_fd[1]);
    if (check_element_is_operator(tree->left))
        chose_good_operator(var, tree->left);
    else
        exec_arg(var, tree->left->data);
    close(1);
}

static int management_pipe_parent(variable_t *var, tree_t *tree,
    int pipe_fd[])
{
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    if (check_element_is_operator(tree->right))
        return (chose_good_operator(var, tree->right));
    else
        return (exec_arg(var, tree->right->data));
}

static int management_pipe(variable_t *var, tree_t *tree)
{
    int pipe_fd[2];
    int wstatus = 0;
    int save = dup(0);
    pid_t pid;

    if ((pipe(pipe_fd) == -1) || ((pid = fork()) == -1))
        return (display_error_fork(0, NULL));
    if (pid == 0) {
        management_pipe_son(var, tree, pipe_fd);
        my_exit(var, "0", 0);
    } else {
        wstatus = management_pipe_parent(var, tree, pipe_fd);
        dup2(save, 0);
    }
    return (WEXITSTATUS(wstatus));
}

int control_pipe(variable_t *var, tree_t *tree)
{
    if (tree == NULL)
        return (1);
    return (management_pipe(var, tree));
}
