#include <iostream>
using namespace std;

class cinema {
    char nome[30];
    int righe;
    int colonne;
    bool* posti;

public:
    cinema(int righe, int colonne, char* nome) : righe(righe), colonne(colonne) {
        for (int i = 0; i < 30; i++) {
            if (nome[i] == '\0') {
                break;
            } else {
                cinema::nome[i] = nome[i];
            }
        }
        cinema::posti = new bool[righe * colonne];
        for (int i = 0; i < righe*colonne; i++) {
            cinema::posti[i]=false;
        }
    }

    ~cinema() {
        delete[] posti;
    }

    bool prenota(char riga, int colonna) {
        short unsigned int intriga = riga - 'A';
        if (cinema::posti[intriga * cinema::colonne + colonna]) {
            return false;
        }
        cinema::posti[intriga * cinema::colonne + colonna] = true;
        return true;
    }

    void stampa() {
        for (int r = 0; r < cinema::righe; r++) {
            if (r == 0) {
                cout << 0 << '\t';
            } else {
                cout << (char)('A' + r - 1) << '\t';
            }
            for (int c = 0; c < cinema::colonne; c++) {
                if (r == 0) {
                    cout << c + 1 << '\t';
                } else {
                    if (cinema::posti[(r) * cinema::colonne + c]) {
                        cout << "*" << '\t';
                    } else {
                        cout << ' ' << '\t';
                    }
                }
            }
            cout << endl;
        }
    }

    bool cancella(char riga, int colonna) {
        short unsigned int intriga = riga - 'A';
        if (!(cinema::posti[intriga * cinema::colonne + colonna])) {
            return false;
        }
        cinema::posti[intriga * cinema::colonne + colonna] = false;
        return true;
    }

    int quantiLiberi() {
        int postiLiberi = 0;
        for (int i = 0; i < cinema::colonne*cinema::righe; i++) {
            if (!(cinema::posti[i])) {
                postiLiberi++;
            }
        }
        return postiLiberi - 1;
    }

    bool prenotaAdiacenti(int postiDaPrenotare) {
        short unsigned int postiAdiacenti = 0;
        short unsigned int primoPostoConfermato = 0;
        for (int postoAttuale = 0; postoAttuale < cinema::righe*cinema::colonne; postoAttuale++) {
            if (postiAdiacenti == 0) {
                primoPostoConfermato = postoAttuale;
            }
            else if (postiAdiacenti == postiDaPrenotare) {
                for (int i = 0; i < postiDaPrenotare; i++) {
                    cinema::posti[primoPostoConfermato + i] = true;
                }
                return true;
            }
            //
            if (cinema::posti[postoAttuale]) {
                postiAdiacenti = 0;
                continue;
            }
            else { //il posto è vuoto
                postiAdiacenti++;
            }
        }
        return false;
    }
};

int main() {
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
    c.stampa();
    c.cancella('B',4);
    c.stampa();
    // SECONDA PARTE
    cout << "Il numero di posti liberi in c e': " << c.quantiLiberi() << endl;
    c.prenotaAdiacenti(4);
    c.stampa();
    return 0;
}