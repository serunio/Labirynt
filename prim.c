
#include "prim.h"
#include "stdlib.h"
#include <stdio.h>
void generacja_prim(labirynt* lab, int x, int y, int seed)
{
    srand(seed);
    lab->l[y][x].odwiedzony = 1;                                  //pierwsza komorka ozanaczona jako odwiedzona

    lab->lista.elementy = malloc(100*sizeof(komorka_t*));    //stworzona lista na komorki sąsiadujące z odwiedzonymi
    lab->lista.rozmiar = -1;

    dodajsasiadow(lab, &lab->l[y][x]);                   //dodanie sąsiadow pierwszej komórki do listy
    int* i;
    komorka_t* k;       //losowy element z listy
    komorka_t* n;       //losowa komorka obok losowo wybranego k
    int r;
    while((r = lab->lista.rozmiar) >= 0)
    {
        int waga = seed%100 +1 ;    //losowa waga z zakresu 1-100
        k = r > 0 ? lab->lista.elementy[rand()%(lab->lista.rozmiar)] : lab->lista.elementy[0];

        int a = 1000;
        while(r >= 0)   //pętla tworzy przejście między losowo wybranym elementem z listy (nieodwiedzonym) a sąsiadującą z nim komórką labiryntu
        {
            a--;
            if(a == 0){srand(rand()); a = 1000;}

            i = losuj(rand());
            n = &lab->l[k->y+i[0]][k->x+i[1]];
            if(n->odwiedzony == 1)
            {
                if(i[1] == 1)
                {
                    k->prawo = n->lewo = waga;
                    break;
                } else
                if(i[1] == -1)
                {
                    k->lewo = n->prawo = waga;
                    break;
                } else
                if(i[0] == 1)
                {
                    k->dol = n->gora = waga;
                    break;
                } else
                if(i[0] == -1)
                {
                    k->gora = n->dol = waga;
                    break;
                }
            }
            free(i);
        }
        k->odwiedzony = 1;
        dodajsasiadow(lab, k);
        usunzlisty(&lab->lista, k);
    }
}

void dodajsasiadow(labirynt* lab, komorka_t* k)
{
    komorka_t* n;
    if(!(n = &lab->l[k->y][k->x+1])->odwiedzony)
    {
        dodajdolisty(lab, n);
    }
    if(!(n = &lab->l[k->y][k->x-1])->odwiedzony)
    {
        dodajdolisty(lab, n);
    }
    if(!(n = &lab->l[k->y+1][k->x])->odwiedzony)
    {
        dodajdolisty(lab, n);
    }
    if(!(n = &lab->l[k->y-1][k->x])->odwiedzony)
    {
        dodajdolisty(lab, n);
    }
}

