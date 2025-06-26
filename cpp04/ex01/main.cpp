#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "--- Test basic: creation et destruction ---" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl << "Destruction via pointeurs Animal* (destructeurs virtuels):" << std::endl;
	delete j;
	delete i;

	std::cout << std::endl << "--- Test tableau mixte d'animaux ---" << std::endl;
	Animal* zoo[4];
	std::cout << "Creation d'un zoo de 4 animaux (2 chiens, 2 chats):" << std::endl;
	for (int idx = 0; idx < 4; ++idx) {
		std::cout << "Animal " << idx << ": ";
		if (idx < 2) {
			zoo[idx] = new Dog();
		} else {
			zoo[idx] = new Cat();
		}
	}
	
	std::cout << std::endl << "Destruction du zoo:" << std::endl;
	for (int idx = 0; idx < 4; ++idx) {
		std::cout << "Deleting animal " << idx << ": ";
		delete zoo[idx];
	}

	std::cout << std::endl << "--- Test copie profonde (Deep Copy) ---" << std::endl;
	std::cout << "Creation du premier chien:" << std::endl;
	Dog dog1;
	dog1.getBrain()->_ideas[0] = "Chase the cat";
	dog1.getBrain()->_ideas[1] = "Bark at mailman";
	std::cout << "Dog1 ideas[0]: " << dog1.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 ideas[1]: " << dog1.getBrain()->_ideas[1] << std::endl;
	
	std::cout << std::endl << "Creation du deuxieme chien par copie:" << std::endl;
	Dog dog2 = dog1; // Constructeur de copie
	std::cout << "Apres copie - Dog2 ideas[0]: " << dog2.getBrain()->_ideas[0] << std::endl;
	std::cout << "Apres copie - Dog2 ideas[1]: " << dog2.getBrain()->_ideas[1] << std::endl;
	
	std::cout << std::endl << "Modification des idees du deuxieme chien:" << std::endl;
	dog2.getBrain()->_ideas[0] = "Play fetch";
	dog2.getBrain()->_ideas[1] = "Sleep on couch";
	
	std::cout << std::endl << "Verification de l'independance (copie profonde):" << std::endl;
	std::cout << "Dog1 ideas[0]: " << dog1.getBrain()->_ideas[0] << " (doit rester 'Chase the cat')" << std::endl;
	std::cout << "Dog2 ideas[0]: " << dog2.getBrain()->_ideas[0] << " (doit etre 'Play fetch')" << std::endl;
	std::cout << "Dog1 ideas[1]: " << dog1.getBrain()->_ideas[1] << " (doit rester 'Bark at mailman')" << std::endl;
	std::cout << "Dog2 ideas[1]: " << dog2.getBrain()->_ideas[1] << " (doit etre 'Sleep on couch')" << std::endl;
	
	std::cout << std::endl << "Verification des adresses Brain (doivent etre differentes):" << std::endl;
	std::cout << "Dog1 brain address: " << dog1.getBrain() << std::endl;
	std::cout << "Dog2 brain address: " << dog2.getBrain() << std::endl;
	
	std::cout << std::endl << "--- Test operateur d'affectation ---" << std::endl;
	std::cout << "Creation d'un troisieme chien:" << std::endl;
	Dog dog3;
	dog3.getBrain()->_ideas[0] = "Original idea";
	std::cout << "Dog3 original idea: " << dog3.getBrain()->_ideas[0] << std::endl;
	
	std::cout << std::endl << "Affectation dog3 = dog1:" << std::endl;
	dog3 = dog1;
	std::cout << "Dog3 apres affectation: " << dog3.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 (source): " << dog1.getBrain()->_ideas[0] << std::endl;
	
	std::cout << std::endl << "Modification de dog3 pour tester l'independance:" << std::endl;
	dog3.getBrain()->_ideas[0] = "New assigned idea";
	std::cout << "Dog3 modifie: " << dog3.getBrain()->_ideas[0] << std::endl;
	std::cout << "Dog1 (doit rester inchange): " << dog1.getBrain()->_ideas[0] << std::endl;

	std::cout << std::endl << "Destruction automatique des objets locaux:" << std::endl;
	return 0;
}
