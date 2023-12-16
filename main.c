//
// Created by jakub on 11/24/23.
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "generacja.h"
#include "solver.h"
#include "druk.h"

void help()
{
    printf("help");
}
int main(int argc, char** argv)
{
   if(!strcmp(argv[1], "-h"))
   {
       help();
       return 0;
   }
    if (argc < 3)
    {
        printf("Podaj wymiary labiryntu\n");
        help();
        return 1;
    }
    int x = atoi(argv[1]);  //wymiary
    int y = atoi(argv[2]);  //labiryntu
    if(x<=1 || y<=1)
    {
        printf("Podano nieprawidlowe wymiary\n");
        help();
        return 1;
    }
    int pusty = 0, sciezka = 0, numery = 0;
    for(int i = 3; i < argc; i++)
    {
        if(!strcmp(argv[i], "-pusty"))
            pusty = 1;
        if(!strcmp(argv[i], "-sciezka"))
            sciezka = 1;
        if(!strcmp(argv[i], "-numery"))
            numery = 1;
    }
    if(!pusty && !sciezka && !numery)
        sciezka = 1;

    int seed =  (int)time(NULL);
    int* waga = calloc(1, sizeof * waga);
    droga* d = NULL;

    //printf("%d\n", seed);

    srand(seed);

    labirynt lab = tworzl(x + 2, y + 2);

    generuj(lab.l, 1, 1, rand());

    solver(lab.l, &d, lab.start->x, lab.start->y, waga);

    if(pusty)
        druk(&lab, x, y, 0);
    if(sciezka)
        druk(&lab, x, y, 1);
    if(numery)
    {
        druk(&lab, x, y, 2);
        writer(d, lab.start->numer);
    }



    printf("Suma wag wszystkich przejsc: %d\n\n", *waga);


}