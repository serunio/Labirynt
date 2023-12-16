//
// Created by jakub on 11/24/23.
//
#include "generacja.h"
#include <stdlib.h>

labirynt tworzl(int x, int y)
{
    labirynt labirynt1;
    //zaalokowanie pamieci dla labiryntu
    komorka_t** l = (komorka_t**)malloc(y*sizeof(komorka_t*));//
    for(int i = 0; i < y; i++)
        l[i] = (komorka_t*)malloc(x*sizeof(komorka_t));

    //ustawienie zmiennych we wszystkich komorkach na domyslna wartosc
    for(int i = 1; i < y-1; i++)
    {
        for (int j = 1; j < x - 1; j++) {
            l[i][j].odwiedzony = l[i][j].lewo = l[i][j].prawo = l[i][j].gora = l[i][j].dol = l[i][j].rodzaj = 0;
            l[i][j].numer =  j + (i - 1) * (x-2);
            l[i][j].x = j;
            l[i][j].y = i;
        }

    }
    //ustawienie barier na brzegach aby funkcja generuj tam nie wchodzila
    for(int i = 0; i < y; i++)
    {
        l[i][0].odwiedzony = -1;
        l[i][x-1].odwiedzony = -1;
    }
    for(int i = 0; i < x; i++)
    {
        l[0][i].odwiedzony = -1;
        l[y-1][i].odwiedzony = -1;
    }

    //wybor komorek startowej i koncowej
    int start = rand()%(x-2) + 1, stop = rand()%(x-2) + 1;
    l[1][start].rodzaj = START;
    l[y-2][stop].rodzaj = STOP;

    labirynt1.l = l;
    labirynt1.start = &l[1][start];
    labirynt1.stop = &l[y-2][stop];

    return labirynt1;
}

int generuj(komorka_t** k, int x, int y, int seed)
{
    srand(seed);

    //sprawdza czy komorka jest nieodwiedzona
    if(k[y][x].odwiedzony != 0)
        return 0;
    k[y][x].odwiedzony = 1;

    int* i; //kierunek nastepnego przejscia
    while(k[y+1][x].odwiedzony == 0 || k[y-1][x].odwiedzony == 0 || k[y][x+1].odwiedzony == 0 || k[y][x-1].odwiedzony == 0)
    {
        seed = rand();
        int waga = seed%100 +1 ;
        i = losuj(seed);
        if(generuj(k, x+i[1], y+i[0], seed))
        {
            if(i[1] == 1) {
                k[y][x].prawo = k[y][x+1].lewo = waga;
            } else
            if(i[1] == -1) {
                k[y][x].lewo = k[y][x-1].prawo = waga;
            } else
            if(i[0] == 1) {
                k[y][x].dol = k[y+1][x].gora = waga;
            } else
            if(i[0] == -1) {
                k[y][x].gora = k[y-1][x].dol = waga;
            }
        }
        free(i);
    }
    return 1;


}

int* losuj(int seed)
{
    srand(seed);
    int indeks = rand()%2;
    int* i = malloc(2*sizeof(int));
    i[0] = 0; i[1] = 0;
    i[indeks] = rand()%2 == 1 ? 1 : -1;
    return i;
}

int* losuj0(int seed)
{
    srand(seed);
    int r = rand();
    int n = r%4;
    int* i = malloc(2*sizeof(int));
    i[0] = 0; i[1] = 0;
    if(n == 0) i[0]=1;
    if(n == 1) i[0]=-1;
    if(n == 2) i[1]=1;
    if(n == 3) i[1]=-1;

    return i;
}


void generujprim(labirynt* lab, int x, int y, int seed)
{
    srand(seed);
    lab->l[y][x].odwiedzony = 1;
    dodajdolisty(lab, &lab->l[y][x]);
    int* i;
    komorka_t* k;
    komorka_t* n;
    while(lab->lista.elementy[0] != NULL)
    {
        int waga = seed%100 +1 ;
        while(1)
        {
            i = losuj(rand());
            k = lab->lista.elementy[rand()%(lab->lista.rozmiar+1)];
            if(i[1] == 1 && (n = &lab->l[k->y][k->x+1])->odwiedzony == 0)
            {
                k->prawo = n->lewo = waga;
                break;
            } else
            if(i[1] == -1 && (n = &lab->l[k->y][k->x-1])->odwiedzony == 0)
            {
                k->lewo = n->prawo = waga;
                break;
            } else
            if(i[0] == 1 && (n = &lab->l[k->y+1][k->x])->odwiedzony == 0)
            {
                k->dol = n->gora = waga;
                break;
            } else
            if(i[0] == -1 && (n = &lab->l[k->y-1][k->x])->odwiedzony == 0)
            {
                k->gora = n->dol = waga;
                break;
            }
        }
        n->odwiedzony = 1;
        dodajdolisty(lab, n);
        usunzlisty(lab->lista, k);
    }
}

void dodajdolisty(labirynt* lab, komorka_t* k)
{
    komorka_t* n;
    if(!(n = &lab->l[k->y][k->x+1])->odwiedzony)
    {
        lab->lista.elementy[lab->lista.rozmiar++] = n;
    }
    if(!(n = &lab->l[k->y][k->x-1])->odwiedzony)
    {
        lab->lista.elementy[lab->lista.rozmiar++] = n;
    }
    if(!(n = &lab->l[k->y+1][k->x])->odwiedzony)
    {
        lab->lista.elementy[lab->lista.rozmiar++] = n;
    }
    if(!(n = &lab->l[k->y-1][k->x])->odwiedzony)
    {
        lab->lista.elementy[lab->lista.rozmiar++] = n;
    }
}

void usunzlisty(lista l, komorka_t* k)
{

}