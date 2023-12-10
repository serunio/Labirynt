//
// Created by cheese on 06.12.2023.
//

#ifndef LABIRYNT_SOLVER_H
#define LABIRYNT_SOLVER_H

#include "generacja.h"

typedef struct droga
{
    komorka_t step;
    struct droga* next;

}droga;

int solver(labirynt, droga*, int x, int y, int waga);
int f(labirynt l, droga* d, droga* new, int x, int y, int* waga);
void writer(droga);
#endif //LABIRYNT_SOLVER_H
