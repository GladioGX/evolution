/**************************************************************
main.cpp ------ Hector HAMELIN, Enzo TSANGOUAEKA - 20/10/2024
**************************************************************/

#include <iostream>  // Gestion des entrées, sorties
#include <cstdlib>   // Aléatoire
#include <string>    // Inclusion de string
#include "event.h"   // Utilisation des guillemets pour inclure le fichier local

using namespace std;

// Routine du programme
void loop();

// Variable Global
int nmbrOfSpecimen(10);

bool IsAlive() {
    if(nmbrOfSpecimen > 0) {
        return true;
    }
    else {
        return false;
    }
}

struct SPECIMEN {
    string name;
};

void loop() {
    while (IsAlive()) {
        event("a");
        nmbrOfSpecimen--;
    }

}


int main() {
    srand(time(0));
    loop();
    system("pause");
    return 0;
}
