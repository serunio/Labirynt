//
// Created by x7kub on 17/12/2023.
//
#include <stdio.h>
#include <stdlib.h>

#include "wilson.h"
#include "generacja.h"
#include "solver.h"
#include "druk.h"

void generacjawilson(labirynt* lab, int seed)
{
    srand(seed);
    lab->lista.elementy = malloc(lab->x * lab->y * sizeof(komorka_t*));
    lab->lista.rozmiar = -1;
    for(int i = 1; i <= lab->y; i++)
    {
        for(int j = 1; j <= lab->x; j++)
        {
            dodajdolisty(lab, &lab->l[i][j]);
        }
    }
    komorka_t* k = lab->lista.elementy[rand()%(lab->lista.rozmiar)];
    k->odwiedzony = 1;
    //printf("dodano %i", k->numer);
    usunzlisty(&lab->lista, k);
    int r;
    int a = 1;
    while((r = lab->lista.rozmiar) >= 0)
    {
        //printf("\nrozmiar listy: %i\n", r);
        seed = rand();
        //losuj komorke z listy
        komorka_t* n = r > 0 ? lab->lista.elementy[rand()%(lab->lista.rozmiar)] : lab->lista.elementy[0];
        n->odwiedzony = 3;
        usunzlisty(&lab->lista, n);
        //printf(", ide od %i", n->numer);
        //idz losowo az znajdziesz odwiedzona komorke
       // printf("\nPrzejscie: ");
        randomwalk(lab, n->x, n->y, seed);
        n->odwiedzony = 1;

       // if(a==1)
        //    druk(lab, 20, 20, 2);
       // a--;
    }
}

void randomwalk(labirynt* lab, int x, int y, int seed)
{
    srand(seed);

    droga* d = malloc(sizeof(*d));
    komorka_t* k = &lab->l[y][x]; //aktualna
    komorka_t* n; //nastepna
    d->step = k;
    int* i;
    int a = 1000;
    while(k->odwiedzony != 1)
    {
            a--;
            if(a == 0) {srand(seed); a = 1000;}
            seed = rand();
            //wybranie kierunku
            i = losuj(seed);
            n = &lab->l[k->y+i[0]][k->x+i[1]];
            //printf(" %i ", n->numer);
            //sprawdzenie czy to nie sciana, jak tak to wybranie jeszcze raz
            if(n->odwiedzony == -1)
            {
            //    printf(" | ");
                continue;
            }
            //sprawdzenie czy to pętla
            if(n->odwiedzony == 3)
            {
                //seed++;
                //srand(seed);

              //  printf("o");
                //jeżeli to pętla to cofamy sie po drodze az do tej komorki i jedziemy dalej
                while(d->step->numer != n->numer)
                {
                    d->step->odwiedzony = 0;
                    d = d->next;
                }
                k = n;
            }
            else {
                //jeżeli to nie pętla to dodajemy komorke do drogi i jedziemy od niej dalej
              //  printf(" + ");
                droga *new = malloc(sizeof *new);
                k = n;
                if (k->odwiedzony != 1)
                    k->odwiedzony = 3;
                new->step = k;
                new->next = d;
                d = new;
            }


    }
   while(d->step->numer != lab->l[y][x].numer)
   {
       int waga = seed%100 +1;
       komorka_t* a = d->step;
       komorka_t* b = d->next->step;
       a->odwiedzony = 1;
       //printf("\ndodano %i", a->numer);
       usunzlisty(&lab->lista, a);
       i[0] = b->y - a->y;
       i[1] = b->x - a->x;
       d = d->next;
       if(i[1] == 1) {
           a->prawo = b->lewo = waga;
       } else
       if(i[1] == -1) {
           a->lewo = b->prawo = waga;
       } else
       if(i[0] == 1) {
           a->dol = b->gora = waga;
       } else
       if(i[0] == -1) {
           a->gora = b->dol = waga;
       }
   }
}