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

		for (size_t j = 0; j < s.size(); j++)
		{
			if (!isdigit(s[j]))
				return false;
		}

		std::istringstream iss(s);
		int n;
		iss >> n;

		_v.push_back(n);
		_d.push_back(n);
	}
	
	return true;
}


static void pairInsert(std::vector<int> &v)
{
	for (size_t i = 0; i + 1 < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
			std::swap(v[i], v[i + 1]);
	}
}

static void pairInsert(std::deque<int> &d)
{
	for (size_t i = 0; i + 1 < d.size(); i += 2)
	{
		if (d[i] > d[i + 1])
			std::swap(d[i], d[i + 1]);
	}
}

static void insertion(std::vector<int> &v)
{
	for (size_t i = 1; i < v.size(); i++)
	{
		int key = v[i];
		size_t j = i;

		while (j > 0 && v[j - 1] > key)
		{
			v[j] = v[j - 1];
			j--;
		}

		v[j] = key;
	}
}

static void insertion(std::deque<int> &d)
{
	for (size_t i = 1; i < d.size(); i++)
	{
		int key = d[i];
		size_t j = i;
		while (j > 0 && d[j - 1] > key)
		{
			d[j] = d[j - 1];
			j--;
		}
		d[j] = key;
	}
}


void PmergeMe::fordJohnsonVector()
{
	pairInsert(_v);
	insertion(_v);
}

void PmergeMe::fordJohnsonDeque()
{
	pairInsert(_d);
	insertion(_d);
}

void PmergeMe::run()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
	
	clock_t startV = clock();
	fordJohnsonVector();
	clock_t endV = clock();

	clock_t startD = clock();
	fordJohnsonDeque();
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

