/*
** EPITECH PROJECT, 2018
** test_101pong
** File description:
** test_pong101
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <math.h>

#define EXIT_ERROR 84
#define UNVALID_CHARAC 84

typedef struct coordinate_s
{
    float x;
    float y;
    float z;
} coordinate_t;

void case_option_h(void);
void display_result(coordinate_t *vector_1, coordinate_t *vector_2, int n);
void vector_angle(coordinate_t *vector);
void is_extension_check_errors(int ac, coordinate_t *vector_1,
coordinate_t *vector_2, char *av[]);
void check_errors(int ac, coordinate_t *vector_1, coordinate_t *vector_2,
                  char *av[]);
coordinate_t *create_vector(float x, float y, float z);
coordinate_t *somme_vector(coordinate_t *vector_1, coordinate_t *vector_2);
coordinate_t *difference_vector(coordinate_t *vector_1, coordinate_t *vector_2);
coordinate_t *produit_vector_real(float R, coordinate_t *vector);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_extension_check_errors, is_extension_check_errors_h, .init =
     redirect_all_std)
{
    int ac = 8;
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    char **av = malloc(sizeof(char *) * 2);

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(2, 2, 2);
    av[1] = "-h";
    is_extension_check_errors(ac, vector_1, vector_2, av);
    cr_stdout_match_str("USAGE\n      ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRI"
                        "PTION\n       x0   ball abscissa at time t - 1\n     "
                        "  y0   ball ordinate at time t - 1\n       z0   ball "
                        "altitude at time t - 1\n       x1   ball abscissa at "
                        "time t\n       z1   ball ordinate at time t\n       y"
                        "1   ball altitude at time t\n       n    time shift ("
                        "greater than or equal to zero, integer)\n");
    free(vector_1);
    free(vector_2);
    free(av);
}

Test(is_extension_check_errors, is_extension_check_errors, .init =
     redirect_all_std)
{
    int ac = 8;
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    char **av = malloc(sizeof(char *) * 2);

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(2, 2, 2);
    av[1] = "12";
    is_extension_check_errors(ac, vector_1, vector_2, av);
    cr_stdout_match_str("The number of arguments is insufficient\n");
    free(vector_1);
    free(vector_2);
    free(av);
}

Test(check_errors, check_errors, .init = redirect_all_std)
{
    int ac = 8;
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    char **av = malloc(sizeof(char *) * 8);

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(2, 2, 2);
    av[1] = "12";
    av[2] = "1";
    av[3] = "2";
    av[4] = "3";
    av[5] = "4";
    av[6] = "+5";
    av[7] = "6";
    is_extension_check_errors(ac, vector_1, vector_2, av);
    cr_stdout_match_str("Invalid input\n");
    free(vector_1);
    free(vector_2);
    free(av);
}

Test(check_errors, check_errors_two, .init = redirect_all_std)
{
    int ac = 8;
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    char **av = malloc(sizeof(char *) * 8);

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(2, 2, 2);
    av[1] = "12";
    av[2] = "1";
    av[3] = "2";
    av[4] = "3";
    av[5] = "4";
    av[6] = "5";
    av[7] = "-6";
    is_extension_check_errors(ac, vector_1, vector_2, av);
    cr_stdout_match_str("Invalid input\n");
    free(vector_1);
    free(vector_2);
    free(av);
}

Test(display_result, display_result, .init = redirect_all_std)
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    int n = 4;

    vector_1->x = 4;
    vector_1->y = 4;
    vector_1->z = 4;
    vector_2->x = 4;
    vector_2->y = 4;
    vector_2->z = 4;
    display_result(vector_1, vector_2, n);
    cr_stdout_match_str("The velocity vector of the ball is:\n(0.00, 0.00, 0.00"
                        ")\nAt time t + 4, ball coordinates will be:\n(0.00, "
                        "0.00, 0.00)\n");
    free(vector_1);
    free(vector_2);
}

Test(vector_angle, angle_cannot_calcul_zero, .init = redirect_all_std)
{
    coordinate_t *vector = malloc(sizeof(*vector));

    vector->x = 4.00;
    vector->y = 4.00;
    vector->z = 4.00;
    vector_angle(vector);
    cr_stdout_match_str("The ball won’t reach the bat.\n");
    free(vector);
}

Test(vector_angle, angle_cannot_calcul, .init = redirect_all_std)
{
    coordinate_t *vector = malloc(sizeof(*vector));

    vector->x = 31.00;
    vector->y = 33.00;
    vector->z = -30.00;
    vector_angle(vector);
    cr_stdout_match_str("The ball won’t reach the bat.\n");
    free(vector);
}

Test(vector_angle, angle_calcul, .init = redirect_all_std)
{
    coordinate_t *vector = malloc(sizeof(*vector));

    vector->x = -39.40;
    vector->y = 33.00;
    vector->z = -10.00;
    vector_angle(vector);
    cr_stdout_match_str("The incidence angla is:\n16.57degrees\n");
    free(vector);
}

Test(create_vector, create, .init = redirect_all_std)
{
    coordinate_t *vector = malloc(sizeof(*vector));
    float x = 4;
    float z = 4;
    float y = 4;

    create_vector(x, y, z);
    printf("%.2f %.2f %.2f", vector->x, vector->y, vector->z);
    cr_stdout_match_str("4.00 4.00 4.00");
    free(vector);
}

Test(somme_vector, somme, .init = redirect_all_std)
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(2, 2, 2);
    vector_1 = somme_vector(vector_1, vector_2);
    printf("%.2f %.2f %.2f", vector_1->x, vector_1->y, vector_1->z);
    cr_stdout_match_str("4.00 4.00 4.00");
    free(vector_1);
    free(vector_2);
}

Test(somme_vector, somme_zero, .init = redirect_all_std)
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));

    vector_1 = create_vector(0, 0, 0);
    vector_2 = create_vector(0, 0, 0);
    vector_1 = somme_vector(vector_1, vector_2);
    printf("%.2f %.2f %.2f", vector_1->x, vector_1->y, vector_1->z);
    cr_stdout_match_str("0.00 0.00 0.00");
    free(vector_1);
    free(vector_2);
}

Test(difference_vector, difference, .init = redirect_all_std)
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *vector_2 = malloc(sizeof(*vector_2));
    coordinate_t *difference = malloc(sizeof(*difference));

    vector_1 = create_vector(2, 2, 2);
    vector_2 = create_vector(6, 6, 6);
    difference = difference_vector(vector_1, vector_2);
    printf("%.2f %.2f %.2f", difference->x, difference->y, difference->z);
    cr_stdout_match_str("4.00 4.00 4.00");
    free(difference);
    free(vector_1);
    free(vector_2);
}

Test(produit_vector, difference, .init = redirect_all_std)
{
    coordinate_t *vector_1 = malloc(sizeof(*vector_1));
    coordinate_t *produit = malloc(sizeof(*produit));
    float R = 2;

    vector_1 = create_vector(2, 2, 2);
    produit = produit_vector_real(R, vector_1);
    printf("%.2f %.2f %.2f", produit->x, produit->y, produit->z);
    cr_stdout_match_str("4.00 4.00 4.00");
    free(produit);
    free(vector_1);
}

Test(case_option, option, .init = redirect_all_std)
{
    case_option_h();
    cr_stdout_match_str("USAGE\n      ./101pong x0 y0 z0 x1 y1 z1 n\n\nDESCRI"
                        "PTION\n       x0   ball abscissa at time t - 1\n"
                        "       y0   ball ordi"
                        "nate at time t - 1\n       z0   ball altitude at time "
                        "t - 1\n       x"
                        "1   ball abscissa at time t\n       z1   ball ordinate"
                        " at time t\n   "
                        "    y1   ball altitude at time t\n       n    time"
                        " shift (greater tha"
                        "n or equal to zero, integer)\n");
}
