//#include "compito.h"
#include <iostream>
using namespace std;
class Palazzo{
private:
    unsigned int maxPiani; //forse non serve
    unsigned int pianiAttuali = 0;
    bool*piani; //nel costruttore assegno poi la memoria necessaria
public:

    Palazzo(int maxPiani) {
        Palazzo::maxPiani = maxPiani; //forse non serve
        Palazzo::piani = new bool[maxPiani]; //posso assegnare direttamente con input
        Palazzo::pianiAttuali = 1; //il costruttore inizializza con un solo piano
        bool*finestre = new bool[pianiAttuali]; //il piano ha (pianiAttuali)finestre, al momento della costruzione 1, perchè ha un piano
        finestre[0] = false; //la finestra è chiusa
        Palazzo::piani[0] = finestre; //il puntatore 0 deve puntare alle finestre del primo piano
    }
    Palazzo(Palazzo& p1) {

    }
    void stampa(const Palazzo Palazzo) {
        cout << "Palazzo:" << endl;
        for (int pianoAttuale = 0; pianoAttuale < Palazzo::pianiAttuali; pianoAttuale++) {
            cout << "piano 1: ";
            for (int finestraAttuale = 0; finestraAttuale <= pianoAttuale; finestraAttuale++) {
                cout << Palazzo::piani[pianoAttuale][finestraAttuale] ? "aperta " : "chiusa ";
            }
        }
    }
    void aggiungi(Palazzo Palazzo) {

    }
};
int main()
{
    // PRIMA PARTE:
    cout << "Test del costruttore:" << endl;
    Palazzo p1(5); /*
    p1.stampa();
    cout << endl;
    cout << "Test del costruttore di copia:" << endl;
    Palazzo p2(p1);
    p2.stampa();
    cout << endl;
    cout << "Test della aggiungi:" << endl;
    p1.aggiungi();
    p1.aggiungi();
    p1.stampa();
    cout << endl;
    // SECONDA PARTE:
    /*cout << "Test del distruttore:" << endl;
    {
    Palazzo p(20);
    }
    cout << "(p e' stato distrutto)" << endl;

    cout << endl << "Test della cambia:" << endl;
    p1.cambia(2, 1);
    p1.cambia(3, 3);
    p1.stampa();
    cout << endl;
    cout << "Test operator! :" << endl;
    cout << !p1 << endl;
    cout << endl << "Test operator%= :" << endl;
    Palazzo p3(5);
    p3.aggiungi();
    p3.aggiungi();
    p1 %= p3;
    p1.stampa();
    cout << endl;*/
    return 0;
}