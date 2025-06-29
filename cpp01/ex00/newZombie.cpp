#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie *zPtr = new Zombie(name);
	if (!zPtr)
		return NULL;
	return zPtr;
}
