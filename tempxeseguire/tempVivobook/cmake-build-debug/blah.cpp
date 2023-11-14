#include <iostream>
using namespace std;

struct elem{
    int inf;
    elem* pun;
};

void stampa(elem*&p0) {
    cout << p0;
}

void inTesta(elem*&p0, int a) {
    elem *p;
    p=new elem;
    p->inf =a;
    p->pun=p0;
    p0=p;
    delete p;
}

int ciao() {
    elem*LI=nullptr; //`1` vuota
    inTesta(LI,44);
    inTesta(LI,50);
    stampa(LI);
}