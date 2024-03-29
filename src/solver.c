#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "labirynt.h"

float solver(komorka** l, droga** d, int x, int y, float* waga)
{
    //sprawdzenie czy komorka byla juz odwiedzona
    if(l[y][x].status != 1)
        return 0;
    l[y][x].status = 2;

    float r = 0;

    if(l[y][x].prawo)
        r = f(l, d, x+1, y, waga, l[y][x].prawo);
    if(l[y][x].lewo && r == 0)
        r = f(l, d, x-1, y, waga, l[y][x].lewo);
    if(l[y][x].dol && r == 0)
        r = f(l, d, x, y+1, waga, l[y][x].dol);
    if(l[y][x].gora && r == 0)
        r = f(l, d, x, y-1, waga, l[y][x].gora);
    return r;
}

float f(komorka** l, droga** d, int x, int y, float* waga, float w)
{
        *waga += w;
        if(l[y][x].rodzaj == STOP || solver(l, d, x, y, waga))
        {
            droga* new = malloc(sizeof * new);
            new->step = &l[y][x];
            l[y][x].status = 3;
            new->waga = w;
            new->next = *d;
            *d = new;
            return *waga;
        }
        *waga -= w;
        return 0;
}

void writer(droga* d, int ostatniakomorka)
{
    droga* tmp;
    printf("Przejscie: ");
    while(d!=NULL)
    {
        printf("\n[%03d]", ostatniakomorka);
        for (int i = 1; i < 10 && d != NULL; i++) {
            printf(d->waga == 10.00 ? "-%.1f->[%03d]" : "-%.2f->[%03d]", d->waga, d->step->numer);
            ostatniakomorka = d->step->numer;
            tmp = d;
            d = d->next;
            free(tmp);
        }
    }
    printf("\n");
}
