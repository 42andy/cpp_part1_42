#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	private:
		unsigned int _capacity;
		std::vector<int> _data;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int value);

		template<typename Iterator>
		void addRange(Iterator first, Iterator last);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};

#include "Span.tpp"

#endif
