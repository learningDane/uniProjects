// stampa un serpenetllo di numeri di r righe e c colonne ma con **
#include <iostream>
using namespace std;
int** creaSerpente(int r, int c) {
    int** serp = new int*[r];
    for (int i = 0; i < r; i++) {
        serp[i] = new int[c];
        for (int j = 0; j < c; j++) {
            if (i % 2 == 0) {
                serp[i][j] = i * c + j + 1;
            } else {
                serp[i][j] = i * c + (c - j);
            }
        }
    }
    return serp;
}

int main() {
    int r, c;
    cout << "Inserire r e c: " << endl;
    cin >> r >> c;

    int** serp = creaSerpente(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << serp[i][j] << '\t';
        }
        cout << endl;
    }

    for (int i = 0; i < r; i++) {
        delete[] serp[i];
    }
    delete[] serp;
}