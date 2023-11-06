#include <iostream>
// chiede l'ordine della tavola pitagorica da stampare e la stampa (richiesto di usare una funzione per stampare le file)
using namespace std;

void stampariga(int i, int n) {
    for (int j = 0; j < n; j++) {
        cout << i + j + 1 << " ";
        if (i + j + 1 < 10) {
            cout << " ";
        }
    }
}

int main() {
    int n;
    cout << "inserire ordine della tavola pitagorica" << endl;
    cin >> n;
    for (int i = 0; i < n; i++) {
        stampariga(i, n);
        cout << endl;
    }
}
