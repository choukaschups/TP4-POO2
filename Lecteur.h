#ifndef TP4_POO2_LECTEUR_H
#define TP4_POO2_LECTEUR_H

#include <fstream>
#include "Requete.h"

using namespace std;

class Lecteur {

public:
    explicit Lecteur(ifstream *fichierLog);

public:
    vector<Requete *> *lire();

private:
    ifstream *fichierLog;
};


#endif //TP4_POO2_LECTEUR_H
