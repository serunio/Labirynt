#include <stdlib.h>

#include "DFS.h"
#include "labirynt.h"

int generacja_dfs(komorka** l, int x, int y, int seed)
{
    //sprawdza czy komorka jest nieodwiedzona
    if(l[y][x].status != 0)
        return 0;
    l[y][x].status = 1;

    srand(seed);

    int* i; //losowy kierunek następnego przejścia
    while(!l[y + 1][x].status || !l[y - 1][x].status || !l[y][x + 1].status || !l[y][x - 1].status)
    {
        seed = rand();
        float waga = (float)(seed%1000 +1)/100; //losowa waga w zakresie 0-10
        i = losuj(seed);
        if(generacja_dfs(l, x + i[1], y + i[0], seed))
        {
            if(i[1] == 1) {
                l[y][x].prawo = l[y][x + 1].lewo = waga;
            } else
            if(i[1] == -1) {
                l[y][x].lewo = l[y][x - 1].prawo = waga;
            } else
            if(i[0] == 1) {
                l[y][x].dol = l[y + 1][x].gora = waga;
            } else
            if(i[0] == -1) {
                l[y][x].gora = l[y - 1][x].dol = waga;
            }
        }
        free(i);
    }
    return 1;
}