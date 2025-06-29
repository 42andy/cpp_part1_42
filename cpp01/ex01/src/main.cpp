#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

// Prototype de la fonction
Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *horde;
	// Test 1: Petite horde
	std::cout << "Test 1: Création d'une petite horde (3 zombies)" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	horde = zombieHorde(3, "Smolz");
	
	std::cout << "Annonce de tous les zombies de la petite horde :" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "Destruction de la petite horde..." << std::endl;
	delete[] horde;
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 2: Horde moyenne
	std::cout << "\nTest 2: Création d'une horde moyenne (7 zombies)" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	horde = zombieHorde(7, "Medz");
	
	std::cout << "Annonce de tous les zombies de la horde moyenne:" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "Destruction de la horde moyenne..." << std::endl;
	delete[] horde;
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 3: Grande horde
	std::cout << "\nTest 3: Création d'une grande horde (12 zombies)" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	horde = zombieHorde(12, "Bigz");
	
	std::cout << "Annonce de tous les zombies de la grande horde :" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "Destruction de la grande horde..." << std::endl;
	delete[] horde;
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 4: Horde vide
	std::cout << "\nTest 4: Cas limite - Horde de 0 zombie" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	horde = zombieHorde(0, "Ghostz");
	if (horde == NULL)
		std::cout << "Aucun zombie créé (pointeur NULL retourné)" << std::endl;
	else
	{
		std::cout << "Horde vide créée mais pointeur valide" << std::endl;
		delete[] horde;
	}

	return 0;
}
