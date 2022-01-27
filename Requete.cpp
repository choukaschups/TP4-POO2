#include <utility>

#include "Requete.h"

const std::string &Requete::getIp() const {
    return ip;
}

const Utilisateur &Requete::getUtilisateur() const {
    return utilisateur;
}

const Date &Requete::getDate() const {
    return date;
}

const HTTP &Requete::getRequeteHttp() const {
    return requeteHttp;
}

int Requete::getReponse() const {
    return reponse;
}

int Requete::getTaille() const {
    return taille;
}

const Referant &Requete::getReferant() const {
    return referant;
}

const std::string &Requete::getIdentificationClient() const {
    return identificationClient;
}

Requete::Requete(std::string ip, Utilisateur utilisateur, const Date &date, HTTP requeteHttp,
                 int reponse, int taille, Referant referant, std::string identificationClient) :
        ip(std::move(ip)),
        utilisateur(std::move(utilisateur)),
        date(date),
        requeteHttp(std::move(requeteHttp)),
        reponse(reponse),
        taille(taille),
        referant(std::move(referant)),
        identificationClient(std::move(identificationClient)) {}
