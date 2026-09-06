/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** main.cpp
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <stdbool.h>

// A mettre dans un header
#define FREQ 2
////////////////////////////

void tick(void)
{
    static clock_t timer;
    static bool defined = false;

    if (!defined) {
        timer = clock();
        defined = true;
    }
    while (timer + (CLOCKS_PER_SEC / FREQ) > clock());
    timer += CLOCKS_PER_SEC / FREQ;
        // la clock tick au bon moment aucun décalage et rattrape
        // le retour dû au temps que prend le reste du programme
//    timer = clock();
        // la clock se décale a cause du temps du reste du programme;
}

int main(void)
{
    while (true) {
        tick();
        fprintf(stdout, "Ticked at %f seconds\n", (float)((float)clock() /
        (float)CLOCKS_PER_SEC));
    }
}
