#include <iostream>

using namespace std;

//questo programma chiede 10 numeri e restituisce la somma
int main() {
    int sum = 0;
    int temp;
    for (int i = 0; i < 10; i++) {
        cout << "inserire un numero" << endl;
        cin >> temp;
        sum = sum + temp;
    }
    return sum;
}
