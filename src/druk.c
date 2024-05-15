#include <stdio.h>
#include <stdlib.h>

#include "druk.h"
#include "labirynt.h"

//#define Z "[97m[47m [40m"
#define Z "#"

void druk(labirynt lab, int x, int y, int tryb)
{
    komorka** l = lab.komorki;
    printf("\n");
    system("");
    drukbariera(l, x, 1);
    for(int j = 1; j <= y; j++)
    {
        if(tryb == 1)
        {
            lab.start->status = 3;
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

void drukbariera(komorka** l, int x, int y)
{

    printf(Z);
    for(int i = 1; i <= x; i++)
    {
        printf(l[y][i].rodzaj == START || l[y][i].rodzaj == STOP ? "       " Z : Z Z Z Z Z Z Z Z);
    }
    printf("\033[0m\n");
}

void drukpion_numery(komorka** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf(Z);
        for (int i = 1; i < x; i++)
        {
            if(j==1)
                printf(" %3d   ",i+(y-1)*x);
            else
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf(Z);
        }
        if(j==1)
            printf(" %3d   " Z,x+(y-1)*x);
        else
            printf("       " Z);
        printf("\033[0m");
        printf("\n");
    }
}

void drukpion_pusty(komorka** l, int x, int y)
{
    for(int j = 0; j<3; j++) {
        printf(Z);
        for (int i = 1; i < x; i++)
        {
                printf("       ");
            if (l[y][i].prawo >  0)
                printf(" ");
            else if (l[y][i].prawo == 0)
                printf(Z);
        }
            printf("       " Z);
        printf("\033[0m");
        printf("\n");
    }
}

void drukpion_sciezka(komorka** l, int x, int y)
{
    int gora, dol, prawo, lewo;
    for(int j = 0; j<3; j++)
    {
        printf(Z);
        for (int i = 1; i <= x; i++)
        {
            if(l[y][i].status == 3)
            {
                gora = dol = prawo = lewo = 0;
                if((l[y][i].gora && l[y-1][i].status == 3) || l[y][i].rodzaj == START)
                    gora = 1;
                if((l[y][i].dol && l[y+1][i].status == 3) || l[y][i].rodzaj == STOP)
                    dol = 1;
                if(l[y][i].prawo && l[y][i+1].status == 3)
                    prawo = 1;
                if(l[y][i].lewo && l[y][i-1].status == 3)
                    lewo = 1;

                if ((j == 0 && gora) || (j == 2 && dol))
                    printf("   .   ");
                else if (j == 1)
                    printf(lewo && prawo ? "......." : lewo ? "....   " : prawo ? "   ...." : "   .   ");
                else printf("       ");

                if (l[y][i].prawo > 0)
                    printf(j == 1 && prawo ? "." : " ");
                else if (l[y][i].prawo == 0)
                    printf(Z);
            }
            else
            {
                printf("       ");
                if (l[y][i].prawo > 0)
                    printf(" ");
                else if (l[y][i].prawo == 0)
                    printf(Z);
            }
        }
        printf("\033[0m");
        printf("\n");
    }
}

void drukpoziom(komorka** l, int x, int y)
{
    printf(Z);
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf("       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf(Z);
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf(Z Z Z Z Z Z Z Z);
    }
    printf("\033[0m");
    printf("\n");
}

void drukpoziom_sciezka(komorka** l, int x, int y)
{
    printf(Z);
    for(int i = 1; i <= x; i++)
    {
        if(l[y][i].dol > 0) {
            printf((l[y][i].status == 3 && l[y + 1][i].status == 3) ? "   .   " : "       ");
            if (l[y][i+1].dol == 0 || i == x + 1 || l[y][i].prawo == 0)
                printf(Z);
            else
                printf(" ");
        }
        else if(l[y][i].dol == 0)
            printf(Z Z Z Z Z Z Z Z);
    }
    printf("\033[0m");
    printf("\n");
}

