#ifndef LABIRYNT_SOLVER_H
#define LABIRYNT_SOLVER_H

#include "labirynt.h"

float solver(komorka**, droga**, int x, int y, float* waga); //rozwiązuje labirynt
float f(komorka** l, droga** d, int x, int y, float* waga, float nowa_waga); //funkcja pomocnicza do solver
void writer(droga*, int); //wypisuje diagram przejść z wagami
#endif //LABIRYNT_SOLVER_H
