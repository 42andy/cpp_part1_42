#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool isChar(const std::string& input)
{
	if (input.length() != 3)
		return false;
	if (input[0] != '\'')
		return false;
	if (input[2] != '\'')
		return false;
	return true;
}

static bool isInt(const std::string& input)
{
	if (input.empty())
		return false;
	size_t start = 0;
	if (input[0] == '+' || input[0] == '-')
		start = 1;
	if (start == input.length())
		return false;
	for (size_t i = start; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

static bool isFloat(const std::string& input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf")
		return true;

	if (input.length() < 2 || input[input.length() - 1] != 'f')
		return false;

	std::string temp = input.substr(0, input.length() - 1);

	size_t start = 0;
	size_t dotCount = 0;
	bool hasDigit = false;

	if (temp[0] == '+' || temp[0] == '-')
		start = 1;

	for (size_t i = start; i < temp.length(); i++)
	{
		if (temp[i] == '.')
			dotCount++;
		else if (std::isdigit(temp[i]))
			hasDigit = true;
		else
			return false;
	}

	if (dotCount != 1)
		return false;
	if (!hasDigit)
		return false;

	return true;
}

static bool isDouble(const std::string& input)
{
	if (input == "-inf" || input == "+inf" || input == "nan")
		return true;

	size_t start = 0;
	size_t dotCount = 0;
	bool hasDigit = false;

	if (input[0] == '+' || input[0] == '-')
		start = 1;

	for (size_t i = start; i < input.length(); i++)
	{
		if (input[i] == '.')
			dotCount++;
		else if (std::isdigit(input[i]))
			hasDigit = true;
		else
			return false;
	}

	if (dotCount != 1)
		return false;
	if (!hasDigit)
		return false;

	return true;
}

static void printChar(double value)
{
	std::cout << "char : ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (value < 32 || value == 127)
		std::cout << "non affichable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value)
{
	std::cout << "int : ";

	if (std::isnan(value) || std::isinf(value))
		std::cout << "impossible" << std::endl;
	else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value)
{
	std::cout << "float : ";

	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	}
	else
	{
		float f = static_cast<float>(value);

		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
}

static void printDouble(double value)
{
	std::cout << "double : ";

	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (std::isinf(value))
	{
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	}
	else
	{
		std::cout << value;
		if (value == static_cast<int>(value))
			std::cout << ".0";
		std::cout << std::endl;
	}
}

void ScalarConverter::convert(const std::string& input)
{
	double value = 0.0;
	bool valid = true;

	if (isChar(input))
		value = static_cast<double>(input[1]);
	else if (isInt(input))
	{
		std::stringstream ss(input);
		long longValue;
		ss >> longValue;

		if (longValue < std::numeric_limits<int>::min() || longValue > std::numeric_limits<int>::max())
			valid = false;
		else
			value = static_cast<double>(longValue);
	}
	else if (isFloat(input))
	{
		if (input == "nanf")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inff")
			value = std::numeric_limits<double>::infinity();
		else if (input == "-inff")
			value = -std::numeric_limits<double>::infinity();
		else
		{
			std::stringstream ss(input);
			float floatValue;
			ss >> floatValue;
			value = static_cast<double>(floatValue);
		}
	}
	else if (isDouble(input))
	{
		if (input == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inf")
			value = std::numeric_limits<double>::infinity();
		else if (input == "-inf")
			value = -std::numeric_limits<double>::infinity();
		else
		{
			std::stringstream ss(input);
			double dv;
			ss >> dv;
			value = dv;
		}
	}
	else
		valid = false;

	if (!valid)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
