//scrivi una funzione che crea una array di 10 interi inseriti da tastiera e scopre se è pari o dispari.
#include <iostream>

using namespace std;

void pari(int vec[10]) {
    int sum = 0;
    for (int i = 0; i < 10 ; i++) {
        sum += vec[i];
    }
    if (sum % 2 == 0) {cout << "pari" ;} else {cout << "dispari" ;}
}

int main() {
    int vec[10];
    for (int i = 0; i < 10 ; i++) {
        cout << "inserisci un numero" << endl;
        cin >> vec[i];
    }
    pari(vec);
}