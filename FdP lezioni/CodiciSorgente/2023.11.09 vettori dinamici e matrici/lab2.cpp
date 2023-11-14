//somma gli elementi sulle diagonali di una array
#include <iostream>
using namespace std;

int sommaDiagonali(const int mat[3][3]) {
    int result = 0;
    for (int r = 0; r < 3 ; r++) {
        for (int c = 0; c < 3; c++) {
            if (r==c || r+c==2) {
                result += mat[r][c];
            }
        }
    }
    return result;
}

int main() {
    int mat[3][3];
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3 ; j++) {
            cout << "inserire un numero" << endl;
            cin >> mat[i][j];
        }
    }
    cout << "la somma delle diagonali è: " << sommaDiagonali(mat);
}