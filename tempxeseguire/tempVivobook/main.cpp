#include <iostream>
using namespace std;

class cinema{
    char nome[30];
    int righe;
    int colonne;
    bool*posti = new bool[righe*colonne];
public:
    cinema(int righe , int colonne, char*nome) {
        for (int i =0; i <30 ; i++) {
            if (nome[i] == '\0') {
                break;
            }
            else {
                cinema::nome[i] = nome[i];
            }
        }
    }
    bool prenota(char riga, int colonna) {
        short unsigned int intriga = riga - 'A';
        if (cinema::posti[intriga*cinema::colonne + colonna]) { return false;}
        cinema::posti[intriga*cinema::colonne + colonna] = true;
        return true;
    }
    void stampa() {
        for (int r = 0; r < cinema::righe; r++) {
            for (int c = 0; c < cinema::colonne; c++) {

            }
        }
    }
};

int main(){
// PRIMA PARTE
    cinema c(3,7,"Moderno");
    c.prenota('A',4);
    c.prenota('C',1);
    c.prenota('C',2);
    c.prenota('C',3);
    c.prenota('C',4);
    c.prenota('C',5);
    c.prenota('C',6);
    c.prenota('C',7);
    c.prenota('B',4);
    c.stampa(); /*
    c.cancella('B',4);
    c.stampa(); */
}