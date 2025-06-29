#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <file> <s1> <s2>" << std::endl;
		return 1;
	}

	// Ouverture du fichier d'entrée
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
	{
		std::cerr << "Error : cannot open file " << argv[1] << std::endl;
		return 1;
	}

	// Lecture complète du fichier
	std::string data((std::istreambuf_iterator<char>(inputFile)),
						std::istreambuf_iterator<char>());
	inputFile.close();

	const std::string oldText = argv[2];
	const std::string newText = argv[3];
	if (oldText.empty())
	{
		std::cerr << "Error : <s1> cannot be empty" << std::endl;
		return 1;
	}

	// Remplacement de tous les oldText par newText
	std::string result;
	std::size_t pos = 0; // Position actuelle dans le texte
	std::size_t found = 0; // Position où on trouve oldTExt

	while ((found = data.find(oldText, pos)) != std::string::npos)
	{
		// Ajouter le texte AVANT la chaîne trouvée
		result += data.substr(pos, found - pos);
		// Ajouter newText à la place de oldText
		result += newText;
		// Avancer la position APRÈS la chaîne trouvée
		pos = found + oldText.length();
	}

	// Ajouter le reste du texte (après la dernière occurrence)
	result += data.substr(pos);

	// Création du fichier de sortie
	std::string outName = std::string(argv[1]) + ".replace";
	std::ofstream outputFile(outName.c_str());
	if (!outputFile)
	{
		std::cerr << "Error: cannot create output file" << std::endl;
		return 1;
	}

	// Écriture du contenu modifié
	outputFile << result;
	outputFile.close();

	std::cout << "File processed : " << outName << std::endl;
	return 0;
}
