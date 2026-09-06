/*
** EPITECH PROJECT, 2020
** PSU_strace_2019
** File description:
** exists in path
*/

#include "strace.h"

static char *get_path(char * const *env)
{
    for (u_int32_t index = 0; env && *env && env[index]; index++) {
        if (strncmp("PATH=", env[index], 5) == 0) {
            return (strdup(&env[index][5]));
        }
    }
    return (NULL);
}

static inline program_status_t __attribute__ ((always_inline))
display_error_message(const char *message)
{
    const char *error = "strace: Can't stat '%s': No such file or directory\n";

    fprintf(stderr, error, message);
    return (STRACE_EXIT_ERROR);
}

char *my_concat(const char *path, const char *file)
{
    int count = 0;
    char *res = malloc((strlen(path) + strlen(file) + 2));

    if (!path || !file)
        return ("");
    memset(res, '\0', (strlen(path) + strlen(file) + 2));
    strcpy(res, path);
    res[strlen(path)] = '/';
    for (int i = strlen(path) + 1; file[count]; i++, count++)
        res[i] = file[count];
    return (res);
}

program_status_t __attribute__ ((noinline)) __attribute__ ((nonnull(1, 3)))
exists_in_path(const char **av, char * const *env, strace_t *strace)
{
    struct stat sb;
    char *path = NULL;

    if (stat(av[0], &sb) == 0) {
        strace->path = (char *)av[0];
        strace->program_arguments = (char **)av;
        return (STRACE_CONTINUE);
    }
    if ((path = get_path(env)) == NULL)
        return (display_error_message(av[0]));
    for (char *el = strtok(path, ":"); el; el = strtok(NULL, ":")) {
        path = my_concat(el, av[0]);
        if (stat(path, &sb) == 0) {
            strace->path = path;
            strace->program_arguments = (char **)av;
            return (STRACE_CONTINUE);
        }
        free(path);
    }
    return (display_error_message(av[0]));
}

bool cond_loop(int wstatus, struct user_regs_struct regs,
    int size_display, bool condition)
{
    if ((condition && WIFEXITED(wstatus)) ||
        (condition && WIFSIGNALED(wstatus))) {
        return (true);
    } else if (WIFEXITED(wstatus) || WIFSIGNALED(wstatus)) {
        display_sys_call_ret(regs, tab_64[regs.rax],
        size_display + 1, true);
        fprintf(stdout, "+++ exited with %d +++\n",
        WEXITSTATUS(wstatus));
        return (true);
    }
    return (false);
}