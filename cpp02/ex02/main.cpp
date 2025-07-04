#include <iostream>
#include "Fixed.hpp"

int main (void)
{
	std::cout << "\nInitialization :" << std::endl;
	Fixed a(10);
	Fixed b(42.42f);
	Fixed c(5.5f);
	Fixed d(2);
	Fixed const e(Fixed(5.05f) * Fixed(2));
	
	std::cout << "\nVariables de test :" << std::endl;
	std::cout << "a = " << a << " (from 10)" << std::endl;
	std::cout << "b = " << b << " (from 42.42f)" << std::endl;
	std::cout << "c = " << c << " (from 5.5f)" << std::endl;
	std::cout << "d = " << d << " (from 2)" << std::endl;
	std::cout << "e = " << e << " (from 5.05 x 2)" << std::endl;

	std::cout << "\nTests opérateurs de comparaison :" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a > b : " << (a > b) << " (should be 0)" << std::endl;
	std::cout << "a < b : " << (a < b) << " (should be 1)" << std::endl;
	std::cout << "a >= b : " << (a >= b) << " (should be 0)" << std::endl;
	std::cout << "a <= b : " << (a <= b) << " (should be 1)" << std::endl;
	std::cout << "a == b : " << (a == b) << " (should be 0)" << std::endl;
	std::cout << "a != b : " << (a != b) << " (should be 1)" << std::endl;
	
	Fixed a_copy(10);
	std::cout << "\nTests égalité avec même valeur :" << std::endl;
	std::cout << "a = " << a << ", a_copy = " << a_copy << std::endl;
	std::cout << "a == a_copy : " << (a == a_copy) << " (should be 1)" << std::endl;
	std::cout << "a >= a_copy : " << (a >= a_copy) << " (should be 1)" << std::endl;
	std::cout << "a <= a_copy : " << (a <= a_copy) << " (should be 1)" << std::endl;

	std::cout << "\nTests opérateurs arithmétiques :" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c + d = " << (c + d) << " (should be 7.5)" << std::endl;
	std::cout << "c - d = " << (c - d) << " (should be 3.5)" << std::endl;
	std::cout << "c * d = " << (c * d) << " (should be 11)" << std::endl;
	std::cout << "c / d = " << (c / d) << " (should be 2.75)" << std::endl;

	std::cout << "\nTests opérateurs d'incrément/décrément :" << std::endl;
	Fixed f(5.5f);
	std::cout << "f initial = " << f << std::endl;
	
	std::cout << "\nPré-incrémentation :" << std::endl;
	std::cout << "++f = " << ++f << " (should be 5.50391)" << std::endl;
	std::cout << "f after ++f = " << f << " (should be 5.50391)" << std::endl;
	
	std::cout << "\nPost-incrémentation :" << std::endl;
	std::cout << "f++ = " << f++ << " (should return 5.50391)" << std::endl;
	std::cout << "f after f++ = " << f << " (should be 5.50781)" << std::endl;
	
	std::cout << "\nPré-décrémentation :" << std::endl;
	std::cout << "--f = " << --f << " (should be 5.50391)" << std::endl;
	std::cout << "f after --f = " << f << " (should be 5.50391)" << std::endl;
	
	std::cout << "\nPost-décrémentation :" << std::endl;
	std::cout << "f-- = " << f-- << " (should be 5.50391)" << std::endl;
	std::cout << "f after f-- = " << f << " (should be 5.5)" << std::endl;

	std::cout << "\nTests fonctions min/max :" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << " (should be 10)" << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << " (should be 42.4219)" << std::endl;
	
	const Fixed const_a(10);
	const Fixed const_b(42.42f);
	std::cout << "\nTests avec valeurs const :" << std::endl;
	std::cout << "Fixed::min(const_a, const_b) = " << Fixed::min(const_a, const_b) << std::endl;
	std::cout << "Fixed::max(const_a, const_b) = " << Fixed::max(const_a, const_b) << std::endl;

	std::cout << "\nTests avec valeurs négatives :" << std::endl;
	Fixed neg1(-10);
	Fixed neg2(-5.5f);
	Fixed pos(3);
	
	std::cout << "neg1 = " << neg1 << ", neg2 = " << neg2 << ", pos = " << pos << std::endl;
	std::cout << "neg1 + neg2 = " << (neg1 + neg2) << " (should be -15.5)" << std::endl;
	std::cout << "neg1 - neg2 = " << (neg1 - neg2) << " (should be -4.5)" << std::endl;
	std::cout << "neg1 * neg2 = " << (neg1 * neg2) << " (should be 55)" << std::endl;
	std::cout << "neg1 / neg2 = " << (neg1 / neg2) << " (should be ≈ 1.82)" << std::endl;
	std::cout << "neg1 < pos: " << (neg1 < pos) << " (should be 1)" << std::endl;
	std::cout << "neg1 > neg2: " << (neg1 > neg2) << " (should be 0)" << std::endl;
	std::cout << "Fixed::min(neg1, neg2) = " << Fixed::min(neg1, neg2) << " (should be -10)" << std::endl;

	// Test division par zéro
	std::cout << "\nTest division par zéro :" << std::endl;
	Fixed zero(0);
	Fixed ten(10);
	std::cout << "ten = " << ten << ", zero = " << zero << std::endl;
	std::cout << "ten / zero = " << (ten / zero) << " (should show error)" << std::endl;

	return 0;
}
