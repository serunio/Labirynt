//
// Created by cheese on 06.12.2023.
//
#include "solver.h"
#include "generacja.h"
#include <stdlib.h>

int solver(labirynt l, droga* d, int x, int y, int waga)
{
    if(l[y][x].rodzaj == START)
        return 1;
    if(l[y][x].odwiedzony != 1)
        return 0;
    l[y][x].odwiedzony = 2;
    droga* new = malloc(sizeof * new);
    int r = 0;
    if(l[y][x+1].prawo)
        r = f(l, d, new, x+1, y, &waga);
    if(l[y][x-1].lewo && r == 0)
        r = f(l, d, new, x-1, y, &waga);
    if(l[y+1][x].dol && r == 0)
        r = f(l, d, new, x, y+1, &waga);
    if(l[y-1][x].gora && r == 0)
        r = f(l, d, new, x, y-1, &waga);
    return r;
}

int f(labirynt l, droga* d, droga* new, int x, int y, int* waga)
{
        *waga += l[y][x].prawo;
        if(solver(l, new, x, y, *waga))
        {
            new->step = l[y][x];
            new->next = d;
            return *waga;
        }
        *waga -= l[y][x].prawo;
        return 0;
}

