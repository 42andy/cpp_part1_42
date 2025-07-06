#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	std::cout << "\nPolymorphisme avec virtual :" << std::endl;
	const Animal* ani = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\nTypes des animaux :" << std::endl;
	std::cout << "Dog type : " << dog->getType() << std::endl;
	std::cout << "Cat type : " << cat->getType() << std::endl;
	
	std::cout << "\nSons des animaux (polymorphisme fonctionnel):" << std::endl;
	std::cout << "Cat sound : ";
	cat->makeSound();
	std::cout << "Dog sound : ";
	dog->makeSound();
	std::cout << "Animal sound : ";
	ani->makeSound();

	std::cout << "\nDestruction des animaux :" << std::endl;
	delete ani;
	delete dog;
	delete cat;

	std::cout << "\nPolymorphisme sans virtual :" << std::endl;
	const WrongAnimal* wani = new WrongAnimal();
	const WrongAnimal* wcat = new WrongCat();
	
	std::cout << "\nType du WrongCat :" << std::endl;
	std::cout << "WrongCat type : " << wcat->getType() << std::endl;
	
	std::cout << "\nSons (polymorphisme dysfonctionnel) :" << std::endl;
	std::cout << "WrongCat sound via WrongAnimal* : ";
	wcat->makeSound(); // Appelle WrongAnimal::makeSound() au lieu de WrongCat::makeSound()
	std::cout << "WrongAnimal sound : ";
	wani->makeSound();

	std::cout << "\nDemonstration du WrongCat sound :" << std::endl;
	WrongCat directWrongCat;
	std::cout << "WrongCat sound direct : ";
	directWrongCat.makeSound(); // Appelle bien WrongCat::makeSound()

	std::cout << "\nDestruction des WrongAnimaux :" << std::endl;
	delete wani;
	delete wcat;
	
	return 0;
}
