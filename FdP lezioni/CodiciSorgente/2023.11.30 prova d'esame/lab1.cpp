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
        if (cinema::posti[intriga * cinema::colonne + colonna - 1]) {
            return false;
        }
        cinema::posti[intriga * cinema::colonne + colonna - 1] = true;
        return true;
    }

    void stampa() {
        cout << "Nome del cinema: " << cinema::nome << endl;
        for (int r = - 1; r < cinema::righe; r++) {
            //stampa 0 A B C...
            if (r == - 1) { cout << 0 << '\t'; }
            else { cout << (char)('A' + r) << '\t';}
            //
            for (int c = 0; c < cinema::colonne; c++) {
                if (r == -1) { //stampa 1 2 3 4..
                    cout << c + 1 << '\t';
                    continue;
                }
                if (cinema::posti[r*cinema::colonne + c]) { //posto occupato
                    cout << '*' << '\t';
                    continue;
                }
                else { //posto libero
                    cout << '_' << '\t';
                    continue;
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    bool cancella(char riga, int colonna) {
        short unsigned int intriga = riga - 'A';
        if (!(cinema::posti[intriga * cinema::colonne + colonna - 1])) {
            return false;
        }
        cinema::posti[intriga * cinema::colonne + colonna - 1] = false;
        return true;
    }

    int quantiLiberi() {
        int postiLiberi = 0;
        for (int i = 0; i < cinema::colonne*cinema::righe; i++) {
            if (!(cinema::posti[i])) {
                postiLiberi++;
            }
        }
        return postiLiberi;
    }

    bool prenotaAdiacenti(int postiDaPrenotare) {
        short unsigned int postiAdiacenti = 0;
        short unsigned int primoPostoConfermato = 0;
        for (int postoAttuale = 0; postoAttuale < cinema::righe*cinema::colonne; postoAttuale++) {
            if (postoAttuale - (cinema::colonne - 1) == 0 || (postoAttuale - (cinema::colonne - 1))%cinema::colonne == 0) { //è finita la fila
                postiAdiacenti = 0;
                continue;
            }
            if (postiAdiacenti == 0) { //ricomincia da capo
                primoPostoConfermato = postoAttuale;
            }
            else if (postiAdiacenti == postiDaPrenotare) { //trovato abbastanza posti adiacenti
                for (int i = 0; i < postiDaPrenotare; i++) { //prenoto i posti
                    cinema::posti[primoPostoConfermato + i] = true;
                }
                return true;
            }
            //
            if (cinema::posti[postoAttuale]) { //il posto è occupato
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
