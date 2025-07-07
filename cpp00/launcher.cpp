#include <iostream>
#include <cstdlib>

int main()
{
	std::string choice;

	std::cout << "Quel exercice veux-tu lancer ?" << std::endl;
	std::cout << "0. ex00 (megaphone)" << std::endl;
	std::cout << "1. ex01 (phonebook)" << std::endl;
	std::cout << "> ";
	std::cin >> choice;

	if (choice == "0")
	{
		std::string args;
		std::cout << "Arguments pour megaphone (ou Entrée pour aucun arg) :" << std::endl;
		std::cin.ignore();
		std::getline(std::cin, args);
		std::system(("ex00/megaphone " + args).c_str());
	}
	else if (choice == "1")
		std::system("ex01/phonebook");
	else
		std::cout << "Choix invalide." << std::endl;

	return 0;
}
