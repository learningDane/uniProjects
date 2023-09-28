// questo programma chiede l'equazione di una retta ed una ascissa e restituisce il valore dell'ordinata

#include <iostream>

using namespace std;

int main() {
    double a;
    double b;
    double x;

    cout << "inserire a (y = ax +b)" << endl;
    cin >> a;

    cout << "inserire b " << endl;
    cin >> b;

    cout << "inserire l'ascissa" << endl;
    cin >> x;

    cout << "il valore dell'ordinata è: " << a * x + b << endl;
    return 0;
}
