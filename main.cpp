/**************************************************************
main.cpp ------ Hector HAMELIN, Enzo TSANGOUAEKA - 20/10/2024
**************************************************************/

#include <iostream>  // Gestion des entrées, sorties
#include <cstdlib>   // Aléatoire
#include <string>    // Inclusion de string
#include <vector>    // Genstion des tableaux
#include "event.h"   // Utilisation des guillemets pour inclure le fichier local

using namespace std; // Pour ne pas avec à écrire std::

// Routine du programme
void loop();
void prompt();
void addSpecimen(int _nbrOfSpecimen);
void killSpecimen(int _ID);
void showSpecimen(int _ID);
void removeSpecimenIdTable(unsigned long long int _ID);
void killRangSpecimen(int _nbrOfSpecimen);
void retry();

// Structure des Specimens
struct SPECIMEN {
    int age;
    unsigned long long int ID;
    bool IsAlive = true;
};

// Variable Global
unsigned long long int nmbrOfSpecimen(0), lastIdGenerate(0);
int reproductionRate(100); // Stat de la troupe
vector<SPECIMEN> tableOfSpecimen;  // Tableau dynamique contenant les tous les SPECIMENs et leurs stats
vector<unsigned long long int> idOfSpecimenAlive; // Tableau dynamique contenant les ID des Specimens en vie

// Vérification de la condition de validité de la boucle
bool IsAlive() {
    if(nmbrOfSpecimen > 0) {
        return true;
    }
    return false;
}

// Supprime un id d'un Speciem du tableau idOfSpecimenAlive
void removeSpecimenIdTable(unsigned long long int _ID) {
    for (auto  it = idOfSpecimenAlive.begin(); it != idOfSpecimenAlive.end(); ++it) {
        if (idOfSpecimenAlive[*it] == _ID) {
            idOfSpecimenAlive.erase(it);  // Supprime l'élément trouvé
            // cout << "Specimen avec ID " << _ID << " a ete supprime du tableau : idOfSpecimenAlive." << endl;
            return;
        }
    }
    // cerr << "Erreur : Spécimen avec ID " << _ID << " n'a pas été trouvé." << endl;
}

// Créé le nombre de Specimen demander
void addSpecimen(int _nbrOfSpecimen) {
    unsigned long long int _ID(lastIdGenerate);
    if(_nbrOfSpecimen > 1) {
        for (int i = 0; i < _nbrOfSpecimen; i++) {
            SPECIMEN newSpecimen;
            newSpecimen.ID = _ID++;
            tableOfSpecimen.push_back(newSpecimen);  // Ajoute dynamiquement le spécimen
            idOfSpecimenAlive.push_back(newSpecimen.ID); // Ajoute de l'ID dans le tableau
            nmbrOfSpecimen++;
        }
        lastIdGenerate += _nbrOfSpecimen;
        // cout << "Les " << _nbrOfSpecimen << " specimens ont ete crees." << endl;
    }
    else if (_nbrOfSpecimen == 1) {
        SPECIMEN newSpecimen;
        newSpecimen.ID = _ID++;
        tableOfSpecimen.push_back(newSpecimen);  // Ajoute dynamiquement le spécimen
        idOfSpecimenAlive.push_back(newSpecimen.ID); // Ajoute de l'ID dans le tableau
        nmbrOfSpecimen++;
        lastIdGenerate += _nbrOfSpecimen;
        // cout << "Un specimen a ete crees." << endl;
    }
    else {
        cout << "Erreur creation impossible." << endl;
    }
}

// Fonction de destrucation de Spéciment via son ID
void killSpecimen(int _ID) {
    for (unsigned long long int i = 0; i < lastIdGenerate; i++) {
            if (tableOfSpecimen[i].ID == _ID) {
                tableOfSpecimen[i].IsAlive = false;
                cout << "Trouve" << endl;
                nmbrOfSpecimen--;
                removeSpecimenIdTable(i);
                return;
            }
    }
    cout << "Pas trouve" << endl;
}

// Permet de tué des spécimens aléatoirement
void killRangSpecimen(int _nbrOfSpecimen) {
    if (_nbrOfSpecimen < nmbrOfSpecimen) {
        int specimentIdToKill(0);
        for (int i = 0; i < _nbrOfSpecimen; i++) {
            specimentIdToKill = rand() % nmbrOfSpecimen + 1;
            killSpecimen(specimentIdToKill);
            // cout << "La specimen a l'ID : " << specimentIdToKill << ", a bien ete detruit." << endl;
        }
        cout << "Les " << _nbrOfSpecimen << " specimens ont ete supprime." << endl;
    }
    else {

    }
}

// Permet d'obtenir des informations sur un spéciment via son ID
void showSpecimen(int _ID) {
    cout << "INFO : ID = " << tableOfSpecimen[_ID].ID << ", STATE = " << (tableOfSpecimen[_ID].IsAlive ? "Alive" : "Dead") << endl;
}

// Routine gérant les commandes / entrees utilisateur
void prompt() {
    bool _isntGoodAnswer = true;
    string answer;
    while (_isntGoodAnswer) {
        int i(0);
        cout << "\n" << nmbrOfSpecimen << " Specimen(s) en vie, que souhaitez-vous faire ?\n" << endl;
        cout << ++i << ". Creer des specimens (a) " << endl;
        cout << ++i << ". Detruire des specimens (b)" << endl;
        // cout << ++i << ". Nourrire des spécimens" << endl;
        // cout << ++i << ". Interagir" << endl;
        // cout << ++i << ". Ignorer" << endl;
        cout << "\nVotre choix : ";
        cin >> answer;
        cout << "\n" << endl;
        // Ajouter ici le systeme de gestion de
        if (answer == "a") {
            addSpecimen(1);
            cout << "[ Ajout d'un specimen ]" << endl;
            _isntGoodAnswer = false;
        }
        else if (answer == "b") {
            killSpecimen(lastIdGenerate-1);
            cout << "[ Suppresion d'un specimen ]" << endl;
            _isntGoodAnswer = false;
        }
    }
}

// Permet de remmetre toutes les variables à leurs valeur initial afin de recommancer une partie
void retry() {
    bool _isntGoodAnswer = true;
    string _answer;
    while (_isntGoodAnswer) {
        cout << "Voulez vous recommencer une partie (o/n) ?";
        cin >> _answer;
        if (_answer == "o") {
            // remettre toutes les variables par defaut
            cout << "Recommancons une partie" << endl;
            _isntGoodAnswer = false;
            return;
        }
        else if (_answer == "n") {
            cout << "Eu revoir" << endl;
            _isntGoodAnswer = false;
            return;
        }
        else {
            cout << "Mauvaise entree" << endl;
        }
    }
}

// Fonction du jeu
void loop() {
    /* Debut du jeu
     L'objectif du debut de jeu est de faire des actions afin d'engendrer la création de specimen
     */

    // Middle Game
    while (IsAlive()) {
        prompt(); // Demandes les actions à faire par l'utilisateur par jour
        event(nmbrOfSpecimen); // Evenement de nuit
    }
}

int main() {
    // Set up
    system("cls");  // Pour nettoyer le terminal
    srand(time(0)); // Pour l'aléatoir

    // Message de bienvenu sur le jeu
    cout << "\n$$$$$$$$\\                  $$\\             $$\\     $$\\                     \n" ;
    cout << "$$  _____|                 $$ |            $$ |    \\__|                    \n" ;
    cout << "$$ |  $$\\    $$\\  $$$$$$\\  $$ |$$\\   $$\\ $$$$$$\\   $$\\  $$$$$$\\  $$$$$$$\\  \n" ;
    cout << "$$$$$\\\\$$\\  $$  |$$  __$$\\ $$ |$$ |  $$ |\\_$$  _|  $$ |$$  __$$\\ $$  __$$\\ \n" ;
    cout << "$$  __|\\$$\\$$  / $$ /  $$ |$$ |$$ |  $$ |  $$ |    $$ |$$ /  $$ |$$ |  $$ |\n" ;
    cout << "$$ |    \\$$$  /  $$ |  $$ |$$ |$$ |  $$ |  $$ |$$\\ $$ |$$ |  $$ |$$ |  $$ |\n" ;
    cout << "$$$$$$$$\\\\$  /   \\$$$$$$  |$$ |\\$$$$$$  |  \\$$$$  |$$ |\\$$$$$$  |$$ |  $$ |\n" ;
    cout << "\\________|\\_/     \\______/ \\__| \\______/    \\____/ \\__| \\______/ \\__|  \\__|\n\n" ;

    addSpecimen(10); // Ajout de spécimen pour ne pas faire échouer la boucle loop()
    loop(); // Fonction du jeu
    retry(); // En cas de mort il est possible de relancer le jeu
    system("pause");
    return 0;
}