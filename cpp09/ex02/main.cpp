#include "PmergeMe.hpp"
#include <iostream>


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	PmergeMe p;

	if (!p.parse(ac, av))
	{
		std::cout << "Error" << std::endl;
		return 1;
	}

	p.run();

	return 0;
}

