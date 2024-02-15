#include "compito.h"
int punteggioMaxGlob = 0;

SpaceAsteroids::SpaceAsteroids(const int naltezza, const int nlarghezza, const int nenergiaMax) {
    if (naltezza < 8 && naltezza > 2) {
        altezza = naltezza;
    }
    if (nlarghezza < 10 && nlarghezza > 2 && nlarghezza % 2 != 0) {
        larghezza = nlarghezza;
    }
    if (nenergiaMax > 0) {
        energiaMax = nenergiaMax;
        energiaRim = energiaMax;
    }
    posizioneX = larghezza / 2; //la posizione della navicinella è al centro
    //inizializzo la mappa con gli 0
    mappa = new int *[larghezza];
    for (int i = 0; i < larghezza; i++) {
        mappa[i] = new int[altezza];
        for (int j = 0; j < altezza; j++) {
            mappa[i][j] = 0;
        }
    }
    //adesso mappa è un puntatore ad una array di puntatori, si comporta quindi come una matrice[larghezza][altezza]
}
bool SpaceAsteroids::colloca_asteroide(int colonna) { //colonna è indicizzata a partire da 1 quindi rimuovi 1!!
    if (colonna < 1 || colonna > larghezza || mappa[colonna - 1][altezza - 1] != 0) { return false; }
    mappa[colonna - 1][altezza - 1] = 1;
    return true;
}
void SpaceAsteroids::avanza_asteroidi() {

}
void SpaceAsteroids::avanza() {
    //faccio avanzare i laser di due e poi lo riporto indietro nella avanza_asteroidi
    

    if (energiaRim < energiaMax) { energiaRim++; }
    possoSpostare = true;
    possoSparare = true;
    avanza_asteroidi();
}




/*
SpaceAsteroids::SpaceAsteroids(const int naltezza, const int nlarghezza, const int nenergiaMax) {
    if (naltezza < 8 && naltezza > 2) {
        altezza = naltezza;
    }
    if (nlarghezza < 10 && nlarghezza > 2 && nlarghezza % 2 != 0) {
        larghezza = nlarghezza;
    }
    if (nenergiaMax > 0) {
        energiaMax = nenergiaMax;
        energiaRim = energiaMax;
    }
    posizioneX = larghezza / 2; //la posizione della navicinella è al centro
    //inizializzo la mappa con gli 0
    mappa = new int *[larghezza];
    for (int i = 0; i < larghezza; i++) {
        mappa[i] = new int[altezza];
        for (int j = 0; j < altezza; j++) {
            mappa[i][j] = 0;
        }
    }
    //adesso mappa è un puntatore ad una array di puntatori, si comporta quindi come una matrice[larghezza][altezza]
}

bool SpaceAsteroids::colloca_asteroide(int colonna) { //colonna è indicizzata a partire da 1 quindi rimuovi 1!!
    if (colonna < 1 || colonna > larghezza || mappa[colonna - 1][altezza - 1] != 0) { return false; }
    mappa[colonna - 1][altezza - 1] = 1;
    return true;
}

void SpaceAsteroids::avanza() {
    possoSpostare = true;
    possoSparare = true;
    //adesso faccio avanzare i laser
    for (int j = altezza - 1; j > 0; j--) { //mappa[i][j]
        for (int i = 0; i < larghezza; i++) {
            if (mappa[i][j] > 10) { //c'è un laser
                if (j == altezza - 1) { mappa[i][j] = 0;}else {
                    if (mappa[i][j+1] == 1) { punteggio++; }//c'è un asteroide quindi alzo il punteggio
                    mappa[i][j+1] = mappa[i][j] - mappa[i][j+1]; //sposto il laser su
                    mappa[i][j] = 0; //cancello il laser spostato
                    if (mappa[i][j+1] == 10) {mappa[i][j+1] = 0;} //il laser svanisce
                    if (j < altezza - 2 && mappa[i][j+1] > 10) { //altrimenti vado out of bound
                        if (mappa[i][j+2] == 1) {punteggio++;}//c'è un asteroide quindi alzo il punteggio
                        mappa[i][j+1] -= mappa[i][j+2];
                        if (mappa[i][j+1] == 10) {mappa[i][j+2] = 0;} //il laser svanisce
                    }
                }
            }
        }
    }
    avanza_asteroidi();
}

void SpaceAsteroids::avanza_asteroidi() {
    if (mappa[posizioneX][1] == 1)
    { //un asteroide colpisce la nave
        gameOver();
        return;
    }
    //adesso avanzo gli asteroidi senza controllare i laser perché ho già fatto
    for (int i = 0; i < larghezza; i++)
    {
        for (int j = 0; j < altezza - 1; j++)
        { //ultima riga no
            if (mappa[i][j] == 10) {mappa[i][j] = 0;} //saeeeeeeeeeeeeeeee
            if (j == 0 && i != posizioneX) { mappa[i][j] = 0; } //elimino gli asteroidi in basso, facendo attenzione alla nave
            if (mappa[i][j+1] == 1) {
                mappa[i][j] = mappa[i][j+1]; //faccio scendere l'asteroide
                mappa[i][j+1] = 0; //elimino l'asteroide spostato
            }
        }
    }
    if (energiaRim < energiaMax) {
        energiaRim++;}
    punteggio++;

    if (punteggio > punteggioMax) {
        punteggioMax = punteggio; }
    if (punteggio > punteggioMaxGlob) {
        punteggioMaxGlob = punteggio; }
}

ostream &operator<<(ostream &os, const SpaceAsteroids &questo) {
    os << "Punteggio: " << questo.punteggio << endl;
    os << "Record: " << punteggioMaxGlob << endl;
    os << "Energia: " << questo.energiaRim << '\n' << endl;
    for (int i = -1; i < questo.altezza; i++) { //mappa[j][i]
        for (int j = 0; j < questo.larghezza; j++) {
            //faccio la riga di _____
            if (i == -1) {
                os << "_";
            }
            //mi occupo della ultima riga ___A____
            else if (questo.altezza - i - 1 == 0)
            {
                if (j == questo.posizioneX){
                    os << "A";
                } else if (questo.mappa[j][questo.altezza - i - 1] == 0){
                    os << "_";
                } else if (questo.mappa[j][questo.altezza - i - 1] == 1) { os << "X"; }
            } else if (questo.mappa[j][questo.altezza - i - 1] == 0)
            {
                os << " ";
            } else if (questo.mappa[j][questo.altezza - i - 1] == 1)
            {
                os << "X";
            }
            else if (questo.mappa[j][questo.altezza - i - 1] > 10)
            {
                os << "|";
            }
            //os << "\t";
        }
        os << endl;
    }
    os << endl;
    return os;
}

SpaceAsteroids::~SpaceAsteroids() {
    for (int i = 0; i < larghezza; i++) {
        delete[] mappa[i];
    }
}


SpaceAsteroids &SpaceAsteroids::operator<<=(int n) {
    if (!possoSpostare) { return *this;} if (posizioneX - n < 0 ) {n = posizioneX; }
    while (n>0 && posizioneX > 0) {
        if (mappa[posizioneX - 1][0] == 1) {
            gameOver();
            return *this;
        }
        n--;
        posizioneX--;
    } possoSpostare = false;
    return *this;
}

void SpaceAsteroids::gameOver() {
    punteggio = 0;
    energiaRim = energiaMax;
    for (int i = 0; i < larghezza; i++) {
        for (int j = 0; j < altezza; j++) {
            mappa[i][j] = 0;
        }
    } posizioneX = larghezza/2, mappa[posizioneX][0] = -1, possoSpostare = true, possoSparare = true;
}

SpaceAsteroids &SpaceAsteroids::operator>>=(int n) {
    if (!possoSpostare) { return *this;} if (n + posizioneX >= larghezza) {n = larghezza - posizioneX -1; }
    while (n>0 && posizioneX < larghezza) {
        if (mappa[posizioneX + 1][0] == 1) {
            gameOver();
            return *this;
        }
        n--;
        posizioneX++;
    } possoSpostare = false;
    return *this;
}

SpaceAsteroids &SpaceAsteroids::operator|=(int n) {
    if (!possoSparare) { return *this;}
    if (energiaRim == 0) { return *this;}
    if (n>energiaRim) { n = energiaRim;}
    energiaRim -= n;
    if (mappa[posizioneX][1] == 1) {
        if (n == 1) {
            mappa[posizioneX][1] = 0;
        }
        else {
            n--;
            mappa[posizioneX][1] = 10 + n; //il 10 mi serve poi per differenziarlo meglio da asteroidi e spazi vuoti nella cout
        }
    }
    else {
        mappa[posizioneX][1] = 10 + n;
    }
    return *this;
}

// fine file
 */