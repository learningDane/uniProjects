//main.cpp=
#include <iostream>
#include "iscrizione.h"

using namespace std;

int main() {
    elem *L;
    init(L);
    visualizza(L);
    aggiungi(L, "mario.bianchi", 24);
    aggiungi(L, "sergio.rossi", 6);
    aggiungi(L, "sergio.rossi",4);
    aggiungi(L, "gianni.verdi", 32);
    aggiungi(L, "luigi.neri",6);
    visualizza(L);
    cout << cerca(L, "mario.bianchi") << endl;
    elimina(L, "mario.bianchi");
    cout << cerca(L, "mario.bianchi") << endl;
    visualizza(L);
    return 0;
}

//iscrizione.cpp=
#include "iscrizione.h"
#include <iostream>

using namespace std;

void init(elem *&L) {
    L = nullptr;
}

void visualizza(elem *current) {
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

bool confronta(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2)
            return false;
        str1++;
        str2++;
    }
    return true;
}

bool cerca(elem *head, char nome[]) {
    while (head != nullptr) {
        if (confronta(head->nome, nome)) { return true; }
        head = head->pun;
    }
    return false;
}

bool cercaNumero(elem *head, int pettorale) {
    while (head != nullptr) {
        if (head->pettorale == pettorale) { return true; }
        head = head->pun;
    }
    return false;
}

void copia(const char daCopiare[], char destinazione[]) {
    int i = 0;
    while (daCopiare[i] != '\0') {
        destinazione[i] = daCopiare[i];
        i++;
    }
    destinazione[i] = '\0';
}

bool aggiungi(elem *&head, char nome[31], int pettorale) {
    if (cerca(head, nome) || cercaNumero(head, pettorale)) { return false; }
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

bool elimina(elem *&head, char nome[]) {
    if (!cerca(head, nome)) {
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

void init(elem*&L);
void visualizza(elem*current);
bool cerca(elem*head,char nome[]);
bool cercaNumero(elem*head,int pettorale);
bool confronta(char* str1, char* str2);
bool aggiungi(elem*&head , char nome[31] , int pettorale);
bool elimina(elem*&head,char nome[]);

#endif //TEMPXESEGUIRE_ISCRIZIONE_H
