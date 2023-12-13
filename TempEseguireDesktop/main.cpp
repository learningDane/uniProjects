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

        // Allocate memory for posti array
        cinema::posti = new bool[righe * colonne];
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
                cout << (char)('A' + r - 1);
            }
            for (int c = 0; c < cinema::colonne; c++) {
                if (r == 0) {
                    cout << c + 1 << '\t';
                } else {
                    if (cinema::posti[(r - 1) * cinema::colonne + c]) {
                        cout << "*" << '\t';
                    } else {
                        cout << ' ' << '\t';
                    }
                }
            }
        }
    }
};

int main() {
    cinema c(3, 7, "Moderno");
    c.prenota('A', 4);
    c.prenota('C', 1);
    c.prenota('C', 2);
    c.prenota('C', 3);
    c.prenota('C', 4);
    c.prenota('C', 5);
    c.prenota('C', 6);
    c.prenota('C', 7);
    c.prenota('B', 4);
    c.stampa();
}