//scrivere una funzione "double funzione()" che dato un vettore di double in ingresso restituisce il valore massimo rpesente nel vettore.
//scirvere un programma che dato il vettore di double {1.3 , 4.5 , 2.4 , 8.4 , -3.14 , -3.14} ne calcola il massimo con la funzione precedente e lo stampa a video.

#include <iostream>

using namespace std;

double massimo(const double vec[]) {
    double max = vec[0];
    for (int i = 0; i < 6; i++) {
        if (vec[i] > max) { max = vec[i]; }
    }
    return max;
}

int main() {
    const double vec[] = {1.3, 4.5, 2.4, 8.4, -3.14, -3.14};
    cout << massimo(vec) << endl;
}