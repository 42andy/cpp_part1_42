```#include "Fixed.hpp"
#include <iostream>

 int	main( void )
 {
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

// Provided Main Tests:
	/*
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	*/

// Provided Main Tests with Prints:
	std::cout << "### a: " << a << std::endl;
	std::cout << "### ++a: " << ++a << std::endl;
	std::cout << "### a: " << a << std::endl;
	std::cout << "### a++: " << a++ << std::endl;
	std::cout << "### a: " << a << std::endl;
	
	std::cout << "### b: " << b << std::endl;

	std::cout << "### max of a and b: " << Fixed::max( a, b ) << std::endl;
	
// Extra Tests for Completeness
	Fixed	c( 1.5f );
	Fixed	d( 2 );

	std::cout << "### c: " << c << std::endl;
	std::cout << "### d: " << d << std::endl;

	// Comparison operators
	std::cout << "### c <  d: "  << (c <  d) << std::endl;
	std::cout << "### c >  d: "  << (c >  d) << std::endl;
	std::cout << "### c <= d: "  << (c <= d) << std::endl;
	std::cout << "### c >= d: "  << (c >= d) << std::endl;
	std::cout << "### c == d: "  << (c == d) << std::endl;
	std::cout << "### c != d: "  << (c != d) << std::endl;

	// Arithmetic operators
	std::cout << "### c + d: " << c + d << std::endl;
	std::cout << "### d - c: " << d - c << std::endl;
	std::cout << "### c * d: " << c * d << std::endl;
	std::cout << "### d / c: " << d / c << std::endl;

	// Pre- and post-decrement
	Fixed			e( 0.25f );		// 0.25
	std::cout << "### e: "   << e   << std::endl;
	std::cout << "### --e: " << --e << std::endl;	// pre
	std::cout << "### e--: " << e-- << std::endl;	// post (returns old)
	std::cout << "### e: "   << e   << std::endl;

	// Min/Max helpers
	std::cout << "### min of c and d: " << Fixed::min( c, d ) << std::endl;
	std::cout << "### max of c and d: " << Fixed::max( c, d ) << std::endl;

	// Const overloads
	const Fixed		fc( 3 );
	const Fixed		fd( 3.25f );
	std::cout << "### const-min of fc and fd: " << Fixed::min( fc, fd ) << std::endl;
	std::cout << "### const-max of fc and fd: " << Fixed::max( fc, fd ) << std::endl;

	return 0;
}```