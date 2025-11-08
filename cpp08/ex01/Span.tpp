#include <iterator>

/*
template<typename Iterator>
void Span::addRange(Iterator first, Iterator last)
{
	while (first != last)
	{
		addNumber(*first);  // Appel à addNumber pour chaque élément
		++first;
	}
}
*/

template<typename Iterator>
void Span::addRange(Iterator first, Iterator last)
{
	if (std::distance(first, last) + _data.size() > _capacity)
		throw NotEnoughCapacityException();
	_data.insert(_data.end(), first, last);
}
