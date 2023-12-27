#include <iostream>

using namespace std;

class PuzzleBobble {
private:
    char bubbles[10][6]; //righe*colonne
public:
    PuzzleBobble() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 6; j++) {
                bubbles[i][j] = ' ';
            }
        }
    }

    friend ostream& operator<<(ostream &os, const PuzzleBobble pb) { //ostream& = cosa viene prima dell'operatore <<, quindi std::cout
        for (int i = -1; i < 11; i++) {
            for (int j = -1; j < 7; j++) {
                // ========
                if (i == -1 || i == 10) {
                    os << '=';
                    continue;
                }
                    //   |
                else if (j == -1 || j == 6) {
                    os << '|';
                }
                    // bubble
                else {
                    os << pb.bubbles[i][j];
                }
            }
            os << std::endl;
        }
        return os;
    }

    PuzzleBobble& fire(short unsigned int colonna, char colore) {
        for (int riga = 0; riga < 10; riga++) {
            if (PuzzleBobble::bubbles[riga][colonna] == ' ') {
                PuzzleBobble::bubbles[riga][colonna] = colore; // bubble = 'Y' ecc
                return *this;
            }
        }
        return *this;
    }

    operator int() const {
        short unsigned int height = 0;
        for (int riga; riga < 10; riga++) {
            for (int col; col < 6; col++) {
                if (PuzzleBobble::bubbles[riga][col] != ' ') {
                    height++;
                    break;
                }
            }
        }
        return height;
    }

    bool check(int riga, int col) {
        char color = bubbles[riga][col];
        int temp = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0 ; col < 6; col++) {
                if (bubbles[i][j] == color) {
                    temp++;
                    //temp è  il numero di bolle consecutive dello stesso colore
                    if (temp == 3) {
                        
                    }
                }
            }
        }
    }

};

int main() {
    // PRIMA PARTE:
    cout << "--- PRIMA PARTE ---" << endl;
    cout << "Test costruttore" << endl;
    PuzzleBobble pb;
    cout << pb;

    cout << "Test funzione fire" << endl;
    pb.fire(0,'R').fire(1,'R').fire(0,'B').fire(2,'Y');
    pb.fire(3,'Y').fire(3,'Y').fire(0,'B').fire(3,'G');
    cout << pb;

    cout << "Test operatore int" << endl;
    cout << "Altezza: " << (int)pb << endl; /*
    // SECONDA PARTE:
    cout << "--- SECONDA PARTE ---" << endl;
    cout << "Test funzionalita' scoppio bolle" << endl;
    pb.fire(0,'B'); // scoppio verticale di 3 bolle
    pb.fire(0,'R'); // no scoppio
    pb.fire(5,'Y').fire(4,'Y'); // scoppio orizzontale di 4 bolle
    pb.fire(3,'G'); // no scoppio
    cout << pb;

    cout << "Test funzione scroll" << endl;
    pb.scroll().scroll();
    cout << pb;
    cout << "Test funzione compact" << endl;
    pb.compact();
    cout << pb;
    return 0; */
}