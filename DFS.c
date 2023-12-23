#include <stdlib.h>

#include "labirynt.h"

int generacja_dfs(komorka_t** k, int x, int y, int seed)
{
    srand(seed);

    //sprawdza czy komorka jest nieodwiedzona
    if(k[y][x].odwiedzony != 0)
        return 0;
    k[y][x].odwiedzony = 1;

    int* i; //losowy kierunek następnego przejścia
    while(!k[y+1][x].odwiedzony || !k[y-1][x].odwiedzony || !k[y][x+1].odwiedzony || !k[y][x-1].odwiedzony)
    {
        seed = rand();
        int waga = seed%100 +1; //losowa waga w zakresie 1-100
        i = losuj(seed);
        if(generacja_dfs(k, x+i[1], y+i[0], seed))
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