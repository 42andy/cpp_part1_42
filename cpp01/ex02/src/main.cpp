#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	// Variable string originale
	std::string brain = "HI THIS IS BRAIN";
	
	// Pointeur vers la variable
	std::string *stringPTR = &brain;
	
	// Référence vers la variable
	std::string &stringREF = brain;
	
	std::cout << "\nVariable originale créée: " << brain << std::endl;
	
	// Partie 1: Comparaison des adresses
	std::cout << "=" << std::string(50, '=') << std::endl;
	
	std::cout << "Adresse de la variable 'brain'   : " << &brain << std::endl;
	std::cout << "Adresse stockée dans le pointeur : " << stringPTR << std::endl;
	std::cout << "Adresse de la référence          : " << &stringREF << std::endl;
	
	std::cout << "\n Les trois adresses sont identiques" << std::endl;
	std::cout << " La référence est un ALIAS de la variable originale" << std::endl;
	std::cout << " Le pointeur CONTIENT l'adresse de la variable" << std::endl;
	
	// Partie 2: Comparaison des valeurs
	std::cout << "=" << std::string(50, '=') << std::endl;
	
	std::cout << "Valeur de 'brain'                : " << brain << std::endl;
	std::cout << "Valeur via pointeur (*stringPTR) : " << *stringPTR << std::endl;
	std::cout << "Valeur via référence (stringREF) : " << stringREF << std::endl;
	
	std::cout << "\n Les trois valeurs sont identiques" << std::endl;
	std::cout << " Toutes accèdent à la même zone mémoire" << std::endl;


	std::cout << "\n Pointeur: peut être réassigné, peut être NULL" << std::endl;
	std::cout << " Référence: doit être initialisée, ne peut pas être réassignée" << std::endl;
	std::cout << " Les trois permettent d'accéder/modifier la même donnée" << std::endl;
	
	return 0;
}
