#include <iostream>
// questo codice prende come input n la lunghezza del lato e stampa un triangolo rettangolo isoscile di asterischi di lato n, e poi uno al contrario
using namespace std;

int main() {
    int n;
    cout << "lunghezza lato > 0" << endl;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            cout << "  ";
        }
        for (int j = i; j < n; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
