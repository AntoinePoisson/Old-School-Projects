/*
** EPITECH PROJECT, 2019
** control_double_right_chevron.c
** File description:
** control double right chevron execution
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "my_shell.h"

static int create_file_two(char const *file, int *fd)
{
    *fd = open(file, O_CREAT, S_IRUSR | S_IWUSR
        | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    close(*fd);
    *fd = open(file, O_RDWR | O_APPEND);
    if (*fd == -1)
        return (-1);
    return (0);
}

static int management_double_right_chevron_son(variable_t *var, tree_t *tree,
    int fd)
{
    int value = 0;

    dup2(fd, 1);
    if (check_element_is_operator(tree->left))
        value = chose_good_operator(var, tree->left);
    else
        value = exec_arg(var, tree->left->data);
    close(1);
    return (value);
}

static int management_double_right_chevron(variable_t *var, tree_t *tree,
    char *file)
{
    int fd = -1;
    int wstatus = 0;
    pid_t pid;

    if ((file == NULL) || (create_file_two(file, &fd) == -1)
        || ((pid = fork()) == -1))
        return (display_error_fork(1, file));
    if (pid == 0) {
        wstatus = management_double_right_chevron_son(var, tree, fd);
        my_exit(var, my_itoa(wstatus, my_isneg(wstatus)), 0);
    } else
        waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
    close(fd);
    free(file);
    return (WEXITSTATUS(wstatus));
}

int control_double_right_chevron(variable_t *var, tree_t *tree)
{
    char *two = NULL;

    if (tree == NULL)
        return (1);
    if (tree->right != NULL && tree->right->operator == -1)
        two = tree->right->data;
    else if (tree->right != NULL && tree->right->operator != -1 &&
        tree->right->left != NULL && tree->right->left->operator == -1)
        two = tree->right->left->data;
    return (management_double_right_chevron(var, tree, purge_name_file(two)));
}