//stampa una matrice e ne stampa la matrice trasposta
#include <iostream>
using namespace std;

int* trasposta(const int*matr, int n) {
    int* trsp = new int[n*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            trsp[i*n + j]= matr[j*n + i];
        }
    }
    return trsp;
}

void stampa(int mat[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i*n + j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main () {
    int n;
    cout << "inserire n: " << endl;
    cin >> n;
    int mat[n*n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat[i*n + j] = i*n + j + 1;
        }
    }
    stampa(mat,n);
    stampa(trasposta(mat,n),n);
}