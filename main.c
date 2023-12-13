//
// Created by jakub on 11/24/23.
//
#include <stdlib.h>
#include "generacja.h"
#include <time.h>
#include <stdio.h>
#include "druk.h"
#include "solver.h"

int main(int argc, char** argv) {
    int seed =  (int)time(NULL)-1701878136;
    //356065;
    droga* d = NULL;
    printf("%d\n", seed);
    if (argc < 3)
    {
        printf("Podaj wymiary labiryntu\n");
        return 1;
    }
    srand(seed);
    int x = atoi(argv[1]);  //wymiary
    int y = atoi(argv[2]);  //labiryntu

    labirynt lab = tworzl(x + 2, y + 2);

    generuj(lab.l, 1, 1, rand());

    printf("\n");
    int* waga = calloc(1, sizeof * waga);

    solver(lab.l, &d, lab.start.x, lab.start.y, waga);
    druk(lab.l, x, y, rand());
    printf("%d\n", *waga);
    printf("[%d]", lab.start.numer);//
    writer(d);
}