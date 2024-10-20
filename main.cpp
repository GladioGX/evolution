/*****************************
Hector HAMELIN, Enzo TSANGOUAEKA - 20/10/2024
*****************************/

#include <iostream> // Gestion des entrées, sorties
#include <cstdlib> // Aléatoire
#include "event.cpp"

using namespace std;

// Routine du programme
void loop();

struct SPECIMEN {
    string name;
};

void loop() {
    cout << "Hello World!" << endl;
    while (true) {
        event("a");
    }
}


int main() {
    srand(time(0));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
