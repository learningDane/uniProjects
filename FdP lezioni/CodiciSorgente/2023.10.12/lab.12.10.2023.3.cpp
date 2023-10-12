#include <iostream>

using namespace std;

//questo programma chiede 10 numeri e restituisce la media dei numeri positivi
int main() {
    int sum = 0;
    int temp;
    int j = 0;
    for (int i = 0; i < 10; i++) {
        cout << "inserire un numero" << endl;
        cin >> temp;
        if (temp > 0) {
            sum += temp;
            j++;
        }
    }
    return sum / j;
}
