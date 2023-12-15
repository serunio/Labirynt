//
// Created by cheese on 26.11.2023.
//

#ifndef LABIRYNT_DRUK_H
#define LABIRYNT_DRUK_H
#include "generacja.h"

void druk(komorka_t** l, int x, int y); //drukuje labirynt
void drukbariera(komorka_t** l, int x, int y); //drukuje gorna lub dolna bariere z uwzgednieniem startu i konca labiryntu
void drukpion(komorka_t** l, int x, int y); //drukuje pionowe sciany
void drukpion_sciezka(komorka_t** l, int x, int y);
void drukpoziom(komorka_t** l, int x, int y); //drukuje poziome sciany
void drukpoziom_sciezka(komorka_t** l, int x, int y);

#endif //LABIRYNT_DRUK_H
