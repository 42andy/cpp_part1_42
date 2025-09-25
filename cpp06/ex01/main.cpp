#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data originalData;
	originalData.number = 42;
	originalData.text = "Hello World";
	originalData.value = 3.14;

	std::cout << "Original Data :" << std::endl;
	std::cout << "Address : " << &originalData << std::endl;
	std::cout << "Number : " << originalData.number << std::endl;
	std::cout << "Text : " << originalData.text << std::endl;
	std::cout << "Value : " << originalData.value << std::endl;

	uintptr_t serialized = Serializer::serialize(&originalData);
	std::cout << "\nSerialized : " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	
	std::cout << "\nDeserialized Data :" << std::endl;
	std::cout << "Address : " << deserialized << std::endl;
	std::cout << "Number : " << deserialized->number << std::endl;
	std::cout << "Text : " << deserialized->text << std::endl;
	std::cout << "Value : " << deserialized->value << std::endl;

	return 0;
}
