#ifndef LABIRYNT_DFS_H
#define LABIRYNT_DFS_H

#include "labirynt.h"

int generacja_dfs(komorka** l, int x, int y, int seed); //funkcja rekurencyjna. tworzy przejscie do losowej komorki i wywoluje sie w niej. zwraca 1 w razie sukcesu i 0 w razie porazki

#endif //LABIRYNT_DFS_H
