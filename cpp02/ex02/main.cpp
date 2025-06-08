#include <iostream>
#include "Fixed.hpp"

int main (void)
{
	std::cout << "\nInitialization :" << std::endl;
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	std::cout << "a = " << a << " (default value)" << std::endl;
	std::cout << "b = " << b << " (result of 5.05 x 2)" << std::endl;

	std::cout << "\nIncrement operators :" << std::endl;
	std::cout << "a before increment: " << a << std::endl;
	std::cout << "++a (pre-increment): " << ++a << " (increments then returns reference)" << std::endl;
	std::cout << "a after pre-increment: " << a << std::endl;
	std::cout << "a++ (post-increment): " << a++ << " (returns copy, then increments)" << std::endl;
	std::cout << "a after post-increment: " << a << std::endl;

	std::cout << "\nTesting min/max functions :" << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << " (should be b = " << b << ")" << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << " (should be a = " << a << ")" << std::endl;

	std::cout << "\nTesting division by zero protection :" << std::endl;
	Fixed zero(0);
	Fixed ten(10);
	std::cout << "ten = " << ten << ", zero = " << zero << std::endl;
	std::cout << "ten / zero = " << (ten / zero) << " (should show error message)" << std::endl;
	return 0;
}
