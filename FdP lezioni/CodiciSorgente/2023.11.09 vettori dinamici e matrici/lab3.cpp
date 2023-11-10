//somma gli elementi sulle diagonali di una array quadrata di lato n
#include <iostream>
using namespace std;

int sommaDiagonali(const int*mat, int n) {
    int result = 0;
    for (int r = 0; r < n ; r++) {
        for (int c = 0; c < n; c++) {
            if (r==c || r+c== n-1) {
                result += mat[r*n + c];
            }
        }
    }
    return result;
}

int main() {
    int n = 4;
    int mat[n][n];
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ; j++) {
            cout << "inserire un numero" << endl;
            cin >> mat[i][j];
        }
    }
    cout << "la somma delle diagonali è: " << sommaDiagonali(&mat[0][0], n);
}