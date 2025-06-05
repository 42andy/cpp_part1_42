#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:

		static const int	MAX_CONTACTS = 8;
		Contact	contacts[MAX_CONTACTS];
		int		contactCount;

	public:

		PhoneBook();

		void	addContact(const Contact& newContact);
		bool	displayContacts() const;
		bool	displayContactDetails(int index) const;

};

#endif