#include <iostream>

using namespace std;

//questo programma chiede due numeri b ed e, ed eleva b alla potenza di e
int main() {
    int b;
    int e;
    cout << "inserire b" << endl;
    cin >> b;
    cout << "inserire e" << endl;
    cin >> e;
    if (e < 0) { e = 0; }
    int result = b;
    if (b == 0 && e == 0) { cout << "indeterminato"; }
    else {
        if (e == 0) { cout << "1" << endl; }
        else {
            for (int i = 1; i < e; i++) {
                result = result * b;
            }
        }
        cout << "il risultato è: " << result << endl;
    }
    return 0;
}
