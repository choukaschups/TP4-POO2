#ifndef TP4_POO2_REQUETE_H
#define TP4_POO2_REQUETE_H

#include <string>

using namespace std;

struct Date {
    int heure;
};

typedef struct Date Date;

struct Utilisateur {
    string nomVisiteur;
    string nomUtilisateur;
};

typedef struct Utilisateur Utilisateur;

enum TypeRessource {
    IMAGE,
    STYLE,
    SCRIPT_JS,
    SCRIPT_PHP,
    PAGE,
    NON_DEFINI
};

struct HTTP {
    string action;
    string url;
    TypeRessource typeRessource;
};

typedef struct HTTP HTTP;

struct Referant {
    string url;
    string ressource;
};

typedef struct Referant Referant;

class Requete {

public:
    const std::string &getIp() const;

    const Utilisateur &getUtilisateur() const;

    const Date &getDate() const;

    const HTTP &getRequeteHttp() const;

    int getReponse() const;

    int getTaille() const;

    const Referant &getReferant() const;

    const std::string &getIdentificationClient() const;

    Requete(std::string ip, Utilisateur utilisateur, const Date &date, HTTP requeteHttp,
            int reponse, int taille, Referant referant, std::string identificationClient);

private:
    std::string ip;
    Utilisateur utilisateur;
    Date date;
    HTTP requeteHttp;
    int reponse;
    int taille;
    Referant referant;
    std::string identificationClient;
};


#endif //TP4_POO2_REQUETE_H
