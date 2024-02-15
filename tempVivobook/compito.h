#ifndef TEMPVIVOBOOK_COMPITO_H
#define TEMPVIVOBOOK_COMPITO_H
#include <iostream>
using namespace std;

class SpaceAsteroids {
private:
    int punteggio = 0;
    int energiaRim = 5;
    int energiaMax = 5;
    int posizioneX = 4; // posizioneX= larghezza/2
    int larghezza = 9; //compresa tra 3 e 9
    int altezza = 7; //compresa tra 3 e 7
    int**mappa = nullptr; //mappa[x][y]
    bool possoSpostare = true;
    bool possoSparare = true;
    void gameOver();
    void avanza_asteroidi();
public:
    SpaceAsteroids(int naltezza = 7,int nlarghezza = 9, int nenergiaMax = 5);
    friend ostream& operator<<(ostream& os, const SpaceAsteroids&questo);
    void avanza();
    bool colloca_asteroide(int col);
    SpaceAsteroids& operator<<=(int n);
    SpaceAsteroids& operator>>=(int n);
    SpaceAsteroids& operator|=(int n);
};


#endif //TEMPVIVOBOOK_COMPITO_H
