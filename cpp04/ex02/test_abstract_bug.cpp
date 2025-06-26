#include "Animal.hpp"

int main() {
    // Cette ligne DOIT provoquer une erreur si Animal est vraiment abstraite
    Animal animal; // ERROR: cannot declare variable 'animal' to be of abstract type 'Animal'
    
    return 0;
}
