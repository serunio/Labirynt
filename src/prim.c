#include "prim.h"
#include <stdlib.h>

void generacja_prim(labirynt* lab, int x, int y, int seed)
{
    srand(seed);
    komorka** komorki = lab->komorki;
    komorki[y][x].status = 1;                      //pierwsza komorka ozanaczona jako odwiedzona

    lista* lista = &lab->lista;
    lista->elementy = malloc(150*sizeof(komorka*));    //stworzona lista na komorki sąsiadujące z odwiedzonymi
    lista->rozmiar = -1;

    dodajsasiadow(lab, &komorki[y][x]);        //dodanie sąsiadow pierwszej komórki do listy
    int* i;
    komorka* k;       //losowy element z listy
    komorka* n;       //losowa komorka obok losowo wybranego k
    int r;
    while((r = lista->rozmiar) >= 0)
    {
        float waga = (float)(rand()%1000 +1)/100;    //losowa waga z zakresu 1-10

        k = lista->elementy[rand()%(r + 1)];

        int a = 1000;
        while(1)   //pętla tworzy przejście między losowo wybranym elementem z listy (nieodwiedzonym) a sąsiadującą z nim komórką labiryntu
        {
            a--;
            if(a == 0){srand(rand()); a = 1000;} //odświeżenie rand zapobiegające zapętleniom

            i = losuj(rand());
            n = &komorki[k->y+i[0]][k->x+i[1]];
            if(n->status == 1)
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
        k->status = 1;
        dodajsasiadow(lab, k);
        usunzlisty(lista, k);
    }
}

void dodajsasiadow(labirynt* lab, komorka* k)
{
    komorka* n;
    lista* l = &lab->lista;
    if(!(n = &lab->komorki[k->y][k->x+1])->status)
    {
        dodajdolisty(l, n);
    }
    if(!(n = &lab->komorki[k->y][k->x-1])->status)
    {
        dodajdolisty(l, n);
    }
    if(!(n = &lab->komorki[k->y+1][k->x])->status)
    {
        dodajdolisty(l, n);
    }
    if(!(n = &lab->komorki[k->y-1][k->x])->status)
    {
        dodajdolisty(l, n);
    }
}