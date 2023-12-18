//
// Created by cheese on 06.12.2023.
//

#ifndef LABIRYNT_SOLVER_H
#define LABIRYNT_SOLVER_H

#include "generacja.h"

typedef struct droga
{
    komorka_t* step;
    struct droga* next;
    int waga;

}droga;

int solver(komorka_t**, droga**, int x, int y, int* waga);
int f(komorka_t** l, droga** d, int x, int y, int* waga, int nowa_waga);
void writer(droga*, int);
#endif //LABIRYNT_SOLVER_H
