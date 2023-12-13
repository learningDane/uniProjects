#ifndef TEMPVIVOBOOK_CINEMA_H
#define TEMPVIVOBOOK_CINEMA_H
#include <cstring>
#include<iostream>

class cinema {
    char nome[30];
    int righe;
    int colonne;
    bool*posti = new bool[righe*colonne]; //true= occupato, false=libero
public:
    cinema(int righe, int colonne, char nome[30]);
    bool prenota(int colonna, char riga);
    bool cancella(int colonna, char riga);
    void stampa();
    int quantiLiberi();
    bool prenotaAdiacenti(int postiDaPrenotare);
};


#endif //TEMPVIVOBOOK_CINEMA_H
