#include <iostream>
#include <vector>
#include "Span.hpp"

int main(void)
{
	std::cout << "Test sujet :" << std::endl;
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span : " << sp.longestSpan() << std::endl;

	std::cout << "\nTest exception (1 seul element) :" << std::endl;
	try
	{
		Span small(1);
		small.addNumber(42);
		small.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception attrapee : " << e.what() << std::endl;
	}

	std::cout << "\nTest 10000 elements :" << std::endl;
	try
	{
		Span big(10000);

		std::vector<int> v;
		for (int i = 0; i < 10000; i++)
			v.push_back(i);

		std::cout << "Ajout de 10000 elements avec addRange :" << std::endl;
		big.addRange(v.begin(), v.end());

		std::cout << "Shortest span : " << big.shortestSpan() << std::endl;
		std::cout << "Longest span : " << big.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Erreur dans le test de performance : " << e.what() << std::endl;
	}

	std::cout << "\nTest depassement de capacite :" << std::endl;
	try
	{
		Span tiny(2);
		tiny.addNumber(1);
		tiny.addNumber(2);
		tiny.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception capacite attrapee : " << e.what() << std::endl;
	}

	return 0;
}
