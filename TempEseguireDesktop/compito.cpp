#include "compito.h"
int record = 0;

void SpaceAsteroids::pulisciSchermo() {
    for(int r=0;r<righe;r++){
        for(int c=0;c<colonne;c++){
            if(r!=righe-1){
                schermo[r * colonne + c] = ' ';
                continue;
            }
            if(c!=colonne/2){
                schermo[r * colonne + c] = '_';
            } else {
                schermo[r * colonne + c] = 'A';
            }
        }
    }
    punteggio = 0; //aggiungi
    avanzato = true; //aggiungi
    avanzatoLaser = true; //aggiungi
    reset = false; //aggiungi
    energia = energiaStart;
}

SpaceAsteroids::SpaceAsteroids(const int altezza,const int larghezza, int energia_massima) {
    //controllo che siano corretti gli input
    righe = (altezza<3 || altezza>7) ? 7 : altezza;
    colonne = (larghezza<3 || larghezza>9 || larghezza%2==0) ? 9 : larghezza;
    energiaStart = energia = (energia_massima<1) ? 5 : energia_massima;
    punteggio = 0;
    schermo = new char[righe*colonne];
    energiaRaggi = new int[righe-1]; //aggiungi
    for(int i=0;i<righe-1;i++){ //inizializzo energiaRaggi[]
        energiaRaggi[i] = 0;
    }

    pulisciSchermo();
}

ostream& operator<<(ostream& os, const SpaceAsteroids& sp1){
    os<<"Punteggio: "<<sp1.punteggio<<endl;
    os<<"Record: "<<record<<endl;
    os<<"Energia: "<<sp1.energia<<endl;

    for(int i=0;i<sp1.colonne;i++){
        os<<"_";
    }
    os<<endl;
    for(int r=0;r<sp1.righe;r++){
        for(int c=0;c<sp1.colonne;c++){
            os<<sp1.schermo[r*sp1.colonne + c];
        }
        os<<endl;
    }
    return os;
}

bool SpaceAsteroids::colloca_asteroide(int col) {
    //argomento sbagliato
    if(col>colonne || col<1 || schermo[col-1] == 'A'){
        return false;
    }
    //argomento corretto
    if(schermo[col-1] == ' '){
        schermo[col-1] = 'X';
        return true;
    }
    return false;
}

void SpaceAsteroids::avanza_asteroidi() {
    for(int r=righe-1;r>=0;r--){
        for(int c=colonne-1;c>=0;c--){
            if(r==righe-1){
                if(schermo[r*colonne+c]=='X'){
                    schermo[r*colonne+c]='_'; //sostituisci ' ' con '_'
                }
                continue;
            }
            if(schermo[r*colonne+c]=='X'){
                schermo[r*colonne+c]=' ';
                if(schermo[(r+1)*colonne+c]!='A'){
                    if(schermo[(r+1)*colonne+c]=='|'){ //se incontro un raggio avanzando l'asteroide
                        energiaRaggi[r+1]--;
                        if(energiaRaggi[r+1]==0) schermo[(r+1)*colonne+c] = ' '; //se l'energia del raggio è 0, allora lo elimino
                        punteggio++;
                        if(punteggio>record){
                            record=punteggio;
                        }
                        continue;
                    }
                    schermo[(r+1)*colonne+c]='X'; //se non incontro niente
                } else {
                    //pulisciSchermo();
                    //return;
                    reset = true;
                }
            }
        }
    }
    if(reset){
        pulisciSchermo();
        return;
    }
    punteggio++;
    if(punteggio>record){
        record=punteggio;
    }
}

void SpaceAsteroids::avanza() {
    int c,counter=0;
    //sposto gli elementi del vettore salva energiaRaggi {elemento piu' lontano,...,elemento piu' vicino}
    for(int i=0;i<righe-1;i++){
        if(energiaRaggi[i]==0) continue;
        if(i==0){
            energiaRaggi[i] = 0;
            continue;
        }
        int tmp = energiaRaggi[i-1]; //in caso non funzioni sostituisci con 0 visto che il primo elemento sarà sempre 0
        energiaRaggi[i-1] = energiaRaggi[i];
        energiaRaggi[i] = tmp;
    }


    for(int r=0;r<righe-1;r++) {
        for (int j = 0; j < colonne - 1; j++) {
            if (r == 0) {
                if (schermo[j] == '|') {
                    schermo[j] = ' ';
                    counter++;
                    continue;
                    //ho già azzerato l'energia
                }
            }
            if (schermo[r * colonne + j] == '|') {
                if (schermo[(r - 1) * colonne + j] != 'X') {
                    schermo[r * colonne + j] = ' ';
                    schermo[(r - 1) * colonne + j] = '|';
                    //counter++;
                    //continue;
                } else {
                    schermo[r * colonne + j] = ' ';
                    schermo[(r - 1) * colonne + j] = '|';
                    energiaRaggi[r-1]--;
                    if(energiaRaggi[r-1]==0) schermo[(r - 1) * colonne + j] = ' '; //se finita energia elimino il raggio
                    punteggio++;
                    //counter++;
                }
                counter++;
            }
        }
    }
    if (punteggio > record) record = punteggio;
    if(counter>0) energia++;
    avanza_asteroidi();
    avanzato = true;
    avanzatoLaser = true;//modifica
}

SpaceAsteroids& SpaceAsteroids::operator<<=(int n) {
    if(!avanzato) return *this;
    int c=0;
    while(schermo[(righe-1)*colonne+c]!='A') c++;
    if(c==0) return *this;
    for(int j=(c-1);j>=c-n || j==0;j--){//DA QUI
        if(schermo[(righe-1)*colonne+j]=='X'){
            pulisciSchermo();
            punteggio = 0;
            return *this;
        }
    }//A QUI
    if(c-n<0) n = c;
    //if(schermo[(righe-1)*colonne+(c-n)]!='X'){//CANCELLA
    schermo[(righe-1)*colonne+(c-n)] = 'A';// -
    schermo[(righe-1)*colonne+(c)] = '_';
    /*} else { //CANCELLA
        pulisciSchermo();
        punteggio = 0;
        return *this;
    }*/
    avanzato = false;
    return *this;
}

SpaceAsteroids& SpaceAsteroids::operator>>=(int n) {
    if(!avanzato) return *this;
    int c=0;
    while(schermo[(righe-1)*colonne+c]!='A') c++;
    if(c==(colonne-1)) return *this;
    for(int j=(c+1);j<=c+n || j==(colonne-1);j++){
        if(schermo[(righe-1)*colonne+j]=='X'){
            pulisciSchermo();
            punteggio = 0;
            return *this;
        }
    }
    if(c+n>(colonne-1)) n = colonne-1-c;
    schermo[(righe-1)*colonne+(c+n)] = 'A';
    schermo[(righe-1)*colonne+(c)] = '_';

    avanzato = false;
    return *this;
}

SpaceAsteroids& SpaceAsteroids::operator|=(int n) {
    if (!avanzatoLaser || n <= 0 || energia <= 0)
        return *this;

    if(n>energia)
        n = energia;
    energiaRaggi[righe-2] = n;
    energia-=n;
    int c;
    for(c=0;schermo[(righe-1)*colonne+c]!='A';c++); //individuo la colonna della navicella
    if(schermo[(righe-2)*colonne+c]!='X'){
        schermo[(righe-2)*colonne+c]='|';
    } else {
        schermo[(righe-2)*colonne+c]='|';
        energiaRaggi[righe-2]--;
        punteggio++;
        if(punteggio>record) record = punteggio;
        //SE IL RAGGIO NON HA PIU' ENERGIA ELIMINO IL RAGGIO
        if(energiaRaggi[righe-2]==0){
            schermo[(righe-2)*colonne+c]=' ';
        }
    }
    avanzatoLaser = false; //aggiungi
    return *this;
}
// fine file