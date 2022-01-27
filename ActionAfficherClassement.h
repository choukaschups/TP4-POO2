#ifndef TP4_POO2_ACTIONAFFICHERCLASSEMENT_H
#define TP4_POO2_ACTIONAFFICHERCLASSEMENT_H

#include "Action.h"

using namespace std;

class ActionAfficherClassement : public Action {

public:
    void executer(vector<Requete *> *) override;

    ActionAfficherClassement();

private:
    static bool cmp(pair<string, int> &p1, pair<string, int> &p2);
};


#endif //TP4_POO2_ACTIONAFFICHERCLASSEMENT_H
