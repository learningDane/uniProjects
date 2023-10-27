Es. 5.4 – Puntatori 3
Scrivere una funzione void inizializzaP(…) che ha come argomento un puntatore a
intero. La funzione assegna NULL al puntatore. Scrivere un programma che crea una variabile
intera k ed una variabile puntatore p che inizialmente punta a k. Successivamente invocare la
funzione che deve modificare il valore della variabile puntatore p assegnandogli NULL.
Stampare il valore del puntatore prima e dopo la chiamata della funzione.

#include <iostream>
using namespace std;

void inizializza(int *pp) {
    pp = NULL;
    cout << pp;
}

int main () {
    int k = 6;
    int *p = &k;
    cout << p << endl;
    inizializza(p);
}
