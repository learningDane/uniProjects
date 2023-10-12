#include <iostream>

using namespace std;

//questo programma chiede numero naturale e stampa due quadrati di asterischi, uno pieno ed uno vuoto
int main() {
    int num;
    cout << "inserire un numero naturale" << endl;
    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i == 0 || i == num - 1) {
                cout << "* ";
                if (j == num - 1) { cout << endl; }
            } else {
                if (j == 0) { cout << "* "; }
                else if (j == num - 1) { cout << "*" << endl; }
                else { cout << "  "; }
            }
        }
    }

    return 0;
}
