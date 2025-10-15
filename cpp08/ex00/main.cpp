#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::cout << "Tests avec vector :" << std::endl;
	std::vector<int> v;

	for (int i = 0; i < 5; i++)
		v.push_back(i * 10);

	std::cout << "Contenu du vector : ";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << "Found : " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}

	try
	{
		easyfind(v, 42);
		std::cout << "Found : 42" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}

	std::cout << "\nTests avec list :" << std::endl;
	std::list<int> l;

	for (int i = 1; i <= 5; i++)
		l.push_back(i);

	std::cout << "Contenu de la list : ";
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	try
	{
		std::list<int>::iterator it2 = easyfind(l, 3);
		std::cout << "Found : " << *it2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}

	try
	{
		easyfind(l, 99);
		std::cout << "Found : 99" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "not found" << std::endl;
	}

	return 0;
}
