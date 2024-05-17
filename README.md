Celem projektu było stworzenie programu generującego labirynt i rozwiązującego go. Więcej szczegółów w [Sprawozdanie.pdf](https://github.com/serunio/Labirynt/blob/master/Sprawozdanie.pdf)

           =======================================================================
                                            POMOC
           =======================================================================
           Program generuje i rozwiazuje losowy labirynt o podanych lub losowych
           wymiarach x i y z zakresu 2-30.
           Wymiary nalezy podac jako dwa pierwsze argumenty wywolania,
           przy nie podaniu ich sa wybierane losowo.
           Jako inne argumenty mozna podac ustawienia:
           
           Algorytmy generujace (nalezy podac dokladnie jeden):
           -wilson (algorytm Wilsona)
           -prim (zrandomizowana wersja algorytmu Prima)
           -dfs (algorytm depth-first search)
           
           Rysunek labiryntu:
           -sciezka (rysuje rozwiazanie)
           -numery (numeruje komorki i wypisuje graf przejsc z uwzglednieniem wag)
           -pusty (labirynt bez sciezki i numerow)
           
           Pomoc:
           -h (wyswietlona zostaje ta pomoc a labirynt nie jest generowany)
           
           Domyslnie wlaczone sa -wilson i -sciezka
           =======================================================================
