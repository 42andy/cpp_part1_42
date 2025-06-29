#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main()
{
	std::cout << "\nTest 1 : Création de zombies sur la HEAP (avec newZombie)" << std::endl;
	std::cout << "Les zombies créés sur le heap doivent être explicitement supprimés" << std::endl;
	
	// Test 1: Zombies sur la heap
	std::cout << "\nCréation d'un zombie Hipz_1 sur le heap :" << std::endl;
	Zombie *heapZombie1 = newZombie("Hipz_1");
	heapZombie1->announce();
	
	std::cout << "Création d'un zombie Hipz_2 sur le heap:" << std::endl;
	Zombie *heapZombie2 = newZombie("Hipz_2");
	heapZombie2->announce();
	
	std::cout << "\nSuppression manuelle des zombies du heap:" << std::endl;
	delete heapZombie1;
	delete heapZombie2;

	std::cout << "\nTest 2 : Création de zombies sur la STACK (avec randomChump)" << std::endl;
	std::cout << "Les zombies créés sur la stack sont automatiquement détruits" << std::endl;
	
	// Test 2: Zombies sur la stack
	std::cout << "\nCréation et annonce automatique de Stakz_1 :" << std::endl;
	randomChump("Stakz_1");
	
	std::cout << "Création et annonce automatique de Stakz_2 :" << std::endl;
	randomChump("Stakz_2");

	std::cout << "\nTest 3 : Comparaison heap vs stack" << std::endl;
	std::cout << "Démonstration de la différence entre allocation heap et stack\n" << std::endl;
	
	// Zombie sur la heap (survit au scope)
	Zombie *persistentZombie;
	{
		std::cout << "Début du bloc scope local..." << std::endl;
		
		persistentZombie = newZombie("Rezist");
		persistentZombie->announce();
		
		// Zombie sur la stack (détruit à la fin du scope)
		std::cout << "Zombie temporaire dans ce scope :" << std::endl;
		randomChump("Tempz");
		
		std::cout << "Fin du bloc scope local (Tempz est détruit automatiquement)" << std::endl;
	}
	
	std::cout << "\nRezist existe toujours, preuve:" << std::endl;
	persistentZombie->announce();
	
	std::cout << "\nNettoyage final:" << std::endl;
	delete persistentZombie;

	return 0;
}