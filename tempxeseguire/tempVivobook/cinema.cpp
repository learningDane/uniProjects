#include "cinema.h"

cinema::cinema(int righe, int colonne, char nome[30]) {
    strcpy(cinema::nome, nome);
    cinema::righe = righe;
    cinema::colonne = colonne;
}

bool cinema::prenota(int colonna, char riga) {
    const int intriga = riga-'A';
    std::cout << intriga; /*
    if (cinema::posti[cinema::colonne*intriga + colonna]) {
        return false;
    }
    else {
        cinema::posti[cinema::colonne*intriga + colonna] = true;
        return true;
    } */
}
