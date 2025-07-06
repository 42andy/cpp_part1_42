#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(const Contact& newContact)
{
	contacts[contactCount % MAX_CONTACTS] = newContact;
	contactCount++;
}

bool PhoneBook::displayContacts() const
{
	if (contactCount == 0)
	{
		std::cout << "No contacts available yet. Please ADD some contacts first." << std::endl;
		return false;
	}
	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First Name" << "|"
			  << std::setw(10) << "Last Name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	int maxToDisplay;
	if (contactCount < MAX_CONTACTS)
		maxToDisplay = contactCount;
	else
		maxToDisplay = MAX_CONTACTS;

	for (int i = 0; i < maxToDisplay; ++i) 
	{
		std::cout << std::setw(10) << i << "|";

		std::string firstName = contacts[i].getFirstName();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		std::cout << std::setw(10) << firstName << "|";

		std::string lastName = contacts[i].getLastName();
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		std::cout << std::setw(10) << lastName << "|";

		std::string nickname = contacts[i].getNickname();
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << nickname << std::endl;
	}
	return true;
}

bool	PhoneBook::displayContactDetails(int index) const
{
	if (index < 0 || index >= contactCount || index >= MAX_CONTACTS)
	{
		std::cout << "Error : invalid index." << std::endl;
		return false;
	}

	std::cout << "First Name : " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name : " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname : " << contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number : " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " << contacts[index].getDarkestSecret() << std::endl;

	return true;
}