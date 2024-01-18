#include <stdlib.h>

#include "DFS.h"
#include "labirynt.h"

int generacja_dfs(komorka** l, int x, int y, int seed)
{
    if(l[y][x].status != 0) //O(1)
        return 0;
    l[y][x].status = 1; //O(1)

    srand(seed); //O(1)

    int* i; //O(1)
    while(!l[y + 1][x].status || !l[y - 1][x].status || !l[y][x + 1].status || !l[y][x - 1].status)
    {
        seed = rand(); //O(1)
        float waga = (float)(seed%1000 +1)/100; //O(1)
        i = losuj(seed); //O(1)
        if(generacja_dfs(l, x + i[1], y + i[0], seed)) //O(x*y)
        {
            if(i[1] == 1) {
                l[y][x].prawo = l[y][x + 1].lewo = waga; //O(1)
            } else
            if(i[1] == -1) {
                l[y][x].lewo = l[y][x - 1].prawo = waga; //O(1)
            } else
            if(i[0] == 1) {
                l[y][x].dol = l[y + 1][x].gora = waga; //O(1)
            } else
            if(i[0] == -1) {
                l[y][x].gora = l[y - 1][x].dol = waga; //O(1)
            }
        }
        free(i); //O(1)
    }
    return 1; //O(1)
}