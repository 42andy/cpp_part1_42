#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else 
	{
		for (int i = 1; i < argc; i++)
		{
			if (i > 1)
				std::cout << ' ';
			for (int j = 0; argv[i][j]; j++)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
		}
	}
	std::cout << std::endl;
	return 0;
}
