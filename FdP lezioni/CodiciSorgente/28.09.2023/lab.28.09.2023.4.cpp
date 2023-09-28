// questo programma chiede all'utente una equazione di primo grado e restituisce il valore di x

#include <iostream>
using namespace std;

int main() {
    double a;
    double b;

    cout << "inserire a (ax +b = 0)" << endl;
    cin >> a;

    cout << "inserire b (ax +b = 0)" << endl;
    cin >> b;

    cout << "the solution is: " << -b/a << endl;
}
