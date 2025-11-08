#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	if (!btc.loadData("data.csv"))
	{
		std::cout << "Error: cannot load data." << std::endl;
		return 1;
	}

	btc.processInput(av[1]);
	return 0;
}
