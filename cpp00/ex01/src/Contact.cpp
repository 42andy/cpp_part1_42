#include "Contact.hpp"

void Contact::setFirstName(const std::string& content)
{
	firstName = content;
}

void Contact::setLastName(const std::string& content)
{
	lastName = content;
}

void Contact::setNickname(const std::string& content)
{
	nickname = content;
}

void Contact::setPhoneNumber(const std::string& content)
{
	phoneNumber = content;
}

void Contact::setDarkestSecret(const std::string& content)
{
	darkestSecret = content;
}

std::string Contact::getFirstName() const
{
	return firstName;
}

std::string Contact::getLastName() const
{
	return lastName;
}

std::string Contact::getNickname() const
{
	return nickname;
}

std::string Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return darkestSecret;
}
