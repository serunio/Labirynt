//
// Created by cheese on 26.11.2023.
//

#ifndef LABIRYNT_DRUK_H
#define LABIRYNT_DRUK_H
#include "generacja.h"
void drukpion0(int* r, int x);
void drukpoziom0(int* r, int* d, int x);
void drukbariera0(int x, int seed);
void druk0(int** pionowe, int** poziome, int x, int y, int seed);

void druk(labirynt l, int x, int y, int seed);
void drukbariera(labirynt l, int x, int y);
void drukpion(labirynt l, int x, int y);
void drukpoziom(labirynt l, int x, int y);
#endif //LABIRYNT_DRUK_H
