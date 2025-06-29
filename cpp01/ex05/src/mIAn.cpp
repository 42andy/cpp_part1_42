#include "Harl.hpp"
#include <iostream>

int main()
{
	std::cout << "=== EXERCICE 05: Harl 2.0 ===\n" << std::endl;
	
	std::cout << "📋 Démonstration du système de plaintes de Harl" << std::endl;
	std::cout << "Test des 4 niveaux de log avec pointeurs sur fonctions membres\n" << std::endl;
	
	Harl harl;
	
	std::cout << "🤖 Création d'une instance de Harl\n" << std::endl;
	
	// Test 1: Niveau DEBUG
	std::cout << "🔧 TEST 1: Niveau DEBUG" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	harl.complain("DEBUG");
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 2: Niveau INFO
	std::cout << "\n📝 TEST 2: Niveau INFO" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	harl.complain("INFO");
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 3: Niveau WARNING
	std::cout << "\n⚠️  TEST 3: Niveau WARNING" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	harl.complain("WARNING");
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 4: Niveau ERROR
	std::cout << "\n❌ TEST 4: Niveau ERROR" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	harl.complain("ERROR");
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 5: Niveaux invalides
	std::cout << "\n🚫 TEST 5: Gestion des niveaux invalides" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	
	std::cout << "Test avec niveau vide:" << std::endl;
	harl.complain("");
	
	std::cout << "\nTest avec niveau inexistant 'CRITICAL':" << std::endl;
	harl.complain("CRITICAL");
	
	std::cout << "\nTest avec niveau en minuscules 'debug':" << std::endl;
	harl.complain("debug");
	
	std::cout << "\nTest avec niveau mixte 'Warning':" << std::endl;
	harl.complain("Warning");
	
	std::cout << "\nTest avec niveau invalide 'INVALID':" << std::endl;
	harl.complain("INVALID");
	
	std::cout << "\n" << std::string(50, '=') << std::endl;
	
	// Test 6: Démonstration en séquence
	std::cout << "\n🔄 TEST 6: Séquence complète de plaintes" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	std::cout << "Harl va se plaindre dans l'ordre croissant de sévérité...\n" << std::endl;
	
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << ">>> Niveau " << levels[i] << " <<<" << std::endl;
		harl.complain(levels[i]);
		std::cout << std::endl;
	}
	
	std::cout << std::string(50, '=') << std::endl;
	
	// Test 7: Test de performance avec répétitions
	std::cout << "\n⏱️  TEST 7: Test de répétitions" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	std::cout << "Test de 3 plaintes consécutives du même niveau...\n" << std::endl;
	
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Plainte #" << i + 1 << ":" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
	}
	
	std::cout << std::string(50, '=') << std::endl;
	
	// Test 8: Simulation d'un scénario réaliste
	std::cout << "\n🎭 TEST 8: Simulation d'un scénario réaliste" << std::endl;
	std::cout << std::string(40, '-') << std::endl;
	std::cout << "Simulation d'un débogage d'application...\n" << std::endl;
	
	std::cout << "Démarrage de l'application..." << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	
	std::cout << "Connexion utilisateur..." << std::endl;
	harl.complain("INFO");
	std::cout << std::endl;
	
	std::cout << "Mémoire faible détectée..." << std::endl;
	harl.complain("WARNING");
	std::cout << std::endl;
	
	std::cout << "Échec de connexion à la base de données..." << std::endl;
	harl.complain("ERROR");
	std::cout << std::endl;
	
	std::cout << "Fin de la simulation." << std::endl;
	
	std::cout << "\n✅ Tous les tests terminés avec succès!" << std::endl;
	std::cout << "\n💡 Enseignements clés:" << std::endl;
	std::cout << "   🔹 Utilisation de pointeurs sur fonctions membres" << std::endl;
	std::cout << "   🔹 Système de logging avec niveaux de sévérité" << std::endl;
	std::cout << "   🔹 Gestion robuste des entrées invalides" << std::endl;
	std::cout << "   🔹 Encapsulation des méthodes privées" << std::endl;
	std::cout << "   🔹 Interface publique simple et claire (complain)" << std::endl;
	
	return 0;
}
