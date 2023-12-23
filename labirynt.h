#ifndef LABIRYNT_GENERACJA_H
#define LABIRYNT_GENERACJA_H
#define START 1
#define STOP 2
typedef struct
{
    int odwiedzony; //0 - nieodwiedzony, 1 - odwiedzony przez generuj(), -1 - bariera, 2 - odwiedzony przez solver(), 3 - nalezy do sciezki, 4 - jest na liscie(prim)
    int rodzaj; //1 - start, 2 - stop
    int numer;
    //przejścia
    int gora, dol, prawo, lewo; //wagi przejsc (0 to brak przejscia czyli sciana)
    int x, y; //wspolrzedne komorki
    int numernaliscie;
}komorka_t;

typedef struct
{
    komorka_t** elementy;
    int rozmiar;
}lista;

typedef struct
{
    komorka_t** komorki;
    komorka_t* start;
    komorka_t* stop;
    lista lista;
    int x, y; //wymiary
}labirynt;

typedef struct droga
{
    komorka_t* step;
    struct droga* next;
    int waga;

}droga;

labirynt tworzl(int x, int y); //tworzy pusty labirynt

int* losuj(int seed); //losowy kierunek przy generacji przejsc

void usunzlisty(lista*, komorka_t*);
void dodajdolisty(lista*, komorka_t*);
#endif //LABIRYNT_GENERACJA_H
