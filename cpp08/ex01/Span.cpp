#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <climits>


Span::Span(unsigned int n) : _capacity(n), _data() {}

Span::Span(const Span &other) : _capacity(other._capacity), _data(other._data) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_data = other._data;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int value)
{
	if (_data.size() >= _capacity)
		throw std::runtime_error("full");
	_data.push_back(value);
}

unsigned int Span::shortestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("no span");

	std::vector<int> tmp(_data);

	std::sort(tmp.begin(), tmp.end());

	unsigned int minSpan = UINT_MAX;
	
	for (std::vector<int>::size_type i = 1; i < tmp.size(); ++i)
	{
		unsigned int diff = static_cast<unsigned int>(tmp[i] - tmp[i - 1]);

		if (diff < minSpan)
			minSpan = diff;
	}
	
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (_data.size() < 2)
		throw std::runtime_error("no span");

	std::vector<int>::const_iterator minIt = std::min_element(_data.begin(), _data.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_data.begin(), _data.end());

	return static_cast<unsigned int>(*maxIt - *minIt);
}
