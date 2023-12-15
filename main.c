//
// Created by jakub on 11/24/23.
//
#include <stdlib.h>
#include "generacja.h"
#include <time.h>
#include <stdio.h>
#include "druk.h"
#include "solver.h"

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        printf("Podaj wymiary labiryntu\n");
        return 1;
    }
    int x = atoi(argv[1]);  //wymiary
    int y = atoi(argv[2]);  //labiryntu
    int seed =  (int)time(NULL);
    int* waga = calloc(1, sizeof * waga);
    droga* d = NULL;

    //printf("%d\n", seed);

    srand(seed);

    labirynt lab = tworzl(x + 2, y + 2);

    generuj(lab.l, 1, 1, rand());

    solver(lab.l, &d, lab.start.x, lab.start.y, waga);

    druk(lab.l, x, y);

    printf("%d\n", *waga);
    printf("[%d]", lab.start.numer);//
    writer(d);
}