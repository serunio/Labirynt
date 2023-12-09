//
// Created by jakub on 11/24/23.
//
#include <stdlib.h>
#include "generacja.h"
#include <time.h>
#include <stdio.h>
#include "druk.h"

int main(int argc, char** argv) {
    int seed =  time(NULL)-1701878136;
    //356065;
    printf("%d\n", seed);
    if (argc < 3)
    {
        printf("Podaj wymiary labiryntu\n");
        return 1;
    }
    srand(seed);
    int x = atoi(argv[1]);  //wymiary
    int y = atoi(argv[2]);  //labiryntu

    labirynt l = tworzl(x + 2, y + 2);

    generuj(l, 1, 1, rand());

    //spoziome = poziom();
    //spionowe = pion();

    druk(l, x, y, rand());
    printf("\n");
    //druk0(spionowe, spoziome, x, y, rand());

}