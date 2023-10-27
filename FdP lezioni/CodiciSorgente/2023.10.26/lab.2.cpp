Es. 5.3 – Puntatori 2
Scrivere una funzione f(…) che ha come argomento un puntatore a intero. Sia n il valore
dell’oggetto puntato. La funzione stampa il valore del puntatore ed il valore dell’oggetto puntato,
dopodiché restituisce come ritorno di funzione:
• il quadrato di n se n è multiplo di 2;
• altrimenti il cubo di n se n è multiplo di 3;
• altrimenti il numero n.
Scrivere un programma che:
• chiede un numero da tastiera;
• stampa a video l’indirizzo a cui tale numero è memorizzato;
• chiama la funzione f(…) sul numero; e
• stampa a video il ritorno della funzione.

#include<iostream>
#include <cmath>
using namespace std;

int funzione(int *pa) {
    cout << pa << '\t' << *pa << endl;
    cout << *pa << endl;
    if (*pa % 2==0) { return (int) pow(*pa, 2);}
    else if (*pa % 3 == 3) {return (int) pow(*pa , 3);}
    else return *pa;
}

int main() {
    int a;
    cout << "numero?" << endl;
    cin >> a;
    cout << &a << '\t' << a << endl;
    cout << funzione(&a);
}
