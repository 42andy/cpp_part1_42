#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <stack>

int main(void)
{

	std::cout << "Test sujet :" << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Sommet de la stack : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Sommet de la stack apres pop : " << mstack.top() << std::endl;
	std::cout << "Taille de la stack apres pop : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "\nTest iteration sur la stack :" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "it avant ++ : " << *it << std::endl;
	++it;
	std::cout << "it apres ++ : " << *it << std::endl;
	--it;
	std::cout << "it apres -- : " << *it << std::endl;
	
	std::cout << "\nContenu de la stack :" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "\nTest avec std::stack :" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "std::stack cree depuis MutantStack, taille : " << s.size() << std::endl;

	std::cout << "\nComparaison avec std::list :" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Sommet de la list : " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Sommet de la list apres pop : " << lst.back() << std::endl;
	std::cout << "Taille de la list apres pop : " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::cout << "\nContenu de la list :" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;

	return 0;
}
