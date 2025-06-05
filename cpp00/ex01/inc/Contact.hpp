#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:

		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:

		void	setFirstName(const std::string& content);
		void	setLastName(const std::string& content);
		void	setNickname(const std::string& content);
		void	setPhoneNumber(const std::string& content);
		void	setDarkestSecret(const std::string& content);

		std::string	getFirstName() const;
		std::string	getLastName() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
};

#endif