#ifndef TP4_POO2_ACTION_H
#define TP4_POO2_ACTION_H

#include <vector>

#include "Requete.h"

using namespace std;

class Action {
public:
    virtual void executer(vector<Requete *> *) = 0;

    virtual ~Action() = default;
};


#endif //TP4_POO2_ACTION_H
