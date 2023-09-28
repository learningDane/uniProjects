#include <iostream>

using namespace std;

int main() {

    int n1;
    int n2;
    int r;
    int mcd;

    start: // this is a label

    number1: //questa è una label, con goto il programma ritorna a quest ariga
    cout << "Insert first number" << endl;
    cin >> n1;
    if (n1 <= 0) {
        cout << "number must be positive" << endl; //non accetta numeri negativi
        goto number1;
    } //questo va alla riga number1

    number2:
    cout << "insert second number (must be smaller than first)" << endl;
    cin >> n2;
    if (n2 <= 0) {
        cout << "number must be positive" << endl; //numeri positiviiiii
        goto number2;
    } else if (n2 > n1) {
        cout << "Second number must be smaller than first! " << endl;
        goto start;
    }

    while (n1 % n2 != 0) {
        r = n1 % n2;
        n1 = n2;
        n2 = r;
    }
    mcd = n2;
    cout << "the McD is " << mcd << " !" << endl;

    return 0;

}
