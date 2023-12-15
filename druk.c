//
// Created by cheese on 26.11.2023.
//
#include "druk.h"
#include <stdio.h>
#include "generacja.h"

void druk(komorka_t** l, int x, int y)
{
    drukbariera(l, x, 1);
    for(int j = 1; j <= y; j++)
    {
        drukpion_sciezka(l, x, j);
        if(j<y) drukpoziom_sciezka(l, x, j);
    }
    drukbariera(l, x, y);
    printf("\n");
}

void drukbariera(komorka_t** l, int x, int y)
{
    printf("#");
    for(int i = 1; i <= x; i++)
    {
        printf(l[y][i].rodzaj == START || l[y][i].rodzaj == STOP ? "       #" : "########");
    }
    printf("\n");
}

void drukpion(komorka_t** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf("#");
        for (int i = 1; i < x; i++)
        {
            if(j==1)
                printf(" %3d   ",i+(y-1)*x);
            else
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf("#");
        }
        if(j==1)
            printf(" %3d   #\n",x+(y-1)*x);
        else
            printf("       #\n");
    }
}
void drukpion_pusty(komorka_t** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf("#");
        for (int i = 1; i < x; i++)
        {
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf("#");
        }
            printf("       #\n");
    }
}

void drukpion_sciezka(komorka_t** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf("#");
        for (int i = 1; i < x; i++)
        {
            if(l[y][i].odwiedzony ==3)
            {
                if ((j == 0 && l[y][i].gora) || (j == 2 && l[y][i].dol))
                    printf("   .   ");
                else if (j == 1)
                    printf(l[y][i].lewo && l[y][i].prawo ? "......." : l[y][i].lewo ? "....   " : l[y][i].prawo ? "   ...." : "   .   ");
                else printf("       ");

                if (l[y][i].prawo > 0)
                    printf(j == 1 ? "." : " ");
                else if (l[y][i].prawo == 0)
                    printf("#");
            }
            else
            {
                printf("       ");
                if (l[y][i].prawo > 0)
                    printf(" ");
                else if (l[y][i].prawo == 0)
                    printf("#");
            }
        }
        if(l[y][x].odwiedzony ==3)
        {
            if ((j == 0 && l[y][x].gora) || (j == 2 && l[y][x].dol))
                printf("   .   #\n");
            else if (j == 1)
                printf(l[y][x].lewo ? "....   #\n" : l[y][x].prawo ? "   ....#\n" : "   .   #\n");
            else
                printf("       #\n");
        }
        else
        {
            printf("       #\n");
        }
    }
}

void drukpoziom(komorka_t** l, int x, int y)
{
    printf("#");
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf("       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf("#");
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf("########");
    }
    printf("\n");
}

void drukpoziom_sciezka(komorka_t** l, int x, int y)
{
    printf("#");
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf(l[y][i].odwiedzony == 3 ? "   .   " : "       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf("#");
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf("########");
    }
    printf("\n");
}