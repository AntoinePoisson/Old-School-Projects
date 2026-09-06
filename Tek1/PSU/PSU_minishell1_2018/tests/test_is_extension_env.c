/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_lib.h"
#include "my_struct.h"

int change_value_env(var_t *var, char const *element, char const *data);
int research_env(var_t *var, char const *str, int *i);
int is_extension_change_value_env(var_t *var, char *result);
char *find_env(var_t *var, char const *str);
int push(var_t *var, char const *str);
int check_error(var_t *var, char *env[]);
int pop(var_t *var);

Test(pop, pop)
{
    var_t *var = malloc(sizeof(*var));
    char **env = malloc(sizeof(char *) * 2);
    char *data_env = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin";
    char data[] = "unsetenv PATH";

    env[0] = data_env;
    env[1] = NULL;
    var->env = env;
    check_error(var, env);
    var->arg = data;
    var->arg_two_d = my_str_to_word_array(var->arg);
    if (var != NULL || env != NULL) {
        cr_expect_neq(pop(var), 1);
        free(var);
        free(env);
    }
}