#include "Zombie.hpp"

Zombie *newZombie(std::string);
void randomChump(std::string);

int main()
{
	Zombie *heapZombie = newZombie("Hipz");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stakz");
	return 0;
}