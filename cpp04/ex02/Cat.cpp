#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructed" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*_brain = *other._brain;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou !" << std::endl;
}

Brain* Cat::getBrain() const
{
	return _brain;
}
