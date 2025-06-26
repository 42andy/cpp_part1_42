#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
	std::cout << "=== EXERCICE 02: CLASSE ABSTRAITE ===" << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test: Classe Animal devenue abstraite ---" << std::endl;
	std::cout << "La classe Animal ne peut plus etre instanciee directement" << std::endl;
	std::cout << "Decommenter la ligne suivante provoquera une erreur de compilation:" << std::endl;
	std::cout << "// Animal animal; // ERROR: cannot declare variable 'animal' to be of abstract type 'Animal'" << std::endl;
	
	std::cout << std::endl << "--- Creation d'animaux concrets via pointeurs Animal* ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl << "Types et sons des animaux:" << std::endl;
	std::cout << "Dog type: " << j->getType() << std::endl;
	std::cout << "Cat type: " << i->getType() << std::endl;
	
	std::cout << std::endl << "Sons (makeSound est pure virtuelle dans Animal):" << std::endl;
	std::cout << "Cat sound: ";
	i->makeSound(); // Appelle Cat::makeSound()
	std::cout << "Dog sound: ";
	j->makeSound(); // Appelle Dog::makeSound()

	std::cout << std::endl << "Destruction via pointeurs Animal* (polymorphisme):" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "--- Test copie profonde avec Brain (heritage de ex01) ---" << std::endl;
	std::cout << "Creation et modification d'un chien:" << std::endl;
	Dog d1;
	d1.getBrain()->_ideas[0] = "Fetch ball";
	d1.getBrain()->_ideas[1] = "Guard house";
	std::cout << "Dog1 _ideas[0]: " << d1.getBrain()->_ideas[0] << std::endl;
	
	std::cout << std::endl << "Copie du chien:" << std::endl;
	Dog d2 = d1;
	std::cout << "Dog2 (copie) _ideas[0]: " << d2.getBrain()->_ideas[0] << std::endl;
	
	std::cout << std::endl << "Modification de la copie:" << std::endl;
	d2.getBrain()->_ideas[0] = "Chase tail";
	std::cout << "Apres modification:" << std::endl;
	std::cout << "Dog1 _ideas[0]: " << d1.getBrain()->_ideas[0] << " (original preserve)" << std::endl;
	std::cout << "Dog2 _ideas[0]: " << d2.getBrain()->_ideas[0] << " (copie modifiee)" << std::endl;
	
	std::cout << std::endl << "Verification des adresses Brain distinctes:" << std::endl;
	std::cout << "Dog1 brain: " << d1.getBrain() << std::endl;
	std::cout << "Dog2 brain: " << d2.getBrain() << std::endl;

	std::cout << std::endl << "--- Test avec des chats ---" << std::endl;
	Cat cat1;
	cat1.getBrain()->_ideas[0] = "Hunt mice";
	Cat cat2;
	cat2 = cat1; // Operateur d'affectation
	cat2.getBrain()->_ideas[0] = "Sleep all day";
	
	std::cout << "Cat1 idea: " << cat1.getBrain()->_ideas[0] << std::endl;
	std::cout << "Cat2 idea: " << cat2.getBrain()->_ideas[0] << std::endl;

	std::cout << std::endl << "Destruction automatique des objets locaux:" << std::endl;
	return 0;
}
