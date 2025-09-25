#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "Tests des formes concrètes :" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		Bureaucrat bob("Bob", 50);
		Bureaucrat charlie("Charlie", 140);
		std::cout << alice << std::endl << bob << std::endl << charlie << std::endl;

		std::cout << "\nTest ShrubberyCreationForm :" << std::endl;
		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;
		charlie.signForm(shrubbery); // ok signer
		bob.executeForm(shrubbery);  // ok exec

		std::cout << "\nTest RobotomyRequestForm :" << std::endl;
		RobotomyRequestForm robotomy("Ben");
		std::cout << robotomy << std::endl;
		bob.signForm(robotomy);
		bob.executeForm(robotomy);

		std::cout << "\nTest PresidentialPardonForm :" << std::endl;
		PresidentialPardonForm pardon("Arthur");
		std::cout << pardon << std::endl;
		alice.signForm(pardon);
		alice.executeForm(pardon);

		std::cout << "\nTests d'échecs :" << std::endl;
		PresidentialPardonForm pardon2("Danny");
		alice.executeForm(pardon2);      // pas signé
		charlie.signForm(pardon2);       // grade trop bas
		alice.signForm(pardon2);         // maintenant signé
		bob.executeForm(pardon2);        // grade exec trop bas
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
