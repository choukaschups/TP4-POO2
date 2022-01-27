#include <iostream>
#include <vector>
#include <map>

#include "ActionAfficherClassement.h"

using namespace std;

bool ActionAfficherClassement::cmp(pair<string, int> &p1, pair<string, int> &p2) {
    return p1.second > p2.second;
}

void ActionAfficherClassement::executer(vector<Requete *> *requetes) {
    map<string, pair<map<string, int>, int>> graphe;

    for (auto requete: *requetes) {
        string cible = requete->getRequeteHttp().url;

        auto paire = &graphe[cible];

        string referent = requete->getReferant().ressource;
        paire->first[referent]++;

        paire->second++;
    }

    auto requetesTriees = new vector<pair<string, int>>;
    for (auto cible: graphe) {
        requetesTriees->push_back(make_pair(cible.first, cible.second.second));
    }

    sort(requetesTriees->begin(), requetesTriees->end(), cmp);

    for (size_t i = 1; i <= min((unsigned long) 10, requetesTriees->size()); ++i) {
        cout << i
             << " : "
             << (*requetesTriees)[i - 1].first
             << " référencé "
             << (*requetesTriees)[i - 1].second
             << " fois"
             << endl;
    }
}

ActionAfficherClassement::ActionAfficherClassement() {

}
