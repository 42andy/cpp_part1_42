#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private :

		std::string _name;

	public :
		// Constructeur : initialise un zombie avec un nom donné
		Zombie(std::string name);
		
		// Destructeur : appelé quand le zombie est détruit
		// HEAP (destruction manuelle avec delete)
		// STACK (destruction automatique en fin de scope)
		~Zombie();

		// Fonction d'annonce : le zombie révèle sa présence
		void announce(void);
};

#endif