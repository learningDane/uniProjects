#ifndef DAVIDESQUERI_COMPITO_H
#define DAVIDESQUERI_COMPITO_H
#include<iostream>
using namespace std;


class SpaceAsteroids {
    int altezza = 7;
    int larghezza = 9;
    int energiaMax = 5;
    int energiaRim = 5;
    int punteggio = 0;
    int punteggioMax = 0;
    int**mappa = nullptr; //mappa[posizioneX][posizioneY]
    int posizioneX = 4;
    bool possoSpostare = true;
    bool possoSparare = true;
    void avanza_asteroidi();
    void gameOver();
public:
    SpaceAsteroids(const int naltezza, const int nlarghezza, const int nenergiaMax);
    bool colloca_asteroide(int colonna);
    void avanza();
    friend ostream& operator<<(ostream& os,const SpaceAsteroids&questo);
    virtual ~SpaceAsteroids();
    SpaceAsteroids& operator<<=(int n);
    SpaceAsteroids& operator>>=(int n);
    SpaceAsteroids& operator|=(int n);
};


#endif //DAVIDESQUERI_COMPITO_H

// fine file