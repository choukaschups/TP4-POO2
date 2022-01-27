#ifndef TP4_POO2_ACTIONCREERGRAPHE_H
#define TP4_POO2_ACTIONCREERGRAPHE_H

#include "Action.h"

class ActionCreerGraphe : public Action {

public:
    explicit ActionCreerGraphe(std::string nomFichier);

    void executer(vector<Requete *> *) override;

private:
    std::string nomFichier;
};


#endif //TP4_POO2_ACTIONCREERGRAPHE_H
