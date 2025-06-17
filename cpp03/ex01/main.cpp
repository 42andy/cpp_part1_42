#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

	std::cout << "\nScav1 va attaquer, subir des dégâts et se réparer :" << std::endl;
	scav1.attack("Enemy");
	scav1.takeDamage(20);
	scav1.beRepaired(10);

	std::cout << "\nCapacité unique de Scavtrap :" << std::endl;
	scav1.guardGate();

	std::cout << "\nOrdre de construction/destruction :" << std::endl;
	{
		ScavTrap scav2("Scav2");
		std::cout << "Scav2 va être détruit à la fin du scope..." << std::endl;
	}

	std::cout << "\nDestruction :" << std::endl;
	std::cout << "Ordre de destruction: Scav1 puis Robot1" << std::endl;

	return 0;
}