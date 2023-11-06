//scrivere un programma che ruota in maniera circolare un vettore di n passi
#include <iostream>

using namespace std;

void ruotaVettore(int *v , int k) {
    int vc[6];
    for (int i = 0; i < 6 ; i++) {
        vc[i] = *(v+i);
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 6; j++) {
            if (j==0) {
                *(v+j)=vc[5];
            }
            else {
                *(v+j) = vc[j-1];
            }
        }
        for (int l = 0; l < 6 ; l++) {
            vc[l] = *(v+l);
        }
    }
}

int main() {
    const int N = 6;
    int k;
    int v[6] = {0,0,0,0,0,0};
    for (int i = 0; i < 6 ; i++) {
        cout << "inserire un numero" << endl;
        cin >> v[i];
    }
    cout << " quanti passi?" << endl;
    cin >> k;
    ruotaVettore(&v[0] , k);
    for (int i = 0; i < 6 ; i++) {
        cout << v[i] << '\t' ;
    }
}
