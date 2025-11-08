#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_rates = other._rates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool validDate(const std::string &d)
{
	if (d.size() != 10 || d[4] != '-' || d[7] != '-')
		return false;

	for (size_t i = 0; i < d.size(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(d[i]))
			return false;
	}

	int y = ::atoi(d.substr(0, 4).c_str());
	int m = ::atoi(d.substr(5, 2).c_str());
	int day = ::atoi(d.substr(8, 2).c_str());

	if (m < 1 || m > 12)
		return false;

	int mdays = 31;

	if (m == 4 || m == 6 || m == 9 || m == 11)
		mdays = 30;

	else if (m == 2)
	{
		bool leap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
		mdays = leap ? 29 : 28;
	}

	if (day < 1 || day > mdays)
		return false;
	
	return true;
}

static bool parseLine(const std::string &line, std::string &date, double &value, char sep)
{
	std::istringstream iss(line);

	if (!std::getline(iss, date, sep))
		return false;

	std::string valStr;
	if (!std::getline(iss, valStr))
		return false;
	

	while (date.size() && (date[0] == ' ' || date[0] == '\t'))
		date.erase(0, 1);

	while (date.size() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
		date.erase(date.size() - 1);

	while (valStr.size() && (valStr[0] == ' ' || valStr[0] == '\t'))
		valStr.erase(0, 1);

	while (valStr.size() && (valStr[valStr.size() - 1] == ' ' || valStr[valStr.size() - 1] == '\t'))
		valStr.erase(valStr.size() - 1);

	std::istringstream vs(valStr);
	vs >> value;

	if (vs.fail())
		return false;
	
	return true;
}

bool BitcoinExchange::loadData(const std::string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		return false;

	std::string line;
	if (!std::getline(file, line))
		return false;

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string d;
		double v;
		if (!parseLine(line, d, v, ','))
			continue;

		if (!validDate(d))
			continue;

		_rates[d] = v;
	}
	
	return true;
}

void BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cout << "Error: cannot open file." << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string d;
		double v;
		if (!parseLine(line, d, v, '|') || !validDate(d))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (v < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}

		if (v > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it = _rates.lower_bound(d);

		if (it == _rates.end() || it->first != d)
		{
			if (it == _rates.begin())
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			--it;
		}

		std::cout << d << " => " << v << " = " << (v * it->second) << std::endl;
	}
}

