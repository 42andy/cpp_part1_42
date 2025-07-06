#include "Fixed.hpp"
#include <iostream>

int main(void)
{
	std::cout << "\nInitialization :" << std::endl;
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;

	std::cout << "\nRaw value of a :" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << "Raw value of b :" << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << "Raw value of c :" << std::endl;
	std::cout << c.getRawBits() << std::endl;
	
	std::cout << "\nDestructors called :" << std::endl;
	
	return 0;
}
