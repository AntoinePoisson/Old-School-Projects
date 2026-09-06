/*
** EPITECH PROJECT, 2018
** is_pushswap
** File description:
** is_pushswap
*/

#include "radix.h"

int check_utility_united(control_list_t **SRC, int size, int united)
{
    int modif = 0;
    char *string;
    int size_string = 0;
    linked_list_t *save = (*SRC)->head;

    for (int i = (*SRC)->length; i > 0; i--) {
        string = (save)->data;
        size_string = my_strlen(string);
        if (string[0] == '-')
            size_string--;
        if (size_string < size)
            return (1);
        if (modif == 0) {
            my_revstr(string);
            if ((string[size - 1] - '0') == united) {
                my_revstr(string);
                return (1);
            }
            else
                my_revstr(string);
        }
        if (modif == 0)
            save = save->next;
    }
    return (0);
}

int is_pushswap(control_list_t **l_a, control_list_t **l_b, char *max, int ac)
{
    int size_max = my_getnbr(max);
    int linked_list = 2;
    int size_string = 0;
    char *string;
    int modif = 3;
    int nbr_push = ac;

    for (int size = 1; size <= size_max; size++) {
        nbr_push = ac;
        if (linked_list == 2) {
            if (modif != 3) {
                for (int i = ac; i > 0; i--) {
                    take_element_one(&(*l_a), &(*l_b));
                }
                for (int i = ac; i > 0; i--) {
                    take_element_two(&(*l_a), &(*l_b));
                    rotation_first_list_one(&(*l_a));
                }
            }
            modif = 0;
            linked_list = 1;
        }
        else if (linked_list == 1) {
            for (int i = ac; i > 0; i--) {
                take_element_two(&(*l_a), &(*l_b));
            }
            for (int i = ac; i > 0; i--) {
                take_element_one(&(*l_a), &(*l_b));
                rotation_first_list_two(&(*l_b));
            }
            linked_list = 2;
        }
        for (int i = 0; i < ac; size_string = 0, modif = 0)
            for (int united = 0; united <= 9 && i < ac; united++) {
                nbr_push = i;
                if ((linked_list == 1 &&
                    check_utility_united(l_a, size, united) == 0)
                    || (linked_list == 2 &&
                    check_utility_united(l_b, size, united) == 0));
                else
                    for (int count_tour = 0; count_tour < (ac - nbr_push) && i
                        < ac; count_tour++, modif = 0) {
                        if (linked_list == 1) {
                            string = (*l_a)->head->data;
                            size_string = my_strlen(string);
                            if (string[0] == '-')
                                size_string--;
                            if (size_string < size) {
                                take_element_one(&(*l_a), &(*l_b));
                                modif = 1;
                                i++;
                            }
                            if (modif == 0) {
                                my_revstr(string);
                                if ((string[size - 1] - '0') == united) {
                                    my_revstr(string);
                                    take_element_one(&(*l_a), &(*l_b));
                                    modif = 1;
                                    i++;
                                }
                                else
                                    my_revstr(string);
                            }
                            if (modif == 0) {
                                rotation_first_list_one(&(*l_a));
                            }
                        } else {
                            string = (*l_b)->head->data;
                            size_string = my_strlen(string);
                            if (string[0] == '-')
                                size_string--;
                            if (size_string < size) {
                                take_element_two(&(*l_a), &(*l_b));
                                modif = 1;
                                i++;
                            }
                            if (modif == 0) {
                                my_revstr(string);
                                if ((string[size - 1] - 48) == united) {
                                    my_revstr(string);
                                    take_element_two(&(*l_a), &(*l_b));
                                    modif = 1;
                                    i++;
                                }
                                else
                                    my_revstr(string);
                            }
                            if (modif == 0)
                                rotation_first_list_two(&(*l_b));
                        }
                    }
            }
    }
    nbr_push = 0;
    if (linked_list == 1){
        for (int i = 0; i < ac; i++) {
            string = (*l_b)->head->data;
            if (string[0] != '-') {
                take_element_two(&(*l_a), &(*l_b));
                nbr_push++;
            }
            else
                rotation_first_list_two(&(*l_b));
        }
        if (nbr_push != ac) {
            for (int i = ac - nbr_push; i >= 0 ; i--) {
                rotation_end_list_two(&(*l_b));
                take_element_two(&(*l_a), &(*l_b));
            }
        }
        return (0);
    }
    for (int i = 0; i < ac; i++) {
        string = (*l_a)->head->data;
        if (string[0] != '-') {
            nbr_push++;
            take_element_one(&(*l_a), &(*l_b));
        }
        else
            rotation_first_list_one(&(*l_a));
    }
    for (int i = nbr_push; i > 0; i--) {
        take_element_two(&(*l_a), &(*l_b));
        rotation_first_list_one(&(*l_a));
    }
    return (0);
}
