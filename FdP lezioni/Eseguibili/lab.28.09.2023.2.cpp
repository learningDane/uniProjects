// questo codice restituisce un quoziente ed un resto

#include <iostream>

using namespace std;

int main() {
    double a;
    double b;
    cout<< "inserire un numero intero" <<endl;
    cin >> a;

    cout<< "inserire un altro numero intero diverso da 0"<< endl;
    cin>> b;
    while (b==0) {
        cout<< "inserire un altro numero intero (non zero)" <<endl;
        cin>> b;
    }

    cout<< "quoziente: " <<a/b << endl;
    cout<< "resto: " << a%b <<endl;
    return 0;
}
