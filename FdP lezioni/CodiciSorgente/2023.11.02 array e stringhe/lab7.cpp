// vquesto programma cerca un determinato carattere in una stringa
#include <iostream>
#include <cstring>
using namespace std;

int search(string stringa, char carattere) {
    for (int i = 0; i < stringa.length() / 2 ; i++)  {
        if (stringa[i] == carattere) { return i;}
    }
}

int main() {
    string stringa= "Fondamenti di Programmazione";
    char carattere = 'd';
    cout << "il carattere " << carattere << " si trova in posizione " << search(stringa , carattere) << endl;
}

