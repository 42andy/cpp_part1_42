#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
	private :
		// Fonctions membres privees
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public :
		// Interface publique : utilise les pointeurs sur fonctions membres
		void complain(std::string level);
};

#endif
