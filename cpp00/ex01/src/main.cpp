#include <iostream>
#include <string>
#include <cstdlib>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static Contact createContact()
{
	Contact newContact;
	std::string input;

	const std::string prompts[5] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest Secret"
	};

	for (int i = 0; i < 5; i++)
	{
		while(true)
		{
			std::cout << prompts[i] << " : ";
			std::getline(std::cin, input);

			if (std::cin.eof())
			{
				std::cout << std::endl << "End of input detected. Exiting program." << std::endl;
				std::exit(0);
			}

			if (input.empty())
			{
				std::cout << "Field cannot be empty. Please try again." << std::endl;
				continue;
			}

			if (i == 0)
				newContact.setFirstName(input);
			else if (i == 1)
				newContact.setLastName(input);
			else if (i == 2)
				newContact.setNickname(input);
			else if (i == 3)
				newContact.setPhoneNumber(input);
			else if (i == 4)
				newContact.setDarkestSecret(input);
			break;
		}
	}
	return newContact;
}

int	main()
{
	PhoneBook	phoneBook;
	std::string	command;

	std::cout << "Welcome to the PhoneBook !" << std::endl;
	std::cout << "Available commands : ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "Enter a command : ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << std::endl << "End of input detected. Exiting program." << std::endl;
			return 0;
		}

		if (command == "ADD")
		{
			std::cout << "Please fill in the contact's details below." << std::endl;
			Contact newContact = createContact();
			phoneBook.addContact(newContact);
			std::cout << "New contact added." << std::endl;
		}

		else if (command == "SEARCH")
		{
			if (!phoneBook.displayContacts())
				continue;

			while (true)
			{
				std::cout << "Enter the index of the contact to display  : ";
				int	index;
				std::cin >> index;

				if (std::cin.eof())
				{
					std::cout << std::endl << "End of input detected. Exiting program." << std::endl;
					return 0;
				}

				if (std::cin.fail())
				{
					std::cout << "Error : invalid index." << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n');
					continue;
				}
				std::cin.ignore(100, '\n');

				if (phoneBook.displayContactDetails(index))
					break;
			}
		}
		else if (command == "EXIT")
		{
			std::cout << "Goodbye !" << std::endl;
			break;
		}
		else
			std::cout << "Error : please use ADD, SEARCH or EXIT." << std::endl;
	}
	return 0;
}
