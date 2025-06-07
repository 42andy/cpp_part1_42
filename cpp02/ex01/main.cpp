#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	std::cout << "\nInitialization :" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	a = Fixed(1234.4321f);

	std::cout << "\nDisplay using operator << (calls toFloat() internally) :" << std::endl;
	std::cout << "a is " << a << " (originally 1234.4321f)" << std::endl;
	std::cout << "b is " << b << " (originally 10)" << std::endl;
	std::cout << "c is " << c << " (originally 42.42f)" << std::endl;
	std::cout << "d is " << d << " (copy of b)" << std::endl;

	std::cout << "\nConversion to integers using toInt() (truncates fractional part) :" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer (1234.4321 → 1234)" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer (10.0 → 10)" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer (42.42 → 42)" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer (copy of b → 10)" << std::endl;
	std::cout << "\nDestructors called :" << std::endl;
	return 0;
}