//questo pgoramma controlla che la stringa inserita sia palindroma o meno
#include <iostream>
#include <cstring>
using namespace std;

bool pali( string stringa) {
    for (int i = 0; i < stringa.length() / 2; i++) {
        if (stringa[i] != stringa[stringa.length() -1 - i]) { return false;}
    }
    return true;
}
int main() {
    string stringa;
    cout << "inserire una parola max 40 caratteri" << endl;
    cin >>  stringa;
    return pali(stringa);
}
 
