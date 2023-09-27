#include <iostream>
//#include "sdfdsf.h"           dove il file tra virgolette è nel progetto

using namespace std;

int main() {

    cout<<"hello world"<<endl;
    // cout<<xxx; stampa xxx e non va a capo
    // <<endl; va a capo

    unsigned int N = 23; //crea una variabile intera positiva a 32 bit e la inizializza a 23
    int a = -1;

    cout<<N<<endl; //stampa il contenuto tra << << e va a capo
    cout<<N;
    cout<< endl; // va a capo (ends the line)

    cout<< "risultato = "<< N + a <<endl;

    unsigned int a1 = N % 2; // % fa operazione di MOD, ovvero restituisce il resto dell'operazione
    cout<< a1 <<endl;

    unsigned short int B = 12; // short int è un intero a 16 bit
    unsigned long int C = 12434; //long int può allocare un intero su 64 bit, ma non è detto

    return 0;
}
