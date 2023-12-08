//
// Created by cheese on 06.12.2023.
//
#include "solver.h"
#include "generacja.h"
#include <stdlib.h>

droga solver(labirynt l, droga* d, int x, int y)
{
    droga* new = malloc(sizeof * new);
    if(l[y][x+1].prawo>0)
    {
        new->step = l[y][x+1];
        new->next = d;
    }
}