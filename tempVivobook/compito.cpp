#include "compito.h"

int record = 0;

SpaceAsteroids::SpaceAsteroids(int naltezza, int nlarghezza, int nenergiaMax) {
    if (naltezza > 2 && naltezza < 8) {
        altezza = naltezza;
    }
    if (nlarghezza > 2 && nlarghezza < 10 && nlarghezza%2 == 1) {
        larghezza = nlarghezza, posizioneX = larghezza/2;
    }
    if (nenergiaMax > 0) {
        energiaMax = nenergiaMax, energiaRim = energiaMax;
    }
    mappa = new int*[larghezza];
    for (int i = 0; i < larghezza; i++) {
        mappa[i] = new int[altezza];
        for (int j = 0; j < altezza; j++) {
            mappa[i][j] = 0;
        }
    }
}

ostream &operator<<(ostream &os, const SpaceAsteroids &questo) {
    os << "Punteggio: " << questo.punteggio << endl;
    os << "Record: " << record << endl;
    os << "Energia: " << questo.energiaRim << endl;
    for (int j = questo.altezza ; j > -1; j--) {
        for (int i = 0; i < questo.larghezza; i++) {
            if (j == questo.altezza) {
                os << "_";
            }
            else if (j==0) {
                if (i == questo.posizioneX) {
                    os << "A";
                }
                else if (questo.mappa[i][j] == 0) {
                    os << "_";
                }
                else if (questo.mappa[i][j] == 1) {
                    os << "X";
                }
            }
            else {
                if (questo.mappa[i][j] > 10) {
                    os << "|";
                }
                else if (questo.mappa[i][j] == 0) {
                    os << " ";
                }
                else if (questo.mappa[i][j] == 1) {
                    os << "X";
                }
            }
        }
        os << endl;
    }
    os << endl;
    for (int j = questo.altezza - 1; j > -1; j--) {
        for (int i = 0; i < questo.larghezza ; i++) {
            os << questo.mappa[i][j] << "\t";
        }
        os << endl;
    }
    return os;
}

void SpaceAsteroids::avanza() {
    possoSparare = true;
    possoSpostare = true;
    for (int j = altezza - 1; j > 0; j--) {
        for (int i = 0; i < larghezza; i ++) {
            for (int a = 0; a < 2; a++) {
                if (mappa[i][j + a - 1] > 10) {
                    if (j+a < altezza) {
                        if (mappa[i][j+a] == 1) { punteggio++;}
                        mappa[i][j+a] = mappa[i][j + a - 1] - mappa[i][j+a];
                        mappa[i][j + a - 1] = 0;
                        mappa[i][j + a] = mappa[i][j + a] > 10 ? mappa[i][j + a] : 0;
                    }
                }
            }
        }
    }
    avanza_asteroidi();
}

void SpaceAsteroids::avanza_asteroidi() {
    if (mappa[posizioneX][1] == 1) {
        gameOver();
        return;
    }
    for (int i = 0; i < larghezza; i++) {
        for (int j = 0; j < altezza - 1; j++) {
            if (j == 0) {
                mappa[i][j] = 0;
            }
            mappa[i][j] = mappa[i][j+1];
            mappa[i][j+1] = 0;
        }
    }
    mappa[posizioneX][0] = -1;
    energiaRim = energiaRim < energiaMax ? energiaRim + 1 : energiaRim;
    punteggio++;
    record = record > punteggio ? record : punteggio;
}

bool SpaceAsteroids::colloca_asteroide(int col) {
    if (col < 1 || col > larghezza || mappa[col - 1][altezza - 1] != 0) { return false;}
    mappa[col - 1][altezza - 1] = 1;
    return true;
}

void SpaceAsteroids::gameOver() {
    punteggio = 0;
    energiaRim = energiaMax;
    posizioneX = larghezza/2;
    possoSparare = true;
    possoSpostare = true;
    for (int i = 0; i < larghezza; i++) {
        for (int j = 0; j < altezza; j++ ) {
            mappa[i][j] = 0;
        }
    }
}

SpaceAsteroids &SpaceAsteroids::operator<<=(int n) {
    if (!possoSpostare) { return *this;}
    while (n>0 && posizioneX > 0) {
        if (posizioneX > 0 && mappa[posizioneX - 1][0] == 1) {
            gameOver();
            return *this;
        }
        n--;
        posizioneX--;
    }
    return *this;
}

SpaceAsteroids &SpaceAsteroids::operator>>=(int n) {
    if (!possoSpostare) { return *this;}
    while (n>0 && posizioneX < larghezza) {
        if (posizioneX<larghezza-1 && mappa[posizioneX + 1][0] == 1) {
            gameOver();
            return *this;
        }
        n--;
        posizioneX++;
    }
    return *this;
}

SpaceAsteroids &SpaceAsteroids::operator|=(int n) {
    if (n < 1 || !possoSparare) { return *this;}
    if (n > energiaRim) {n = energiaRim;}
    energiaRim -= n;
    mappa[posizioneX][1] = 10 + n - mappa[posizioneX][1];
    mappa[posizioneX][1] = mappa[posizioneX][1] == 10 ? 0 : mappa[posizioneX][1];
    return *this;
}
