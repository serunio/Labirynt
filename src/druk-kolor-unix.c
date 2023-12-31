//
// Created by cheese on 26.11.2023.
//
#ifdef unix || __APPLE__
#include "druk.h"
#include <stdio.h>
#include "labirynt.h"

void druk(labirynt* lab, int x, int y, int tryb)
{
    komorka_t** l = lab->komorki;
    printf("\n");
    drukbariera(l, x, 1);
    for(int j = 1; j <= y; j++)
    {
        if(tryb == 1)
        {
            lab->start->odwiedzony = 3;
            drukpion_sciezka(l, x, j);
            if(j<y) drukpoziom_sciezka(l, x, j);
        }
        else if(tryb == 2)
        {
            drukpion_numery(l, x, j);
            if(j<y) drukpoziom(l, x, j);
        }
        else if(tryb == 0)
        {
            drukpion_pusty(l, x, j);
            if(j<y) drukpoziom(l, x, j);
        }

    }
    drukbariera(l, x, y);
    printf("\n");
}

void drukbariera(komorka_t** l, int x, int y)
{
    printf("\033[107m#\033[0m");
    for(int i = 1; i <= x; i++)
    {
        printf(l[y][i].rodzaj == START || l[y][i].rodzaj == STOP ? "       \033[107m#\033[0m" : "\033[107m########\033[0m");
    }
    printf("\n");
}

void drukpion_numery(komorka_t** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf("\033[107m#\033[0m");
        for (int i = 1; i < x; i++)
        {
            if(j==1)
                printf(" %3d   ",i+(y-1)*x);
            else
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf("\033[107m#\033[0m");
        }
        if(j==1)
            printf(" %3d   \033[107m#\033[0m\n",x+(y-1)*x);
        else
            printf("       \033[107m#\033[0m\n");
    }
}

void drukpion_pusty(komorka_t** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf("\033[107m#\033[0m");
        for (int i = 1; i < x; i++)
        {
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf("\033[107m#\033[0m");
        }
            printf("       \033[107m#\033[0m\n");
    }
}

void drukpion_sciezka(komorka_t** l, int x, int y)
{
    int gora, dol, prawo, lewo;
    for(int j = 0; j<3; j++)
    {
        printf("\033[107m#\033[0m");
        for (int i = 1; i <= x; i++)
        {
            if(l[y][i].odwiedzony == 3)
            {
                gora = dol = prawo = lewo = 0;
                if((l[y][i].gora && l[y-1][i].odwiedzony == 3) || l[y][i].rodzaj == START)
                    gora = 1;
                if((l[y][i].dol && l[y+1][i].odwiedzony == 3) || l[y][i].rodzaj == STOP)
                    dol = 1;
                if(l[y][i].prawo && l[y][i+1].odwiedzony == 3)
                    prawo = 1;
                if(l[y][i].lewo && l[y][i-1].odwiedzony == 3)
                    lewo = 1;

                if ((j == 0 && gora) || (j == 2 && dol))
                    printf("   .   ");
                else if (j == 1)
                    printf(lewo && prawo ? "......." : lewo ? "....   " : prawo ? "   ...." : "   .   ");
                else printf("       ");

                if (l[y][i].prawo > 0)
                    printf(j == 1 && prawo ? "." : " ");
                else if (l[y][i].prawo == 0)
                    printf("\033[107m#\033[0m");
            }
            else
            {
                printf("       ");
                if (l[y][i].prawo > 0)
                    printf(" ");
                else if (l[y][i].prawo == 0)
                    printf("\033[107m#\033[0m");
            }
        }
        printf("\n");
    }
}

void drukpoziom(komorka_t** l, int x, int y)
{
    printf("\033[107m#\033[0m");
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf("       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf("\033[107m#\033[0m");
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf("\033[107m########\033[0m");
    }
    printf("\n");
}

void drukpoziom_sciezka(komorka_t** l, int x, int y)
{
    printf("\033[107m#\033[0m");
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf((l[y][i].odwiedzony == 3 && l[y+1][i].odwiedzony == 3) ? "   .   " : "       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf("\033[107m#\033[0m");
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf("\033[107m########\033[0m");
    }
    printf("\n");
}
#endif //ifdef unix
