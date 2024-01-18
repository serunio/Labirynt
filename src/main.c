#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "labirynt.h"
#include "prim.h"
#include "solver.h"
#include "druk.h"
#include "wilson.h"
#include "DFS.h"

void help();
int start(int argc, char** argv);

int pusty = 0, sciezka = 0, numery = 0, dfs = 0, prim = 0, wilson = 0;
int x, y;

int main() {
    labirynt l;
    for (int i = 46; i <= 300; i++) {
        int precision = 10000;
        float total = 0;
        for (int k = 1; k <= precision; k++) {
            // Zastąp poniższą linijkę odpowiednim kodem do uruchomienia Labirynt.exe z argumentami
            // oraz przechwycenia wyniku.
            l = tworzl(i+2, i+2);

            float result = generacja_wilson(&l, k)/(i*i);
            for(int j = y+1; j >= 0; j--)
                free(l.komorki[j]);
            free(l.komorki);
            total += result;

        }
        float average = total / precision;
        printf("(%d, %f), ", i, average);

    }

    return 0;
}

int main0(int argc, char** argv)
{
    if(start(argc, argv))
        return 0;

    int seed = (int)(time(NULL));
    //printf("%i\n", seed);
    srand(seed);

    float waga = 0;
    droga* d = NULL;

    labirynt lab = tworzl(x + 2, y + 2);

    if(wilson)
        generacja_wilson(&lab, seed);
    if(prim)
        generacja_prim(&lab, x/2 + 1, y/2 + 1, rand());
    if(dfs)
        generacja_dfs(lab.komorki, x/2 + 1, y/2 + 1, rand());

    solver(lab.komorki, &d, lab.start->x, lab.start->y, &waga);

    if(pusty)
        druk(&lab, x, y, 0);
    if(sciezka)
        druk(&lab, x, y, 1);
    if(numery)
    {
        druk(&lab, x, y, 2);
        writer(d, lab.start->numer);
    }
    printf("Suma wag na calym przejsciu: %.2f\n", waga);
    if(argc == 1) printf("Podaj argument \"-h\" aby uzyskac pomoc\n\n");

    for(int i = y+1; i >= 0; i--)
        free(lab.komorki[i]);
    free(lab.komorki);
    return 0;
}

void help()
{
    printf("=======================================================================\n"
           "                                 POMOC\n"
           "=======================================================================\n"
           "Program generuje i rozwiazuje losowy labirynt o podanych lub losowych\n"
           "wymiarach x i y z zakresu 2-30.\n"
           "Wymiary nalezy podac jako dwa pierwsze argumenty wywolania,\n"
           "przy nie podaniu ich sa wybierane losowo.\n"
           "Jako inne argumenty mozna podac ustawienia:\n"
           "\n"
           "Algorytmy generujace (nalezy podac dokladnie jeden):\n"
           "-wilson (algorytm Wilsona)\n"
           "-prim (zrandomizowana wersja algorytmu Prima)\n"
           "-dfs (algorytm depth-first search)\n"
           "\n"
           "Rysunek labiryntu:\n"
           "-sciezka (rysuje rozwiazanie)\n"
           "-numery (numeruje komorki i wypisuje graf przejsc z uwzglednieniem wag)\n"
           "-pusty (labirynt bez sciezki i numerow)\n"
           "\n"
           "Pomoc:\n"
           "-h (wyswietlona zostaje ta pomoc a labirynt nie jest generowany)\n\n"
           "Domyslnie wlaczone sa -wilson i -sciezka\n"
           "=======================================================================\n");
}

int start(int argc, char** argv)
{
    //wybór ustawień
    int brakwymiarow = 0;
    for(int i = 1; i < argc; i++)
    {
        if(!strcmp(argv[i], "-pusty"))
            pusty = 1;
        if(!strcmp(argv[i], "-sciezka"))
            sciezka = 1;
        if(!strcmp(argv[i], "-numery"))
            numery = 1;
        if(!strcmp(argv[i], "-dfs"))
            dfs = 1;
        if(!strcmp(argv[i], "-prim"))
            prim = 1;
        if(!strcmp(argv[i], "-wilson"))
            wilson = 1;
        if(!strcmp(argv[i], "-h"))
            {help(); return 1;}
        if(i == 2 && pusty + sciezka + numery + prim + dfs + wilson == 2) brakwymiarow = 1;
    }

    if(prim + dfs + wilson > 1)
    {
        printf("Wybierz jeden algorytm generujacy.\n");
        help();
        return 1;
    }

    if (argc < 3 || brakwymiarow )
    {
        srand(time(NULL));
        x = rand()%29 + 2; //losowe
        y = rand()%29 + 2; //wymiary
        printf("Wybrano losowe wymiary labiryntu: %ix%i\n", x, y);
    }
    else
    {
        x = atoi(argv[1]);  //wymiary
        y = atoi(argv[2]);  //labiryntu
    }

    if(x < 2 || y < 2 || x > 300 || y > 300)
    {
        printf("Podano nieprawidlowe wymiary\n");
        help();
        return 1;
    }

    //ustawienia domyślne
    if(!prim && !dfs && !wilson)
    {wilson = 1;}
    if(!pusty && !sciezka && !numery)
    {sciezka = 1;}

    return 0;
}
