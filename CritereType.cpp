#include "CritereType.h"

using namespace std;

CritereType::CritereType() = default;

bool CritereType::estValide(const Requete *requete) {
    TypeRessource typeRessource = requete->getRequeteHttp().typeRessource;

    return typeRessource != IMAGE && typeRessource != STYLE && typeRessource != SCRIPT_JS;
}
