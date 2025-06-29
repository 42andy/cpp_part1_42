#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	std::cout << "\nTest 1 : HumanA (utilise une référence vers Weapon)" << std::endl;
	{
		std::cout << "\nCréation d'une arme 'crude spiked club'" << std::endl;
		Weapon club("crude spiked club");
		
		std::cout << "Création de Bob (HumanA) avec cette arme" << std::endl;
		HumanA bob("Bob", club);
		
		std::cout << "Bob attaque avec son arme :" << std::endl;
		bob.attack();
		
		std::cout << "Changement du type d'arme en 'some other type of club'" << std::endl;
		club.setType("some other type of club");
		
		std::cout << "Bob attaque à nouveau (l'arme a changé automatiquement) :" << std::endl;
		bob.attack();
	}

	std::cout << "\nTest 2 : HumanB (utilise un pointeur vers Weapon)" << std::endl;
	{
		std::cout << "\nCréation de Jim (HumanB) sans arme" << std::endl;
		HumanB jim("Jim");
		
		std::cout << "Jim essaie d'attaquer sans arme:" << std::endl;
		jim.attack();
		
		std::cout << "Création d'une arme 'crude spiked club'" << std::endl;
		Weapon club("crude spiked club");
		
		std::cout << "Attribution de l'arme à Jim" << std::endl;
		jim.setWeapon(club);
		
		std::cout << "Jim attaque maintenant qu'il a une arme :" << std::endl;
		jim.attack();
		
		std::cout << "Changement du type d'arme en 'some other type of club'" << std::endl;
		club.setType("some other type of club");
		
		std::cout << "Jim attaque à nouveau (l'arme a changé):" << std::endl;
		jim.attack();
	}

	return 0;
}
