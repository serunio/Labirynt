//
// Created by jakub on 11/24/23.
//
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "generacja.h"
#include "prim.h"
#include "solver.h"
#include "druk.h"
#include "wilson.h"

void help()
{
    printf("help");
}
int main(int argc, char** argv)
{
   if(argc > 1 && !strcmp(argv[1], "-h"))
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
    int pusty = 0, sciezka = 0, numery = 0, dp = 0, prim = 0, wilson = 0;
    for(int i = 3; i < argc; i++)
    {
        if(!strcmp(argv[i], "-pusty"))
            pusty = 1;
        if(!strcmp(argv[i], "-sciezka"))
            sciezka = 1;
        if(!strcmp(argv[i], "-numery"))
            numery = 1;
        if(!strcmp(argv[i], "-dp"))
            dp = 1;
        if(!strcmp(argv[i], "-prim"))
            prim = 1;
        if(!strcmp(argv[i], "-wilson"))
            wilson = 1;
    }
    if(prim + dp + wilson > 1)
    {
        printf("Wybierz jeden algorytm generujacy.\n");
        return 1;
    }
    if(!prim && !dp && !wilson)
        wilson = 1;
    if(!pusty && !sciezka && !numery)
        sciezka = 1;

    int seed =  (int)time(NULL);
    printf("%i\n", seed);
    int* waga = calloc(1, sizeof * waga);
    droga* d = NULL;

    //printf("%d\n", seed);

    srand(seed);

    labirynt lab = tworzl(x + 2, y + 2);

    lab.liczba_nieodwiedzonych = x*y;

    if(wilson)
        generacjawilson(&lab, seed);
    if(prim)
        generujprim(&lab, x/2, y/2, rand());
    if(dp)
        generuj(lab.l, x/2, y/2, rand());

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