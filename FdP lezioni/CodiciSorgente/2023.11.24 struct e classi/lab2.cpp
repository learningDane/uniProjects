//main.cpp=
#include "iscrizione.h"
#include <iostream>
using namespace std;
int main() {
    lista L;
    L.init();
    L.visualizza();
    L.aggiungi("mario.bianchi", 24);
    L.aggiungi("sergio.rossi", 6);
    L.aggiungi("sergio.rossi", 4); // gia' presente
    L.aggiungi("gianni.verdi", 32);
    L.aggiungi("luigi.neri", 6); // gia' presente
    L.visualizza();
    cout << L.cerca("mario.bianchi") << endl;
    L.elimina("mario.bianchi");
    cout << L.cerca("mario.bianchi") << endl;
    L.visualizza();
    return 0;
}
//iscrizione.cpp=
#include "iscrizione.h"
#include <iostream>

using namespace std;

void lista::init() {
    l = nullptr;
}

void lista::visualizza() {
    elem*current = l;
    while (current != nullptr) {
        for (int i = 0; i < 31; i++) {
            if (current->nome[i] == '\0') { break; }
            else {
                cout << current->nome[i];
            }
        }
        cout << '\t' << current->pettorale << endl;
        current = current->pun;
    }
}

bool lista::confronta(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2)
            return false;
        str1++;
        str2++;
    }
    return true;
}

bool lista::cerca(char nome[]) {
    elem*head=l;
    while (head != nullptr) {
        if (confronta(head->nome, nome)) { return true; }
        head = head->pun;
    }
    return false;
}

bool lista::cercaNumero( int pettorale) {
    elem*head=l;
    while (head != nullptr) {
        if (head->pettorale == pettorale) { return true; }
        head = head->pun;
    }
    return false;
}

void lista::copia( char daCopiare[], char destinazione[]) {
    int i = 0;
    while (daCopiare[i] != '\0') {
        destinazione[i] = daCopiare[i];
        i++;
    }
    destinazione[i] = '\0';
}

bool lista::aggiungi( char nome[31], int pettorale) {
    elem*&head=l;
    if (cerca( nome) || cercaNumero(pettorale)) { return false; }
    elem *nuovoIscritto = new elem;
    copia(nome, nuovoIscritto->nome);
    nuovoIscritto->pun = nullptr;
    nuovoIscritto->pettorale = pettorale;
    if (head == nullptr) {
        head = nuovoIscritto;
        return true;
    }
    elem *temp = head;
    while (temp->pun != nullptr) {
        temp = temp->pun;
    }

    temp->pun = nuovoIscritto;
    return true;
}

bool lista::elimina( char nome[]) {
    elem*&head= l;
    if (!cerca(nome)) {
        return false;  // Name not found
    }

    // Special case: If the target name is in the first node
    if (confronta(head->nome, nome)) {
        elem *toDelete = head;
        head = head->pun;
        delete toDelete;
    } else {
        // Search for the target name in the rest of the list
        elem *temp = head;
        while (temp->pun != nullptr && !confronta(temp->pun->nome, nome)) {
            temp = temp->pun;
        }

        // Check if the target name is found
        if (temp->pun == nullptr) {
            return false;  // Target name not found
        }

        // Adjust pointers to skip the node with the target name
        elem *toDelete = temp->pun;
        temp->pun = temp->pun->pun;
        delete toDelete;
    }

    return true;
}

//iscrizione.h=
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
