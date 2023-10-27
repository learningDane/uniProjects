#include <iostream>
//chiede come input la lunghezza del lato di base del triangolo isoscile e stampa due triangolo isoscili, uno con la bse verso làlto, làltro con la base verso sinistra.
using namespace std;

void spaces(int x) {
    for (int y = 0; y < x; y++) {
        cout << "  ";
    }
}

int main() {
    int n;
    cout << "inserire lunghezza lato di base" << endl;
    cin >> n;
    if (n % 2 == 0) { n++; }
    for (int i = 0; i < n; i += 2) {
        spaces(i / 2);
        for (int j = 0; j < n - i; j++) {
            cout << "* ";
        }
        spaces(i / 2);
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i < n + 1; i++) {
        //stampa riga
        for (int j = 0; (j < i && i <= n / 2 + 1) || (j < n - i + 1 && i >= n / 2 + 1); j++) {
            cout << "* ";
        }
        cout << endl;
    }
}
