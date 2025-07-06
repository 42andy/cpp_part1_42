#include "Contact.hpp"

void Contact::setFirstName(const std::string& content)
{
	_firstName = content;
}

void Contact::setLastName(const std::string& content)
{
	_lastName = content;
}

void Contact::setNickname(const std::string& content)
{
	_nickname = content;
}

void Contact::setPhoneNumber(const std::string& content)
{
	_phoneNumber = content;
}

void Contact::setDarkestSecret(const std::string& content)
{
	_darkestSecret = content;
}

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}
