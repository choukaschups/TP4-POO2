#ifndef TP4_POO2_CRITEREHEURE_H
#define TP4_POO2_CRITEREHEURE_H


#include "Critere.h"

class CritereHeure : public Critere {

public:
    bool estValide(const Requete *requete) override;

    CritereHeure(int heure);

private:
    int heure;
};


#endif //TP4_POO2_CRITEREHEURE_H
