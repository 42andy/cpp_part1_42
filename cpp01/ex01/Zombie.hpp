#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private :

		std::string _name;

	public :
		// Constructeur par défaut : crée un zombie sans nom
		Zombie();
		
		// Constructeur paramétré : crée un zombie avec un nom donné
		Zombie(std::string name);
		
		// Destructeur : affiche quand le zombie est détruit
		~Zombie();

		// Setter : assigne un nom à un zombie existant
		void setName(std::string name);
		
		// Fonction d'annonce : le zombie révèle sa présence
		void announce(void);
};
#endif
