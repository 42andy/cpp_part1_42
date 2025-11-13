#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _v(other._v), _d(other._d) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_v = other._v;
		_d = other._d;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::parse(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string s(av[i]);

		// Verifier que la chaine n'est pas vide
		if (s.empty())
			return false;

		// Verifier que ce sont uniquement des chiffres (pas de signe -)
		for (size_t j = 0; j < s.size(); j++)
		{
			if (!isdigit(s[j]))
				return false;
		}

		std::istringstream iss(s);
		long n;
		iss >> n;

		// Verifier overflow et que c'est un entier positif
		if (iss.fail() || n < 0 || n > 2147483647)
			return false;

		// Verifier les doublons
		for (size_t j = 0; j < _v.size(); j++)
		{
			if (_v[j] == static_cast<int>(n))
				return false;
		}

		_v.push_back(static_cast<int>(n));
		_d.push_back(static_cast<int>(n));
	}
	
	return true;
}

// Etape 3-5: Tri recursif Ford-Johnson pour vector
static std::vector<int> fordJohnsonSortVec(std::vector<int> input)
{
	// Cas de base
	if (input.size() <= 1)
		return input;

	std::vector<int> big;
	std::vector<int> small;
	
	// Etape 1-2: Grouper en paires et comparer
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			big.push_back(input[i + 1]);
			small.push_back(input[i]);
		}
		else
		{
			big.push_back(input[i]);
			small.push_back(input[i + 1]);
		}
	}

	// Gerer element impair
	int odd = -1;
	bool hasOdd = (input.size() % 2 != 0);
	if (hasOdd)
		odd = input[input.size() - 1];

	// Etape 3: Trier recursivement les grands elements
	std::vector<int> S = fordJohnsonSortVec(big);

	// Etape 4-5: Inserer les petits avec binary search
	for (size_t i = 0; i < small.size(); i++)
	{
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), small[i]);
		S.insert(it, small[i]);
	}

	// Inserer l'element impair
	if (hasOdd)
	{
		std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), odd);
		S.insert(it, odd);
	}

	return S;
}

// Etape 3-5: Tri recursif Ford-Johnson pour deque
static std::deque<int> fordJohnsonSortDeq(std::deque<int> input)
{
	// Cas de base
	if (input.size() <= 1)
		return input;

	std::deque<int> big;
	std::deque<int> small;
	
	// Etape 1-2: Grouper en paires et comparer
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] < input[i + 1])
		{
			big.push_back(input[i + 1]);
			small.push_back(input[i]);
		}
		else
		{
			big.push_back(input[i]);
			small.push_back(input[i + 1]);
		}
	}

	// Gerer element impair
	int odd = -1;
	bool hasOdd = (input.size() % 2 != 0);
	if (hasOdd)
		odd = input[input.size() - 1];

	// Etape 3: Trier recursivement les grands elements
	std::deque<int> S = fordJohnsonSortDeq(big);

	// Etape 4-5: Inserer les petits avec binary search
	for (size_t i = 0; i < small.size(); i++)
	{
		std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), small[i]);
		S.insert(it, small[i]);
	}

	// Inserer l'element impair
	if (hasOdd)
	{
		std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), odd);
		S.insert(it, odd);
	}

	return S;
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
	
	clock_t startV = clock();
	_v = fordJohnsonSortVec(_v);
	clock_t endV = clock();

	clock_t startD = clock();
	_d = fordJohnsonSortDeq(_d);
	clock_t endD = clock();

	std::cout << "After:  ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;

	double durV = (double)(endV - startV) * 1000000.0 / CLOCKS_PER_SEC;
	double durD = (double)(endD - startD) * 1000000.0 / CLOCKS_PER_SEC;
	
	std::cout << "Time to process a range of " << _v.size() 
			  << " elements with std::vector : " << durV << " us" << std::endl;
	std::cout << "Time to process a range of " << _d.size() 
			  << " elements with std::deque  : " << durD << " us" << std::endl;
}

