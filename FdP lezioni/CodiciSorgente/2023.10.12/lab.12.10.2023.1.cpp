#include <iostream>

using namespace std;

//questo programma chiede numeri fino a che non gliene si dia una positivo e poi lo restituisce
int main() {
    int input;
    do {
        cout << "inserire un numero positivo" << endl;
        cin >> input;
    } while (input < 0);
    cout << "il numero è: " << input << endl;
    return 0;
}
