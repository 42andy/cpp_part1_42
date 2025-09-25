#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Tests Bureaucrat et Form :" << std::endl;

	try
	{
		Form form1("Tax Form", 50, 25);
		Form form2("Permit", 10, 5);
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;

		Bureaucrat bob("Bob", 40);
		Bureaucrat alice("Alice", 60);
		std::cout << bob << std::endl;
		std::cout << alice << std::endl;

		std::cout << "\nTest signature réussie :" << std::endl;
		bob.signForm(form1);
		std::cout << form1 << std::endl;

		std::cout << "\nTest signature échouée :" << std::endl;
		alice.signForm(form1);
		alice.signForm(form2);
		bob.signForm(form2);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "\nTest création form invalide :" << std::endl;
		Form invalidForm("Invalid", 0, 50);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception création form grade 0 : " << e.what() << std::endl;
	}

	try
	{
		Form invalidForm2("Invalid2", 50, 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception création form grade 151 : " << e.what() << std::endl;
	}

	return 0;
}
