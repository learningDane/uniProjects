#include <iostream>

using namespace std;

int i = 0;
long double n;
long double n1;
int j;

int main() {
    cout << "inserisci primo numero" << endl;
    cin >> n;
    cout << "quanti decimali desideri?" << endl;
    cin >> j;

    while (i < j) {
        n = 0.5 * (n + (2 / n));
        cout << n << endl;
        n1 = n;
        i++;
    }

    cout << "sqrt{2} = " << n << endl;

}