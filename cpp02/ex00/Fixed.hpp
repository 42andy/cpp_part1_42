#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private :

		int _value;					// Valeur en format fixed-point
		static const int _bits = 8;	// Nombre de bits pour la partie fractionnaire

	public :

		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
