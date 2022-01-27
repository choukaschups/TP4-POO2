#include "Lecteur.h"
#include "Requete.h"

#include <iostream>
#include <string>
#include <regex>
#include <vector>

using namespace std;

vector<Requete *> *Lecteur::lire() {
    auto requetes = new vector<Requete *>;

    string ligne;

    // ?:(?:http:\/\/((?:intranet-)?if\.insa-lyon.fr((?:\/[a-zA-Z0-9]*)+(?:\.([a-z]+))?[^ ]*)|.+))|-
    // TODO : Enlever la partie locale d'un referent si il y a
    // TODO : améliorer le match d'une cible

    // ((?:\/[a-zA-Z0-9-]+)+(?=\/)?(?:\.([a-z]+))?)[^ ]* Censé enlever le trailing slash mais ne marche pas sur mac

    // TODO Gérer le cas de la chaîne vide ou de la racine (/)

    regex reg(R"lit(^([0-9]{3}(?:.[0-9]{1,3}){3}) (-) (-) \[[0-9]{2}\/[A-Z][a-z]{2,3}\/[0-9]{4}:([0-9]{2}):[0-9]{2}:[0-9]{2} \+[0-9]{4}\] "([A-Z]{3,}) ((?:\/[a-zA-Z0-9-]*)+(?=\/)?(?:\.([a-z]+))?)[^ ]* HTTP\/1\.[01]" ([0-9]{3}|-) ([0-9]{1,}|-) "(.+)" (".+")$)lit");
    smatch match;

    int a = 1;

    while (!fichierLog->eof()) {
        getline(*fichierLog, ligne, '\n');
        regex_search(ligne, match, reg);

        string ip = match[1];

        Utilisateur utilisateur;
        utilisateur.nomVisiteur = match[2];
        utilisateur.nomUtilisateur = match[3];

        Date date;
        date.heure = atoi(match[4].str().c_str());

        HTTP requeteHttp;
        requeteHttp.action = match[5];
        requeteHttp.url = match[6];

        string extensionRessource = match[7];

        if (extensionRessource.empty()) {
            // Si le chemin ne point vers aucune ressource, c'est qu'il point implicitement vers la page index.html du répertoire
            requeteHttp.url += "/index.html";
            extensionRessource = "html";
        }

        TypeRessource typeRessource;

        if (extensionRessource == "jpg" || extensionRessource == "png" || extensionRessource == "gif" ||
            extensionRessource == "bmp" || extensionRessource == "ico") {
            typeRessource = IMAGE;
        } else if (extensionRessource == "css") {
            typeRessource = STYLE;
        } else if (extensionRessource == "js") {
            typeRessource = SCRIPT_JS;
        } else if (extensionRessource == "php") {
            typeRessource = SCRIPT_PHP;
        } else if (extensionRessource == "html") {
            typeRessource = PAGE;
        } else {
            typeRessource = NON_DEFINI;
        }

        requeteHttp.typeRessource = typeRessource;

        int reponse = atoi(match[8].str().c_str());

        int taille = atoi(match[9].str().c_str());

        Referant referant;
        referant.url = match[10];
        referant.ressource = match[11];

        string identificationClient = match[12];

        /*cout << "IP : " << ip << endl;

        cout << "Utilisateur :" << endl;
        cout << utilisateur.nomVisiteur << endl;
        cout << utilisateur.nomUtilisateur << endl;

        cout << "Date :" << endl;
        cout << date.heure << endl;

        cout << "Requête :" << endl;
        cout << requeteHttp.action << endl;
        cout << requeteHttp.url << endl;
        cout << requeteHttp.typeRessource << endl;

        cout << "Réponse : " << reponse << endl;

        cout << "Taille : " << taille << endl;

        cout << "Référant :" << endl;
        cout << referant.url << endl;
        cout << referant.ressource << endl;

        cout << "Identification client : " << identificationClient << endl;*/

        cout << a++ << endl;

        auto requete = new Requete(ip, utilisateur, date, requeteHttp, reponse, taille, referant, identificationClient);
        requetes->push_back(requete);
    }

    return requetes;
}

Lecteur::Lecteur(ifstream *fichierLog) : fichierLog(fichierLog) {}
