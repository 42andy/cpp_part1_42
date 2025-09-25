#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate()
{
	static int i = 0;
	switch (i++ % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
		return;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
		return;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
		return;
	}
	std::cout << "Type inconnu" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (...)
			{
				std::cout << "Type inconnu" << std::endl;
			}
		}
	}
}

int main()
{
	Base* o1 = generate();
	Base* o2 = generate();
	Base* o3 = generate();

	std::cout << "\nIdentification avec pointeurs :" << std::endl;
	std::cout << "objet 1 : ";
	identify(o1);
	std::cout << "objet 2 : ";
	identify(o2);
	std::cout << "objet 3 : ";
	identify(o3);

	std::cout << "\nIdentification avec references :" << std::endl;
	std::cout << "objet 1 : ";
	identify(*o1);
	std::cout << "objet 2 : ";
	identify(*o2);
	std::cout << "objet 3 : ";
	identify(*o3);

	delete o1;
	delete o2;
	delete o3;
	
	return 0;
}
