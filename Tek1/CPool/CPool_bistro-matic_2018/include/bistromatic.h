/*
** EPITECH PROJECT, 2018
** bistromatic
** File description:
** Lib bistromatic
*/

#ifndef BISTRO_H
#define BISTRO_H
#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_EXPR     84
#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84
#define EXIT_PARENTH  84
#define MULTIPLE_SYM  84
#define LETTER_FOUND  84
#define TIME_OUT      84
#define DIV_OR_MOD_O  84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"
#define DIV_BY_O_MSG     "division by 0"
#define MOD_BY_O_MSG     "modulo by 0"
#define NOT_HANDLED      "syntax error"
#define TIME_OUT_MSG     "exit: will time out"

char *eval_expr(char const *base, char const *ops,
                char const *expr, unsigned int size);
char result_rpn[9999999];
char *rework_string(char const str[]);

typedef struct stockage_s
{
    char data;
    struct stockage_s *next;
} stockage_t;

typedef struct pile_s
{
    stockage_t *first;
} pile_t;

char *end(int carry, char *chaine_three, int a);
char *is_extension_multip(int *a, int i, char *first, char *chaine_three);
void *revstring(char *first, char *second);
void is_carry_mul(int *retenue, int *total);
char *is_extension_two_multip(char *result, char *chaine_three, int i);
char *is_extension_three_multip(int total, char *chaine_three, int *a);
char *infin_mul_second(char *first, char *second, int negative_case);
char *is_neg_mul_posi(char *first, char *second, int *negative_case);
char *is_posi_mul_neg(char *first, char *second, int *negative_case);
char *my_itoa(int nbr, int neg);
int is_case_zero(int nbr);
int number(char **str);
int compare_precedence(char const *str, pile_t *pile, int i);
int summands(char **str);
int factors(char **str);
char **my_str_to_word_array(char const *str);
int word_count(char const *str);
int is_operator(char c);
char *calculator(char *first_number, char operator, char *second_number);
char *my_rpn(char const *str);
void push(pile_t *pile, char charac);
char pop(pile_t *pile);
char is_top_pile(pile_t *pile);
char *my_itoa(int nbr, int neg);
int is_case_zero(int nbr);
int is_extension_compare_precedence(char const *str, pile_t *pile, int i);
int is_extension_compare_precedence_two(char const *str, int i, pile_t *pile);
int is_extension_operator_pile(char result[], int a, char reserve[], int i);
int is_extension_two_operator(char reserve[], int i, int a, char result[]);
int is_cas_no_parenthese(char reserve[], int i);
char *is_extension_my_rpm(pile_t *pile, int a, int i, char const *str);
int is_extension_my_rpm_two(pile_t *pile, int a, int i, char const *str);
int is_extension_my_rpm_three(int a, char const *str, int i);
char *infin_add(char *first, char *second);
char *infin_add_second(char *first, char *second);
char *infin_sub_second(char *first, char *second, int negative_case);
int is_extension_retenue_sub(int *r, int *retenue);
char *is_infin_next(int i, int r, char string_three[], int negative_case);
void is_case_end_ft(char *first, int i, int *end_ft);
void is_case_end_sd(char *second, int i, int *end_sd);
void is_reverser_str(char *first, char *second);
char *selection_add(char chaine_three[], int r, int i, char *first);
char *selection_sub(char string_three[], int r, int i, int negative_case);
int is_extension_end_b(char *second, int i, int exit_negative);
int is_extension_end_a(char *first, int i, int exit_negative);
int is_extension_retenue(int *r, int *retenue);
int is_extension_exit_negative(char *first, char *second);
int is_zero_zero(char *first, char *second);
int checkage_if_nbr_is_negative_for_espace(int i, char const *str);
int checkage_if_nbr_negative(int a, char const *str);
char *infin_mod(char *divided, char* divisor);
char *infin_div(char *divided, char* divisor);
char *infin_sub(char *first, char *second);
char *selection(char chaine_three[], int result, int i, char *para_useless);
char *extend_infmul(char *result, char *chaine_three);
char *end(int carry, char *chaine_three, int a);
char *multip(char *first, char *second, char *chaine_three, int negative_case);
char *infin_mul_second(char *first, char *second, int negative_case);
char *infin_mul(char *first, char *second);
void check_unary_op(char *expr);
void check_base(char const *base);
void check_ops(char const *ops);
void check_arg_in_string(char *str, char char_to_test);
void check_multiple_symboles(char *base, char *ops);
int size_equal(char *divided, char *divisor);
int is_extension_my_rpm_four(int i, int a, pile_t *pile, char const *str);

#endif
