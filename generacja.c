//
// Created by jakub on 11/24/23.
//
#include "generacja.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

labirynt tworzl(int x, int y)
{
    labirynt labirynt1;
    //zaalokowanie pamieci dla labiryntu
    komorka_t** l = (komorka_t**)malloc(y*sizeof(komorka_t*));
    for(int i = 0; i < y; i++)
        l[i] = (komorka_t*)malloc(x*sizeof(komorka_t));

    //ustawienie zmiennych we wszystkich komorkach na domyslna wartosc
    for(int i = 1; i < y-1; i++)
    {
        for (int j = 1; j < x - 1; j++) {
            l[i][j].odwiedzony = l[i][j].lewo = l[i][j].prawo = l[i][j].gora = l[i][j].dol = l[i][j].rodzaj = 0;
            l[i][j].numer = j + (i - 1) * (x-2);
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
    labirynt1.start = l[1][start];
    labirynt1.stop = l[y-2][stop];

    return labirynt1;
}


int generuj(komorka_t** k, int x, int y, int seed)
{
    srand(seed);

    //sprawdza czy komorka jest nieodwiedzona
    if(k[y][x].odwiedzony != 0)
    {
        //printf("komorka: [%d][%d]   odwiedzony = %d\n", x, y, k[y][x].odwiedzony);
        return 0;
    }
    k[y][x].odwiedzony = 1;

    int* i; //kierunek nastepnego przejscia
    while(k[y+1][x].odwiedzony == 0 || k[y-1][x].odwiedzony == 0 || k[y][x+1].odwiedzony == 0 || k[y][x-1].odwiedzony == 0)
    {
        seed = rand();
        //printf("%d %d\n", x, y);
        int waga = rand()%10 +1 ;
        //printf("%d\n\n", waga);
        //printf("komorka: [%d][%d]", x, y);
        i = losuj(rand());
        //printf("   kierunek: [%d][%d]\n",i[0],i[1]);
        if(generuj(k, x+i[0], y+i[1], seed))
        {
            if(i[0] == 1) {
                k[y][x].prawo = k[y][x+1].lewo = waga;
            } else
            if(i[0] == -1) {
                k[y][x].lewo = k[y][x-1].prawo = waga;
            } else
            if(i[1] == 1) {
                k[y][x].dol = k[y+1][x].gora = waga;
            } else
            if(i[1] == -1) {
                k[y][x].gora = k[y-1][x].dol = waga;
            }
        }
    }
    return 1;


}


int* losuj0(int seed)
{
    printf("  %d  ", seed);
    srand(seed);
    int indeks = rand()%2;
    int* i = malloc(2*sizeof(int));
    i[0] = 0; i[1] = 0;
    i[indeks] = rand()%2 == 1 ? 1 : -1;
    return i;
}

int* losuj(int seed)
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