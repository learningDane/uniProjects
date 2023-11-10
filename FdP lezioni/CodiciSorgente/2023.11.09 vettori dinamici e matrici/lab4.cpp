// stampa un serpenetllo di numeri di r righe e c colonne
#include <iostream>
using namespace std;
int* creaSerpente(int r, int c) {
    int * serp = new int[r*c];
    for(int i = 0 ; i < r ; i++) {
        for (int j = 0; j < c ; j++) {
            if (i%2 == 0) {
                serp[i*c + j]= i*c + j + 1;
            }
            else {
                serp[i*c + j]= i*c + (c - j);
            }
        }
    }
    return serp;
}


int main() {
    int r;
    int c;
    cout << "inserire r e c" << endl;
    cin >> r;
    cin >> c;
    int *serp = creaSerpente(r,c);
    for(int i = 0 ; i < r ; i++) {
        for (int j = 0; j < c ; j++) {
            cout << serp[i*c + j] << '\t';
        }
        cout << endl;
    }
}
