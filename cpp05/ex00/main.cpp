#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Tests Bureaucrat :" << std::endl;

	try
	{
		Bureaucrat bob("Bob", 50);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "Après increment : " << bob << std::endl;
		bob.decrementGrade();
		bob.decrementGrade();
		std::cout << "Après 2 decrements : " << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat alice("Alice", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception création grade 0 : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat charlie("Charlie", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception création grade 151 : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception increment grade 1 : " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception decrement grade 150 : " << e.what() << std::endl;
	}

	return 0;
}
