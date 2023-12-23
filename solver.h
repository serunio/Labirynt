#ifndef LABIRYNT_SOLVER_H
#define LABIRYNT_SOLVER_H

#include "labirynt.h"

int solver(komorka_t**, droga**, int x, int y, int* waga); //rozwiązuje labirynt
int f(komorka_t** l, droga** d, int x, int y, int* waga, int nowa_waga); //funkcja pomocnicza do solver
void writer(droga*, int); //wypisuje diagram przejść z wagami
#endif //LABIRYNT_SOLVER_H
