#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	std::cout << "\nInitialization :" << std::endl;
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	std::cout << "\nDefault constructor : a = " << a << " (from 0)" << std::endl;
	std::cout << "Int constructor : b = " << b << " (from 10)" << std::endl;
	std::cout << "Float constructor : c = " << c << " (from 42.42f)" << std::endl;
	std::cout << "Copy constructor : d = " << d << " (copy of b (10))" << std::endl;

	std::cout << "\nTests opérateur d'assignation :" << std::endl;
	std::cout << "\nAssignation -> a = Fixed(1234.4321f)" << std::endl;
	a = Fixed(1234.4321f);
	std::cout << "a = " << a << " (from 1234.4321f)" << std::endl;

	std::cout << "\nAssignation -> e = b" << std::endl;
	Fixed e;
	e = b;
	std::cout <<"e = " << e << " (from b (10))" << std::endl;

	std::cout << "\nTests opérateur d'insertion<< pour montrer values :" << std::endl;
	std::cout << "a = " << a << " (from 1234.4321f)" << std::endl;
	std::cout << "b = " << b << " (from 10)" << std::endl;
	std::cout << "c = " << c << " (from 42.42f)" << std::endl;
	std::cout << "d = " << d << " (copy of b(10))" << std::endl;

	std::cout << "\nTests méthodes de conversion :" << std::endl;
	std::cout << "toInt() :" << std::endl;
	std::cout << "a.toInt() = " << a.toInt() << " (from 1234.4321f)" << std::endl;
	std::cout << "b.toInt() = " << b.toInt() << " (from 10)" << std::endl;
	std::cout << "c.toInt() = " << c.toInt() << " (from 42.42f)" << std::endl;
	
	std::cout << "\ntoFloat() :" << std::endl;
	std::cout << "a.toFloat() = " << a.toFloat() << " (from 1234.4321f)" << std::endl;
	std::cout << "b.toFloat() = " << b.toFloat() << " (from 10)" << std::endl;
	std::cout << "c.toFloat() = " << c.toFloat() << " (from 42.42f)" << std::endl;

	std::cout << "\nTests méthodes getRawBits/setRawBits :" << std::endl;
	Fixed f;
	std::cout << "f initial value = " << f << std::endl;
	std::cout << "f.getRawBits() = " << f.getRawBits() << std::endl;
	
	std::cout << "\nAfter f.setRawBits(256) :" << std::endl;
	f.setRawBits(256);
	std::cout << "f = " << f << " (from 1 (toFloat() value))" <<std::endl;
	std::cout << "f.getRawBits() = " << f.getRawBits() << " (from 256 (raw value))" << std::endl;

	std::cout << "\nTests valeurs négatives :" << std::endl;
	Fixed neg1(-42);
	Fixed neg2(-3.14f);
	std::cout << "neg1 = " << neg1 << " (from -42)" << std::endl;
	std::cout << "neg2 = " << neg2 << " (from -3.14f)" << std::endl;
	std::cout << "neg1.toInt() = " << neg1.toInt() << std::endl;
	std::cout << "neg2.toInt() = " << neg2.toInt() << std::endl;

	std::cout << "\nDestructors called :" << std::endl;
	
	return 0;
}
