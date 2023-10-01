// questo programma chiede un nuemro romano e ne calcola l'equivalente in base 10
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    int x = 0; // il numero equivalente alla lettera
    string s;
    cout << "inserire un numero romano" << endl;
    cin >> s;
    int tot = 0;
    int prec = 0; // il numero della lettera precedente
    for (n = 0; n < s.length(); n++) {
        if (s.at(n) == 'M') { x = 1000; }
        else if (s.at(n) == 'D') { x = 500; }
        else if (s.at(n) == 'C') { x = 100; }
        else if (s.at(n) == 'L') { x = 50; }
        else if (s.at(n) == 'X') { x = 10; }
        else if (s.at(n) == 'V') { x = 5; }
        else if (s.at(n) == 'I') { x = 1; }
        else { cout << "error, insert only Roman Numbers (Capitalized)" << endl; }
        if (prec >= x) {
            tot = tot + x;
        } else { tot = tot + x - 2 * prec; }
        prec = x;
    }
    cout << tot << endl;
}