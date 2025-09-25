#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "Tests Intern :" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		std::cout << "Création des formulaires :" << std::endl;
		AForm* form1 = intern.makeForm("shrubbery creation", "garden");
		AForm* form2 = intern.makeForm("robotomy request", "Bender");
		AForm* form3 = intern.makeForm("presidential pardon", "Arthur");
		std::cout << std::endl;

		if (form1)
		{
			std::cout << *form1 << std::endl;
			boss.signForm(*form1);
			boss.executeForm(*form1);
			delete form1;
		}
		std::cout << std::endl;

		if (form2)
		{
			std::cout << *form2 << std::endl;
			boss.signForm(*form2);
			boss.executeForm(*form2);
			delete form2;
		}
		std::cout << std::endl;

		if (form3)
		{
			std::cout << *form3 << std::endl;
			boss.signForm(*form3);
			boss.executeForm(*form3);
			delete form3;
		}

		std::cout << "\nTest formulaire inexistant :" << std::endl;
		try
		{
			AForm* invalidForm = intern.makeForm("invalid form", "target");
			if (invalidForm)
			delete invalidForm;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}

		std::cout << "\nExemple du sujet :" << std::endl;
		Intern someRandomIntern;
		AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << *rrf << std::endl;
			delete rrf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception : " << e.what() << std::endl;
	}
	
	return 0;
}
