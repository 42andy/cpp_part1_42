#include "Fixed.hpp"
#include <climits>

Fixed::Fixed() : _value(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _bits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: _value(static_cast<int>(roundf(value * (1 << _bits))))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_value) / (1 << _bits);
}

int Fixed::toInt(void) const
{
	return this->_value >> _bits;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	long long temp = static_cast<long long> (this->_value) * other._value;
	long long final_result = temp >> _bits;

	if (final_result > INT_MAX || final_result < INT_MIN)
	{
		std::cout << "Error: Result overflow after multiplication!" << std::endl;
		return Fixed(0);
	}
	result.setRawBits(static_cast<int>(final_result));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	if (other._value == 0)
	{
		std::cout << "Error: Division by zero!" << std::endl;
		return Fixed(0);
	}
	Fixed result;
	long long temp = static_cast<long long>(this->_value) * (1LL << _bits); // x256
	long long final_result = temp / other._value;

	if (final_result > INT_MAX || final_result < INT_MIN)
	{
		std::cout << "Error: Result overflow after division!" << std::endl;
		return Fixed(0);
	}
	result.setRawBits(static_cast<int>(final_result));
	return result;
}

Fixed& Fixed::operator++()
{
	++this->_value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++this->_value;
	return old;
}

Fixed& Fixed::operator--()
{
	--this->_value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--this->_value;
	return old;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	return b;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	float value = fixed.toFloat();
	out << value;
	return out;
}