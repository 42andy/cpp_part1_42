#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "Creation et destruction :" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << std::endl << "Ordre de destruction (brain->dog/cat->animal) :" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\nTableau mixte d'animaux :" << std::endl;
	Animal* gang[4];
	std::cout << "Creation d'un gang de 4 animaux (2 chiens, 2 chats):" << std::endl;
	for (int idx = 0; idx < 4; ++idx)
	{
		std::cout << "Animal " << idx << " : " << std::endl;
		if (idx < 2)
			gang[idx] = new Dog();
		else
			gang[idx] = new Cat();
	}
	
	std::cout << "\nDestruction du gang :" << std::endl;
	for (int idx = 0; idx < 4; ++idx)
	{
		std::cout << "Deleting animal " << idx << " : " << std::endl;
		delete gang[idx];
	}

	std::cout << "\nCopie profonde :" << std::endl;
	std::cout << "Creation du premier chien :" << std::endl;
	Dog dog1;
	dog1.getBrain()->_ideas[0] = "Mange";
	dog1.getBrain()->_ideas[1] = "Joue";
	std::cout << "Dog1 idea 0 : " << dog1.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 idea 1 : " << dog1.getBrain()->_ideas[1] << std::endl;
	
	std::cout << "\nCreation du deuxieme chien par copie :" << std::endl;
	Dog dog2 = dog1;
	std::cout << "Apres copie -> Dog2 idea 0 : " << dog2.getBrain()->_ideas[0] << std::endl;
	std::cout << "Apres copie -> Dog2 idea 1 : " << dog2.getBrain()->_ideas[1] << std::endl;
	
	std::cout << std::endl << "Modification des idees du deuxieme chien :" << std::endl;
	dog2.getBrain()->_ideas[0] = "Aboie";
	dog2.getBrain()->_ideas[1] = "Attaque";
	
	std::cout << "\nVerification de la copie profonde :" << std::endl;
	std::cout << "Dog1 idea 0 : " << dog1.getBrain()->_ideas[0] << " (Mange)" << std::endl;
	std::cout << "Dog2 idea 0 : " << dog2.getBrain()->_ideas[0] << " (Aboie)" << std::endl;
	std::cout << "Dog1 idea 1 : " << dog1.getBrain()->_ideas[1] << " (Joue)" << std::endl;
	std::cout << "Dog2 idea 1 : " << dog2.getBrain()->_ideas[1] << " (Attaque)" << std::endl;
	
	std::cout << "\nVerification des adresses Brain (differentes) :" << std::endl;
	std::cout << "Dog1 brain address : " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 brain address : " << dog2.getBrain() << std::endl;
	
	std::cout << "\nOperateur d'affectation :" << std::endl;
	std::cout << "Creation d'un troisieme chien :" << std::endl;
	Dog dog3;
	dog3.getBrain()->_ideas[0] = "Dort";
	std::cout << "Dog3 idea 0 : " << dog3.getBrain()->_ideas[0] << std::endl;
	
	std::cout << "\nAffectation dog3 = dog1:" << std::endl;
	dog3 = dog1;
	std::cout << "Dog3 apres affectation : " << dog3.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 (source) : " << dog1.getBrain()->_ideas[0] << std::endl;
	
	std::cout << "\nModification de dog3 pour tester l'independance :" << std::endl;
	dog3.getBrain()->_ideas[0] = "Court";
	std::cout << "Dog3 modifie : " << dog3.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 (doit rester inchange) : " << dog1.getBrain()->_ideas[0] << std::endl;

	std::cout << "\nDestruction :" << std::endl;

	return 0;
}
