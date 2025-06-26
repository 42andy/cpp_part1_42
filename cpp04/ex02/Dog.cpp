#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructed" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destructed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Ouaf !" << std::endl;
}

Brain* Dog::getBrain() const
{
	return _brain;
}
