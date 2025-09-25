#include "iter.hpp"
#include <string>
#include <iostream>

template<typename T>
void printElement(T const &element)
{
	std::cout << element << " ";
}

void addOne(int &n)
{
	n++;
}

void toUpper(char &c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
}

int main(void)
{
	std::cout << "Test tableaux entiers : " << std::endl;;
	int intArray[] = {1, 2, 3, 4, 5};
	int intLength = 5;
	
	std::cout << "Array original : ";
	iter(intArray, intLength, printElement<int>);
	
	iter(intArray, intLength, addOne);
	
	std::cout << "\nApres addOne : ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	std::cout << "\nTest tableaux char : ";
	char charArray[] = {'h', 'e', 'l', 'l', 'o'};
	int charLength = 5;
	
	std::cout << "\nChar array original : ";
	iter(charArray, charLength, printElement<char>);
	
	iter(charArray, charLength, toUpper);

	std::cout << "\nApres toUpper : ";
	iter(charArray, charLength, printElement<char>);
	std::cout << std::endl;

	std::cout << "\nTest tableaux chaines de char : ";
	std::string stringArray[] = {"un", "deux", "trois"};
	int stringLength = 3;
	
	std::cout << "\nString array : ";
	iter(stringArray, stringLength, printElement<std::string>);
	
	std::cout << std::endl;
	return 0;
}
