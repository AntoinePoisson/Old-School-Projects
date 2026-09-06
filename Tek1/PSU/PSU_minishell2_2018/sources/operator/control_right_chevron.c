/*
** EPITECH PROJECT, 2019
** control_right_chevron.c
** File description:
** control right chevron execution
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include "my_shell.h"

static int create_file(char const *file, int *fd)
{
    *fd = open(file, O_CREAT, S_IRUSR | S_IWUSR
        | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    close(*fd);
    *fd = open(file, O_RDWR | O_TRUNC);
    if (*fd == -1)
        return (-1);
    return (0);
}

static void management_right_chevron_son(variable_t *var, tree_t *tree, int fd)
{
    dup2(fd, 1);
    if (check_element_is_operator(tree->left))
        chose_good_operator(var, tree->left);
    else
        exec_arg(var, tree->left->data);
    close(1);
}

static int management_right_chevron(variable_t *var, tree_t *tree, char *file)
{
    int fd = -1;
    int wstatus = 0;
    pid_t pid;

    if ((file == NULL) || (create_file(file, &fd) == -1)
        || ((pid = fork()) == -1)) {
        return (display_error_fork(1, file));
    }
    if (pid == 0) {
        management_right_chevron_son(var, tree, fd);
        my_exit(var, "99999");
    } else
        waitpid(pid, &wstatus, WUNTRACED | WCONTINUED);
    close(fd);
    free(file);
    return (0);
}

int control_right_chevron(variable_t *var, tree_t *tree)
{
    char *two = NULL;

    if (tree == NULL)
        return (84);
    if (tree->right != NULL && tree->right->operator == -1)
        two = tree->right->data;
    else if (tree->right != NULL && tree->right->operator != -1 &&
        tree->right->left != NULL && tree->right->left->operator == -1)
        two = tree->right->left->data;
    return (management_right_chevron(var, tree, purge_name_file(two)));
}