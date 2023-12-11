//
// Created by jakub on 11/24/23.
//

#ifndef LABIRYNT_GENERACJA_H
#define LABIRYNT_GENERACJA_H
#define START 1
#define STOP 2
typedef struct
{
    int odwiedzony; //0 - nieodwiedzony, 1 - odwiedzony przez generuj(), -1 - bariera, 2 - odwiedzony przez solver()
    int rodzaj; //1 - start, 2 - stop

    //przejścia
    int gora, dol, prawo, lewo; //wagi przejsc (0 to brak przejscia czyli sciana)
}komorka_t;

typedef struct
{
    komorka_t** l;
    komorka_t start;
    komorka_t stop;
}labirynt;

labirynt tworzl(int x, int y); //tworzy pusty labirynt
int generuj(komorka_t** k, int x, int y, int seed); //funkcja rekurencyjna. tworzy przejscie do losowej komorki i wywoluje sie w niej. zwraca 1 w razie sukcesu i 0 w razie porazki
int* losuj(int seed); //losowy kierunek przy generacji przejsc
#endif //LABIRYNT_GENERACJA_H
