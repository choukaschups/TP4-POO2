#include "ActionCreerGraphe.h"

#include <utility>
#include <fstream>
#include <iostream>
#include <map>

void ActionCreerGraphe::executer(vector<Requete *> * requetes) {
    map<string, map<string, int>> graphe;

    for (auto requete: *requetes) {
        string referent = requete->getReferant().url;

        auto cibles = &graphe[referent];

        string cible = requete->getRequeteHttp().url;
        (*cibles)[cible]++;
    }

    ofstream os(nomFichier);

    if (!os.is_open()) {
        cout << "Erreur lors de la création du fichier" << endl;

        return;
    }

    int i = 0;
    map<string, int> numeros;
    for (auto cible : graphe) {
        numeros.insert(make_pair(cible.first, i++));
    }

    os << "diagraph {" << endl;
    for (const auto& referent : graphe) {
        os << "node" << numeros[referent.first] << " " << "[label=\"" << referent.first << "\"];" << endl;
    }

    for (const auto& referent : graphe) {
        for (const auto& cible : referent.second) {
            os << "node" << numeros[referent.first] << " -> " << "node" << numeros[cible.first] << " [label=\"" << cible.second << "\"];" << endl;
        }
    }

    os << "}";
}

ActionCreerGraphe::ActionCreerGraphe(std::string nomFichier) : nomFichier(std::move(nomFichier)) {

}
