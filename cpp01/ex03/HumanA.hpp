#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	private :

		std::string _name;
		Weapon& _weapon; // toujours valide, ne peut jms etre null

	public :
		// Constructeur, doit obligatoiremetn recevoir une arme dans init list
		HumanA(std::string name, Weapon &weapon);
		// peut toujours attaquer car a une arme des le debut tte facon
		void attack(void);
};

#endif
