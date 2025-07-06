#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		_ideas[i] = "";
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain copy constructed" << std::endl;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = other._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}
