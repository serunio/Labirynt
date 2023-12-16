//
// Created by cheese on 26.11.2023.
//

#ifndef LABIRYNT_DRUK_H
#define LABIRYNT_DRUK_H
#include "generacja.h"

void druk(labirynt* lab, int x, int y, int tryb); //drukuje labirynt //tryb: 0 - pusty labirynt, 1 - labirynt ze sciezka, 2 - labirynt z numerami komorek

void drukbariera(komorka_t** l, int x, int y); //drukuje gorna lub dolna bariere z uwzgednieniem startu i konca labiryntu

//drukuje pionowe sciany
void drukpion_numery(komorka_t** l, int x, int y);
void drukpion_sciezka(komorka_t** l, int x, int y);
void drukpion_pusty(komorka_t** l, int x, int y);

//drukuje poziome sciany
void drukpoziom(komorka_t** l, int x, int y);
void drukpoziom_sciezka(komorka_t** l, int x, int y);


#endif //LABIRYNT_DRUK_H
