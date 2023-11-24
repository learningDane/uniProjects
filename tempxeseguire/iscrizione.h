#ifndef TEMPXESEGUIRE_ISCRIZIONE_H
#define TEMPXESEGUIRE_ISCRIZIONE_H

struct elem {
    char nome[31]; //nome.cognome
    int pettorale; //numero
    elem *pun;
};

class lista {
public:
    elem* l;
    void init();
    void visualizza();
    bool cerca(char nome[]);
    bool cercaNumero(int pettorale);
    bool confronta(char* str1, char* str2);
    bool aggiungi(char nome[31] , int pettorale);
    bool elimina(char nome[]);
    void copia( char daCopiare[], char destinazione[]);
};

#endif //TEMPXESEGUIRE_ISCRIZIONE_H
