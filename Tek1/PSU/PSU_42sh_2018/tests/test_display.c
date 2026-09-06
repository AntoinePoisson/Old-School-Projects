/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_shell.h"

void redirect_all_stdou(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(display_env, display_env_return_value, .init = redirect_all_stdou)
{
    variable_t *var = malloc(sizeof(variable_t));

    if (var != NULL) {
        var->env = NULL;
        cr_expect_eq(display_env(var), 0);
        free(var);
    }
}

Test(display_env, display_env_null, .init = redirect_all_stdou)
{
    variable_t *var = malloc(sizeof(variable_t));

    if (var != NULL) {
        var->env = malloc(sizeof(char *) * 1);
        var->env[0] = NULL;
        if (var->env != NULL) {
            cr_expect_eq(display_env(var), 0);
            free(var->env);
        }
        free(var);
    }
}

Test(display_env, display_env, .init = redirect_all_stdou)
{
    variable_t *var = malloc(sizeof(variable_t));
    char result[] = "PATH=KAKA";

    if (var != NULL) {
        var->env = malloc(sizeof(char *) * 2);
        if (var->env != NULL) {
            var->env[0] = malloc(sizeof(char) * my_strlen(result));
            var->env[0] = result;
            var->env[1] = NULL;
            display_env(var);
            cr_stdout_match_str("PATH=KAKA\n");
            free(var->env);
        }
        free(var);
    }
}

Test(display, display, .init = redirect_all_stdou)
{
    display();
    cr_stdout_match_str("[/home/Crow/PSU/PSU_minishell1_2018] $> ");
}
