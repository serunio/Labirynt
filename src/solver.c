#include <stdlib.h>
#include <stdio.h>

#include "solver.h"
#include "labirynt.h"

int solver(komorka_t** l, droga** d, int x, int y, int* waga)
{

    if(l[y][x].odwiedzony != 1)
        return 0;
    l[y][x].odwiedzony = 2;

    int r = 0;

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

int f(komorka_t** l, droga** d, int x, int y, int* waga, int w)
{
        *waga += w;
        if(l[y][x].rodzaj == STOP || solver(l, d, x, y, waga))
        {
            droga* new = malloc(sizeof * new);
            new->step = &l[y][x];
            l[y][x].odwiedzony = 3;
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
            printf("-%03d->[%03d]", d->waga, d->step->numer);
            ostatniakomorka = d->step->numer;
            tmp = d;
            d = d->next;
            free(tmp);
        }
    }
    printf("\n");
}

void solver2(labirynt* lab)
{
    komorka_t* a = lab->stop;
    komorka_t* n;
    droga d1;
    droga d2;
    droga* d = malloc(sizeof * d);
    while(1)
    {
        n = &lab->komorki[a->y][a->x + 1];
        if(f2(n, d))
            continue;
        n = &lab->komorki[a->y][a->x - 1];
        if(f2(n, d))
            continue;
        n = &lab->komorki[a->y + 1][a->x];
        if(f2(n, d))
            continue;
        n = &lab->komorki[a->y - 1][a->x];
        if(f2(n, d))
            continue;
    }
}

int f2(komorka_t* n, droga* d)
{

}