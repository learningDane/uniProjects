//scrivere una funzione "double posMinimo()" che dato un vettore di double in ingresso restituisce la posizione del primo minimo
//scirvere un programma che dato il vettore di double {1.3 , 4.5 , 2.4 , 8.4 , -3.14 , -3.14} ne calcola la posizione del minimo con la funzione precedente e lo stampa a video.

#include <iostream>

using namespace std;

double massimo(const double vec[]) {
    int min = 0;
    for (int i = 0; i < 6; i++) {
        if (vec[i] < vec[min]) { min = i; }
    }
    return min;
}

int main() {
    const double vec[] = {1.3 , 4.5 , 2.4 , 8.4 , -3.14 , -3.14};
    cout << massimo(vec) << endl;
}