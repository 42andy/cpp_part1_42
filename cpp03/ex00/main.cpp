#include "ClapTrap.hpp"

int main()
{
	std::cout << "\nConstruction de ClapTraps :" << std::endl;
	ClapTrap robot1("Robot1");
	ClapTrap robot2("Robot2");

	std::cout << "\nRobot1 va attaquer, subir des dégâts et se réparer :" << std::endl;
	robot1.attack("Enemy");
	robot1.takeDamage(5);
	robot1.beRepaired(3);

	std::cout << "\nRobot1 va mourir :" << std::endl;
	robot1.attack("Enemy");
	robot1.takeDamage(15);

	std::cout << "\nRobot1 devrait etre mort et ne peut attaquer :" << std::endl;
	robot1.attack("Enemy");
	robot1.beRepaired(5);

	std::cout << "\nRobot2 va epuiser ses points d'énergie (10 max) :" << std::endl;
	robot2.attack("Enemy1");
	robot2.attack("Enemy2");
	robot2.attack("Enemy3");
	robot2.attack("Enemy4");
	robot2.attack("Enemy5");
	robot2.attack("Enemy6");
	robot2.attack("Enemy7");
	robot2.attack("Enemy8");
	robot2.attack("Enemy9");
	robot2.attack("Enemy10");

	std::cout << "\nTentative d'attaque sans énergie :" << std::endl;
	robot2.attack("Enemy11");

	std::cout << "\nDestruction :" << std::endl;

	return 0;
}
