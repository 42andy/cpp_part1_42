#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "\nCréation d'un ClapTrap de base :" << std::endl;
	ClapTrap robot1("Robot1");

	std::cout << "\nRobot1 va attaquer, subir des dégâts et se réparer :" << std::endl;
	robot1.attack("Enemy");
	robot1.takeDamage(5);
	robot1.beRepaired(3);

	std::cout << "\nCréation d'un ScavTrap (héritage de ClapTrap) :" << std::endl;
	ScavTrap scav1("Scav1");

	std::cout << "\nScav1 va attaquer, subir des dégâts et se réparer + capacité :" << std::endl;
	scav1.attack("Enemy");
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	scav1.guardGate();

	std::cout << "\nCréation d'un FragTrap (héritage de ClapTrap):" << std::endl;
	FragTrap frag1("Frag1");

	std::cout << "\nFrag1 utilise les capacités de ClapTrap (pas de redéfinition) :" << std::endl;
	frag1.attack("Enemy");
	frag1.takeDamage(30);
	frag1.beRepaired(15);

	std::cout << "\nCapacité unique de Fragtrap :" << std::endl;
	frag1.highFivesGuys();

	std::cout << "\nComparaison des trois types :" << std::endl;
	std::cout << "\nClapTrap Robot1 (Attack Damage : 0) :" << std::endl;
	robot1.attack("TestTarget");
	std::cout << "\nScavTrap Scav1 (Attack Damage : 20) :" << std::endl;
	scav1.attack("TestTarget");
	std::cout << "\nFragTrap Frag1 (Attack Damage : 30) :" << std::endl;
	frag1.attack("TestTarget");

	std::cout << "\nOrdre de construction/destruction :" << std::endl;
	{
		FragTrap frag2("Frag2");
		std::cout << "Frag2 va être détruit à la fin du scope..." << std::endl;
	}

	std::cout << "\nCapacités spéciales de chaque type :" << std::endl;
	std::cout << "ScavTrap :" << std::endl;
	scav1.guardGate();
	std::cout << "FragTrap :" << std::endl;
	frag1.highFivesGuys();


	std::cout << "\nDestruction :" << std::endl;
	std::cout << "Ordre de destruction: Frag1, Scav1, Robot1" << std::endl;

	return 0;
}