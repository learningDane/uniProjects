#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    cout<< "inserire un numero intero" <<endl;
    cin>> a;
    while (b==0) {
        cout<< "inserire un altro numero intero (non zero)" <<endl;
        cin>> b;
    }

    cout<< "quoziente: " <<a/b << endl;
    cout<< "resto: " << a%b <<endl;
    return 0;
}