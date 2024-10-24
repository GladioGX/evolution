// event.cpp
#include <iostream> // Gestion des entrées, sorties
#include <cstdlib>  // Aléatoire
#include "event.h"

using namespace std;

void event(unsigned long long int _nmbrOfSpecimen);
void event1();
void event2();
void event3();
void event4();


// Retournera un evenement qui a x probabilité d'arriver
void event(unsigned long long int _nmbrOfSpecimen) {
    int prob (rand() % 100 + 1);
    if (prob < 26) {
        event1();
    }
    else if (prob < 51) {
        event2();
    }
    else if (prob < 76) {
        event3();
    }
    else if (prob < 101) {
        event4();
    }
}

// 25 % (1 à 25)
void event1() {
    cout << "Il pleut, le taux de reproducation augemnte de x2 durant la nuit." << endl;
}

// 25 % (26 à 50)
void event2() {
    cout << "Il vente" << endl;
}

// 25 % (51 à 75)
void event3() {
    cout << "Il neige" << endl;
}

// 25 % (76 à 100)
void event4() {
    cout << "Il fait soleil" << endl;
}