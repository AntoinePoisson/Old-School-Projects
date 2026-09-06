/*
** EPITECH PROJECT, 2019
** control_double_left_chevron.c
** File description:
** control double left chevron execution
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "my_shell.h"

static void management_double_left_chevron_son(char const *file, int pipe_fd[])
{
    char *element = NULL;

    close(pipe_fd[0]);
    my_putstr("? ");
    for (element = get_next_line(0); element != NULL &&
        my_strcmp(element, file) != 0; element = get_next_line(0)) {
        if (element != NULL && my_strcmp(element, file) != 0)
            my_putstr("? ");
        write(pipe_fd[1], element, my_strlen(element));
        write(pipe_fd[1], "\n", 1);
        free(element);
        element = NULL;
    }
    close(pipe_fd[1]);
}

static int management_double_left_chevron_pare(variable_t *var,
    tree_t *tree, int pipe_fd[], pid_t pid)
{
    int wstatus = 0;

    close(pipe_fd[1]);
    waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
    dup2(pipe_fd[0], 0);
    close(pipe_fd[0]);
    if (check_element_is_operator(tree->left))
        return (chose_good_operator(var, tree->left));
    else
        return (exec_arg(var, tree->left->data));
}

static int management_double_left_chevron(variable_t *var, tree_t *tree,
    char *file)
{
    int pipe_fd[2];
    pid_t pid;
    int wstatus = 0;
    int save = dup(0);

    if ((file == NULL) || pipe(pipe_fd) == -1 || ((pid = fork()) == -1))
        return (84);
    if (pid == 0) {
        management_double_left_chevron_son(file, pipe_fd);
        my_exit(var, "99999", 0);
    } else {
        wstatus = management_double_left_chevron_pare(var, tree, pipe_fd, pid);
        dup2(save, 0);
    }
    free(file);
    return (wstatus);
}

int control_double_left_chevron(variable_t *var, tree_t *tree)
{
    char *two = NULL;

    if (tree == NULL)
        return (84);
    if (tree->right != NULL && tree->right->operator == -1)
        two = tree->right->data;
    else if (tree->right != NULL && tree->right->operator != -1 &&
        tree->right->left != NULL && tree->right->left->operator == -1)
        two = tree->right->left->data;
    return (management_double_left_chevron(var, tree, purge_name_file(two)));
}