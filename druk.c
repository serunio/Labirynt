//
// Created by cheese on 26.11.2023.
//
#include "druk.h"
#include <stdlib.h>
#include <stdio.h>
#include "generacja.h"

void drukpion0(int* r, int x)
{
    for(int j = 0; j<2; j++) {
        printf("#");
        for (int i = 0; i < x; i++) {
            printf("    ");
            if (r[i] == 0)
                printf(" ");
            else if (r[i] == 1)
                printf("#");
        }
        printf("    #\n");
    }
}

void drukpoziom0(int* r, int* d, int x)
{
    printf("#");
    for(int i = 0; i < x; i++)
    {
        if(r[i] == 0) {
            printf("    ");
            if (r[i + 1] == 1 || i == x - 1 || d[i] == 1)
                printf("#");
            else
                printf(" ");
        }
        else if(r[i] == 1)
            printf("#####");

    }
    printf("\n");
}

void drukbariera0(int x, int seed)
{
    srand(seed);
    int a = 1+rand()%x;
    printf("#");
    for(int i = 1; i<a; i++)
    {
        printf("#####");
    }
    printf("    #");
    for(int i = 1; i<=x-a; i++)
        printf("#####");
    printf("\n");

}

void druk0(int** pionowe, int** poziome, int x, int y, int seed)
{
    srand(seed);
    drukbariera0(x, rand());
    for(int j = 0; j < y; j++)
    {
        drukpion0(pionowe[j], x-1);
        if(j<y-1) drukpoziom0(poziome[j], pionowe[j], x);
    }
    drukbariera0(x, rand());
}

void druk(labirynt l, int x, int y, int seed)
{
    drukbariera(l, x, 1);
    for(int j = 1; j <= y; j++)
    {
        drukpion(l, x, j);
        if(j<y) drukpoziom(l, x, j);
    }
    drukbariera(l, x, y);
}

void drukbariera(labirynt l, int x, int y)
{
    printf("#");
    for(int i = 1; i <= x; i++)
    {
        printf(l[y][i].rodzaj == START || l[y][i].rodzaj == STOP ? "    #" : "#####");
    }
    printf("\n");
}

void drukpion(labirynt l, int x, int y)
{
    for(int j = 0; j<2; j++) {
        printf("#");
        for (int i = 1; i < x; i++) {
            printf("    ",i+(y-1)*x);
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf("#");
        }
        printf("    #\n");
    }
}

void drukpoziom(labirynt l, int x, int y)
{
    printf("#");
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf("    ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf("#");
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf("#####");

    }
    printf("\n");
}