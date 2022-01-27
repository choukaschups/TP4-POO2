#include <iostream>
#include <vector>
#include <map>

#include "Action.h"
#include "ActionAfficherClassement.h"
#include "ActionCreerGraphe.h"
#include "Lecteur.h"
#include "Critere.h"
#include "CritereType.h"
#include "CritereHeure.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc == 1) {
        cout << "Erreur : Nombre d'arguments insuffisant" << endl;

        return 1;
    }

    auto *fichierLog = new ifstream(
            argv[argc - 1]
    ); // Le nom du fichier est le dernier argument passé à la ligne de commande

    if (!fichierLog->is_open()) {
        cout << "Erreur : Nom de fichier invalide" << endl;

        return 1;
    }

    auto *criteres = new vector<Critere *>;
    auto actions = map<string, Action *>();

    for (int i = 1; i < argc - 1; ++i) {
        string argument = argv[i];
        //cout << argument << endl;

        if (argument.size() == 1 || argument[0] != '-' || argument.size() > 2) {
            cout << "Erreur : Option mal formatée" << endl;

            return 1;
        }

        char option = argument[1];

        switch (option) {
            case 'e': {
                criteres->push_back(new CritereType());

                break;
            }

            case 'g': {
                if (i == argc - 2) {
                    cout << "Erreur : Il faut spécifier le nom du fichier graphe à créer" << endl;

                    return 1;
                }

                string nomFichierGraphe = argv[i + 1];

                cout << nomFichierGraphe << endl;

                actions.insert(make_pair("graphe", new ActionCreerGraphe(nomFichierGraphe)));

                ++i;

                break;
            }

            case 't': {
                if (i == argc - 2) {
                    cout << "Erreur : Il faut spécifier l'heure" << endl;

                    return 1;
                } // TODO Marchera pas

                int heure = atoi(argv[++i]);

                criteres->push_back(new CritereHeure(heure));

                break;
            }

            default: {
                cout << "Erreur : Option invalide" << endl;

                break;
            }
        }
    }

    if (actions.find("graphe") == actions.end()) {
        actions.insert(make_pair("top", new ActionAfficherClassement()));
    }

    auto *lecteur = new Lecteur(fichierLog);
    auto *requetes = lecteur->lire();

    for (auto it = requetes->begin(); it != requetes->end(); it++) {
        for (auto critere: *criteres) {
            if (!critere->estValide(*it)) {
                requetes->erase(it--);
            }
        }
    }

    for (auto action : actions) {
        action.second->executer(requetes);
    }

    return 0;
}
