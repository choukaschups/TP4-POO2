#ifndef TP4_POO2_CRITERETYPE_H
#define TP4_POO2_CRITERETYPE_H


#include "Critere.h"

class CritereType : public Critere {
public:
    CritereType();

    bool estValide(const Requete *requete) override;
};


#endif //TP4_POO2_CRITERETYPE_H
