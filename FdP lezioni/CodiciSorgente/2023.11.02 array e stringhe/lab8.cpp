//questo programma conta le parole nelle stringhe
#include <iostream>
#include <cstring>

using namespace std;

int conta(string stringa) {
    int parole =0;
    for (int i = 0; i < stringa.length(); i++) {
        if (stringa[i] == ' ') { continue;}
        else if (stringa[i] != ' ') {
            if (stringa[i+1] == '\t') { return parole+1;}
            else if (stringa[i+1] == ' ') {parole++;}
            else { continue;}
        }
    }
    return parole;
}

int main() {
    string stringa1 = "Lorem ipsum  dolor   sit amet  ";
    string stringa2 = "  Lorem ipsum  dolor   sit amet  ";
    cout << "Numero di parole nella prima cstring: " << conta(stringa1) << endl;
    cout << "Numero di parole nella seconda cstring: " << conta(stringa2) << endl;
}