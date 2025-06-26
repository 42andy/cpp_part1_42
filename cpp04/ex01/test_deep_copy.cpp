
#include "Cat.hpp"

int main() {
	std::cout << "=== Test copie profonde ===" << std::endl;
	
	Cat cat1;
	cat1.getBrain()->_ideas[0] = "Original idea";
	cat1.getBrain()->_ideas[1] = "Another idea";
	
	// Test constructeur de copie
	Cat cat2 = cat1;
	cat2.getBrain()->_ideas[0] = "Modified idea";
	
	std::cout << "Cat1 idea[0]: " << cat1.getBrain()->_ideas[0] << std::endl;
	std::cout << "Cat2 idea[0]: " << cat2.getBrain()->_ideas[0] << std::endl;
	std::cout << "Cat1 idea[1]: " << cat1.getBrain()->_ideas[1] << std::endl;
	std::cout << "Cat2 idea[1]: " << cat2.getBrain()->_ideas[1] << std::endl;
	
	// Vérifier que les adresses des Brain sont différentes
	std::cout << "Cat1 brain address: " << cat1.getBrain() << std::endl;
	std::cout << "Cat2 brain address: " << cat2.getBrain() << std::endl;
	
	return 0;
}
