#include<iostream>
using namespace std;

struct elem{
    int informazione;
    elem* punSuccessivo;
};

void aggiungiElem(elem*& primo, int newElemInf){
    elem* temp = new elem;
    temp-> informazione = newElemInf;
    temp-> punSuccessivo = primo;
    primo=temp;
    delete temp;
}

void stampaLista(elem*&elemento,int lung) {
    cout << elemento->informazione;
    lung--;
    if (lung != 0) {
        stampaLista((elemento->punSuccessivo));
    }
}

int main() {
    int a = 45;
    elem* primo = nullptr;
    aggiungiElem(primo,a);
    aggiungiElem(primo,85);
    stampaLista(primo,2);
}