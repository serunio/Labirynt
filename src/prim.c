#include "prim.h"
#include <stdlib.h>
#include <stdio.h>

void generacja_prim(labirynt* lab, int x, int y, int seed)
{
    srand(seed); // O(1)
    komorka** komorki = lab->komorki; // O(1)
    komorki[y][x].status = 1; // O(1)

    lista* lista = &lab->lista; // O(1)
    lista->elementy = malloc(1000 * sizeof(komorka*)); // O(1)
    lista->rozmiar = -1; // O(1)

    dodajsasiadow(lab, &komorki[y][x]); // O(1)

    int* i; // O(1)
    komorka* k; // O(1)
    komorka* n; // O(1)
    int r; // O(1)
    // Pętla while wykonuje się (x * y - 1) razy, gdzie x to liczba kolumn, a y to liczba wierszy
    while ((r = lista->rozmiar) >= 0) // O(x * y)
    {
        float waga = (float)(rand() % 1000 + 1) / 100; // O(1)

        k = lista->elementy[rand() % (r + 1)]; // O(1)

        int a = 1000;

        // Pętla while może potencjalnie powtórzyć się wiele razy w zależności od losowania
        // Nie ma to wpływu na złożoność obliczeniową
        while (1)
        {
            a--; // O(1)
            if (a == 0)
            {
                srand(rand()); // O(1)
                a = 1000; // O(1)
            }

            i = losuj(rand()); // O(1)
            n = &komorki[k->y + i[0]][k->x + i[1]]; // O(1)

            if (n->status == 1)
            {
                if (i[1] == 1)
                {
                    k->prawo = n->lewo = waga; // O(1)
                    break;
                }
                else if (i[1] == -1)
                {
                    k->lewo = n->prawo = waga; // O(1)
                    break;
                }
                else if (i[0] == 1)
                {
                    k->dol = n->gora = waga; // O(1)
                    break;
                }
                else if (i[0] == -1)
                {
                    k->gora = n->dol = waga; // O(1)
                    break;
                }
            }
            free(i); // O(1)
        }

        k->status = 1; // O(1)
        dodajsasiadow(lab, k); // O(1)
        usunzlisty(lista, k); // O(1)
    }

    free(lista->elementy); // O(1)
}

void dodajsasiadow(labirynt* lab, komorka* k)
{
    komorka* n; // O(1)
    lista* l = &lab->lista; // O(1)

    // Dla każdej sąsiedniej komórki wykonuje się O(1) operacji (stała złożoność)
    if (!(n = &lab->komorki[k->y][k->x + 1])->status)
    {
        dodajdolisty(l, n); // O(1)
    }
    if (!(n = &lab->komorki[k->y][k->x - 1])->status)
    {
        dodajdolisty(l, n); // O(1)
    }
    if (!(n = &lab->komorki[k->y + 1][k->x])->status)
    {
        dodajdolisty(l, n); // O(1)
    }
    if (!(n = &lab->komorki[k->y - 1][k->x])->status)
    {
        dodajdolisty(l, n); // O(1)
    }
}
