#include "Zombie.hpp"
#include <iostream>
#include <cstdlib>

Zombie *zombieHorde(int N, std::string name);

int main()
{
	Zombie *horde;

	std::cout << "\nTest 1 : Création d'une petite horde (3 zombies)" << std::endl;
	horde = zombieHorde(3, "Smolz");
	
	std::cout << "\nAnnonce de tous les zombies de la petite horde :" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "\nDestruction de la petite horde..." << std::endl;
	delete[] horde;
	
	std::cout << "\nTest 2 : Création d'une horde moyenne (7 zombies)" << std::endl;
	horde = zombieHorde(7, "Medz");
	
	std::cout << "\nAnnonce de tous les zombies de la horde moyenne :" << std::endl;
	for (int i = 0; i < 7; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "\nDestruction de la horde moyenne..." << std::endl;
	delete[] horde;
	
	std::cout << "\nTest 3 : Création d'une grande horde (12 zombies)" << std::endl;
	horde = zombieHorde(12, "Bigz");
	
	std::cout << "\nAnnonce de tous les zombies de la grande horde :" << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << " [" << i << "] ";
		horde[i].announce();
	}
	std::cout << "\nDestruction de la grande horde..." << std::endl;
	delete[] horde;
	
	std::cout << "\nTest 4: Cas limite - Horde de 0 zombie" << std::endl;
	horde = zombieHorde(0, "Ghostz");
	if (horde == NULL)
		std::cout << "Aucun zombie créé (pointeur NULL retourné)" << std::endl;

	return 0;
}
