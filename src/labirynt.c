#include "labirynt.h"
#include <stdlib.h>

labirynt tworzl(int x, int y)
{
    labirynt labirynt1;
    //zaalokowanie pamieci dla labiryntu
    komorka_t** l = (komorka_t**)malloc(y*sizeof(komorka_t*));
    for(int i = 0; i < y; i++)
        l[i] = (komorka_t*)malloc(x*sizeof(komorka_t));

    //ustawienie zmiennych we wszystkich komórkach na domyślne wartości
    for(int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++) {
            l[i][j].odwiedzony = l[i][j].lewo = l[i][j].prawo = l[i][j].gora = l[i][j].dol = l[i][j].rodzaj = 0;
            l[i][j].numernaliscie = -1;
            l[i][j].numer =  j + (i-1) * (x-2);
            l[i][j].x = j;
            l[i][j].y = i;

        }
    }
    //ustawienie barier na brzegach aby funkcje generujące tam nie wchodziły
    for(int i = 0; i < y; i++)
    {
        l[i][0].odwiedzony = l[i][0].numer = -1;
        l[i][x-1].odwiedzony = l[i][x-1].numer = -1;
    }
    for(int i = 0; i < x; i++)
    {
        l[0][i].odwiedzony = l[0][i].numer = -1;
        l[y-1][i].odwiedzony = l[y-1][i].numer = -1;
    }

    //wybor komorek startowej i koncowej
    int start = rand()%(x-2) + 1, stop = rand()%(x-2) + 1;
    l[1][start].rodzaj = START;
    l[y-2][stop].rodzaj = STOP;

    labirynt1.x = x-2; labirynt1.y = y-2;
    labirynt1.komorki = l;
    labirynt1.start = &l[1][start];
    labirynt1.stop = &l[y-2][stop];

    return labirynt1;
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

void dodajdolisty(lista* l, komorka_t* n)
{
    n->odwiedzony = 4;
    l->elementy[++l->rozmiar] = n;
    n->numernaliscie = l->rozmiar;
}

void usunzlisty(lista* l, komorka_t* k)
{
    if(k->numernaliscie <= l->rozmiar)
    {
        int i = k->numernaliscie;
        k->numernaliscie = l->rozmiar+1;
        while (i < l->rozmiar) {
            l->elementy[i] = l->elementy[i + 1];
            l->elementy[i++]->numernaliscie--;
        }
        l->elementy[i] = NULL;
        l->rozmiar--;
    }
}
