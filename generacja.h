//
// Created by jakub on 11/24/23.
//

#ifndef LABIRYNT_GENERACJA_H
#define LABIRYNT_GENERACJA_H
#define START 1
#define STOP 2
typedef struct komorka
{
    int odwiedzony;
    int rodzaj; //1 - start, 2 - stop

    //przejścia
    int gora, dol, prawo, lewo; //wagi przejsc (0 to brak przejscia czyli sciana)
}komorka_t, **labirynt;

static int** spoziome; //tablica ścian poziomych
static int** spionowe; //tablica ścian pionowych

komorka_t** tworzl(int x, int y); //tworzy pusty labirynt
int** tworzs(int x, int y); //tworzy tablice ścian
int generuj(komorka_t** k, int x, int y, int seed);
int** pion();
int** poziom();
int* losuj(int seed); //losowy kierunek
#endif //LABIRYNT_GENERACJA_H
