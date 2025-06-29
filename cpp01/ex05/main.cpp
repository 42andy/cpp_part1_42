#include "Harl.hpp"
#include <iostream>

int main()
{
	std::cout << "\nCréation d'une instance de Harl" << std::endl;
	Harl harl;

	std::cout << "\nTest 1 : Niveau DEBUG" << std::endl;
	harl.complain("DEBUG");

	std::cout << "\nTest 2 : Niveau INFO" << std::endl;
	harl.complain("INFO");

	std::cout << "\nTest 3 : Niveau WARNING" << std::endl;
	harl.complain("WARNING");

	std::cout << "\nTest 4 : Niveau ERROR" << std::endl;
	harl.complain("ERROR");

	std::cout << "\nTests en + : Gestion des niveaux invalides :" << std::endl;
	
	std::cout << "\nTest avec niveau vide :" << std::endl;
	harl.complain("");

	std::cout << "\nTest avec niveau en minuscules 'debug' :" << std::endl;
	harl.complain("debug");

	std::cout << "\nTest avec niveau invalide 'INVALID' :" << std::endl;
	harl.complain("INVALID");

	return 0;
}
