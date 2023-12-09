//
// Created by cheese on 26.11.2023.
//
#include "druk.h"
#include <stdio.h>
#include "generacja.h"

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