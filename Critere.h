#ifndef TP4_POO2_CRITERE_H
#define TP4_POO2_CRITERE_H


#include "Requete.h"

class Critere {
public:
    virtual bool estValide(const Requete *requete) = 0;

    virtual ~Critere() = default;
};


#endif //TP4_POO2_CRITERE_H
