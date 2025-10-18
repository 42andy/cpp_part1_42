#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
	std::cout << "Test constructeur defaut : " << std::endl;
	Array<int> emptyArray;
	std::cout << "Taille array vide : " << emptyArray.size() << std::endl;

	std::cout << "\nTest constructeur avec taille : " << std::endl;
	Array<int> intArray(5);
	std::cout << "Taille array : " << intArray.size() << std::endl;

	std::cout << "\nRemplissage tableau : " << std::endl;
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i;

	std::cout << "Contenu array int: ";
	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\nTest constructeur copie : " << std::endl;
	Array<int> copyArray(intArray);
	std::cout << "Taille de la copie : " << copyArray.size() << std::endl;
	std::cout << "Contenu de la copie : ";
	for (unsigned int i = 0; i < copyArray.size(); i++)
		std::cout << copyArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\nModification original : " << std::endl;
	intArray[0] = 999;
	std::cout << "Original modifié : " << intArray[0] << std::endl;
	std::cout << "Copie non modifiée : " << copyArray[0] << std::endl;

	std::cout << "\nTest operateur assignation : " << std::endl;
	Array<int> assignArray;
	assignArray = intArray;
	std::cout << "Taille de assign : " << assignArray.size() << std::endl;

	std::cout << "\nTest chaines de char : " << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "World";
	stringArray[2] = "!";
	std::cout << "String array : ";
	for (unsigned int i = 0; i < stringArray.size(); i++)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;

	std::cout << "\nTest hors limites : " << std::endl;
	try {
		std::cout << intArray[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception attrapée : " << e.what() << std::endl;
	}

	return 0;
}
