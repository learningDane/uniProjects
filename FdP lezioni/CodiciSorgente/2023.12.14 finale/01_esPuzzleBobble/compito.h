#include <iostream>
using namespace std;

#define WIDTH 6
#define HEIGHT 10

class PuzzleBobble{
    char tiles[HEIGHT][WIDTH];
    // Funzione di appoggio che conta le bolle dello stesso colore di quella
    // in (row,column) che sono nella stessa fila verticale o orizzontale.
    // Se pop_them è true, le elimina dallo schema anche.
    // (per funzionalita' seconda parte)
    int count_bubbles(int row, int column, bool pop_them);

public:
    // PRIMA PARTE
    PuzzleBobble();
    PuzzleBobble& fire(int, char);
    operator int()const;
    friend ostream& operator<<(ostream&, const PuzzleBobble&);

    // SECONDA PARTE
    PuzzleBobble& scroll();
    void compact();
};
