#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Test de classe abstraite : decommenter pour verifier qu'Animal ne peut pas etre instanciee
	// Animal animal;
	// error: cannot declare variable ‘animal’ to be of abstract type ‘Animal’

	std::cout << "\nCreation (animal->brain->dog/cat) :" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	
	std::cout << "\nTypes des animaux (ex00) :" << std::endl;
	std::cout << "Dog type : " << dog->getType() << std::endl;
	std::cout << "Cat type : " << cat->getType() << std::endl;
	
	std::cout << "\nSons des animaux (polymorphisme fonctionnel) (ex00) :" << std::endl;
	std::cout << "Cat sound : ";
	cat->makeSound();
	std::cout << "Dog sound : ";
	dog->makeSound();

	std::cout << "\nDestruction des animaux (brain->dog/cat->animal) :" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\nCopie profonde (ex01) :" << std::endl;
	std::cout << "Creation du original chien :" << std::endl;
	Dog original;
	original.getBrain()->_ideas[0] = "Original idea";
	std::cout << "Original chien idea : " << original.getBrain()->_ideas[0] << std::endl;
	
	std::cout << "\nCreation du copy-chien :" << std::endl;
	Dog copy = original;
	std::cout << "Apres copie -> Copy-chien idea : " << copy.getBrain()->_ideas[0] << std::endl;
	copy.getBrain()->_ideas[0] = "Copy idea";

	std::cout << "\nApres modification des idees du copy-chien :" << std::endl;
	std::cout << "Original chien: " << original.getBrain()->_ideas[0] << std::endl;
	std::cout << "Copy-chien: " << copy.getBrain()->_ideas[0] << std::endl;
	std::cout << "\nOriginal chien brain address : " << original.getBrain() << std::endl;
	std::cout << "Copy-chien brain address : " << copy.getBrain() << std::endl;

	std::cout << "\nDestruction :" << std::endl;

	return 0;
}
