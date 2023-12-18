
#include "prim.h"
#include "stdlib.h"
void generujprim(labirynt* lab, int x, int y, int seed)
{
    srand(seed);
    lab->l[y][x].odwiedzony = 1;

    lab->lista.elementy = malloc(100*sizeof(komorka_t*));
    lab->lista.rozmiar = -1;
    lab->lista.pojemnosc = 1;

    dodajsasiadow(lab, &lab->l[y][x]);
    int* i;
    komorka_t* k;//losowy element z listy
    komorka_t* n;//komorka obok losowo wybranej k
    while(lab->lista.rozmiar != 0)
    {
        int waga = seed%100 +1 ;
        k = lab->lista.elementy[rand()%(lab->lista.rozmiar)];
        //printf("wylosowano komorke numer %i\n", k->numer);
        while(lab->lista.rozmiar)
        {
            i = losuj(rand());
            if(i[1] == 1 && (n = &lab->l[k->y][k->x+1])->odwiedzony == 1)
            {
                k->prawo = n->lewo = waga;
                break;
            } else
            if(i[1] == -1 && (n = &lab->l[k->y][k->x-1])->odwiedzony == 1)
            {
                k->lewo = n->prawo = waga;
                break;
            } else
            if(i[0] == 1 && (n = &lab->l[k->y+1][k->x]) ->odwiedzony == 1)
            {
                k->dol = n->gora = waga;
                break;
            } else
            if(i[0] == -1 && (n = &lab->l[k->y-1][k->x])->odwiedzony == 1)
            {
                k->gora = n->dol = waga;
                break;
            }
        }
        //printf("kierunek: [%i][%i]\n", i[0], i[1]);
        k->odwiedzony = 1;
        dodajsasiadow(lab, k);
        usunzlisty(&lab->lista, k);
    }
}

void dodajsasiadow(labirynt* lab, komorka_t* k)
{
    //if(lab->lista.rozmiar >= lab->lista.pojemnosc - 5)
    //    lab->lista.elementy = (komorka_t**)realloc(lab->lista.elementy, (lab->lista.pojemnosc += 5) * sizeof(komorka_t*));
    //printf("dodawanie sasiadow komorki %i\n", k->numer);
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

