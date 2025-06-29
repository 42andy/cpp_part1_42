#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	private :

		std::string _name;
		Weapon* _weapon; // peut etre null

	public :
		// Constructeur, peut creer un humain sans arme, weapon init a null
		HumanB(std::string name);
		// peut assigner une arme plus tard
		void setWeapon(Weapon &weapon);
		// attaque uniquement si il a une arme
		void attack(void);
};

#endif
