#ifndef PIETRODEMARIA_COMPITO_H
#define PIETRODEMARIA_COMPITO_H

#include <iostream>
#include <cstring>
using namespace std;
extern int record;

class SpaceAsteroids {
    char* schermo;
    int* energiaRaggi;
    int colonne, righe, energia;
    int energiaStart;
    int punteggio;
    bool reset;
    bool avanzato;
    bool avanzatoLaser;
    void pulisciSchermo();
    void avanza_asteroidi();
public:
    //PRIMA PARTE
    //static int record;
    SpaceAsteroids(int,int,int);
    friend ostream& operator<<(ostream&,const SpaceAsteroids&);
    bool colloca_asteroide(int);
    void avanza();
    //SECONDA PARTE
    ~SpaceAsteroids(){ delete[] schermo;};
    SpaceAsteroids& operator<<=(int n);
    SpaceAsteroids& operator>>=(int n);
    SpaceAsteroids& operator|=(int n);
};
//int SpaceAsteroids::record = 0;

#endif //PIETRODEMARIA_COMPITO_H

// fine file