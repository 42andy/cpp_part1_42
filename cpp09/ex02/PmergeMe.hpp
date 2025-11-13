#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <ctime>

class PmergeMe
{
	private:
		std::vector<int> _v;
		std::deque<int> _d;

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		bool parse(int ac, char **av);
		void run();
};

#endif
