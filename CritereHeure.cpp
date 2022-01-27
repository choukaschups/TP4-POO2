#include "CritereHeure.h"

using namespace std;

bool CritereHeure::estValide(const Requete *requete) {
    return requete->getDate().heure == heure;
}

CritereHeure::CritereHeure(int heure) : heure(heure) {}
