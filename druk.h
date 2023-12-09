//
// Created by cheese on 26.11.2023.
//

#ifndef LABIRYNT_DRUK_H
#define LABIRYNT_DRUK_H
#include "generacja.h"

void druk(labirynt l, int x, int y, int seed); //drukuje labirynt
void drukbariera(labirynt l, int x, int y); //drukuje gorna lub dolna bariere z uwzgednieniem startu i konca labiryntu
void drukpion(labirynt l, int x, int y); //drukuje pionowe sciany
void drukpoziom(labirynt l, int x, int y); //drukuje poziome sciany

#endif //LABIRYNT_DRUK_H
