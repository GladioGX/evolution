#include <iostream> // Gestion des entrées, sorties

using namespace std;

void event(string _name);

void event(string _name) {
    switch (_name) {
        case 'a':
            std::cout << "aaaaaaaa" << std::endl;
            break;
        case 'b':
            std::cout << "bbbbbbbb" << std::endl;
            break;
        default:
            break;
    }
}