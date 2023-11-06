#include <iostream>

using namespace std;

int main() {
    int scelta;
    cout << "Menu Operazioni" << endl;
    cout << "1: minimo di tre interi" << endl;
    cout << "2: massimo di tre interi" << endl;
    cout << "3: media di tre interi" << endl;
    cout << "0: esci" << endl;
    cout << "Scelta?" << endl;
    cin >> scelta;
    while (scelta > 3) {
        cout << "non contemplato, riprovare" << endl;
        cin >> scelta;
    }
    if (!scelta) {
        return 0;
    }
    int result;
    int a;
    int b;
    int c;
    cout << "inserire a" << endl;
    cin >> a;
    cout << "inserire b" << endl;
    cin >> b;
    cout << "inserire c" << endl;
    cin >> c;
    switch (scelta) {
        case 1:
            if (a < b && a < c) { result = a; }
            else if (c < a && c < b) { result = c; }
            else if (b < a && b < c) { result = b; }
        case 2:
            if (a > b && a > c) { result = a; }
            else if (c > a && c > b) { result = c; }
            else if (b > a && b > c) { result = b; }
        case 3:
            result = (a + b + c)/3;
            break;
    }
    cout << result;
}
