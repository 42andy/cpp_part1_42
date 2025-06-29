#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	std::cout << "=== EXERCICE 03: Unnecessary violence ===\n" << std::endl;
	
	std::cout << "📋 Démonstration des différences entre références et pointeurs" << std::endl;
	std::cout << "HumanA utilise une RÉFÉRENCE, HumanB utilise un POINTEUR\n" << std::endl;
	
	// Test 1: HumanA avec référence
	std::cout << "🗡️  TEST 1: HumanA (utilise une référence vers Weapon)" << std::endl;
	std::cout << std::string(55, '-') << std::endl;
	{
		std::cout << "Création d'une arme 'crude spiked club'" << std::endl;
		Weapon club("crude spiked club");
		
		std::cout << "Création de Bob (HumanA) avec cette arme" << std::endl;
		HumanA bob("Bob", club);
		
		std::cout << "\nBob attaque avec son arme:" << std::endl;
		bob.attack();
		
		std::cout << "\nChangement du type d'arme en 'some other type of club'" << std::endl;
		club.setType("some other type of club");
		
		std::cout << "Bob attaque à nouveau (l'arme a changé automatiquement):" << std::endl;
		bob.attack();
		
		std::cout << "\n💡 HumanA est toujours armé car il a une RÉFÉRENCE" << std::endl;
		std::cout << "   → La référence ne peut pas être NULL" << std::endl;
		std::cout << "   → L'arme doit exister dès la construction" << std::endl;
	}
	
	std::cout << "\n" << std::string(70, '=') << std::endl;
	
	// Test 2: HumanB avec pointeur
	std::cout << "\n🔫 TEST 2: HumanB (utilise un pointeur vers Weapon)" << std::endl;
	std::cout << std::string(55, '-') << std::endl;
	{
		std::cout << "Création de Jim (HumanB) sans arme" << std::endl;
		HumanB jim("Jim");
		
		std::cout << "\nJim essaie d'attaquer sans arme:" << std::endl;
		jim.attack();
		
		std::cout << "\nCréation d'une arme 'crude spiked club'" << std::endl;
		Weapon club("crude spiked club");
		
		std::cout << "Attribution de l'arme à Jim" << std::endl;
		jim.setWeapon(club);
		
		std::cout << "\nJim attaque maintenant qu'il a une arme:" << std::endl;
		jim.attack();
		
		std::cout << "\nChangement du type d'arme en 'some other type of club'" << std::endl;
		club.setType("some other type of club");
		
		std::cout << "Jim attaque à nouveau (l'arme a changé):" << std::endl;
		jim.attack();
		
		std::cout << "\n💡 HumanB peut être sans arme car il a un POINTEUR" << std::endl;
		std::cout << "   → Le pointeur peut être NULL" << std::endl;
		std::cout << "   → L'arme peut être assignée après la construction" << std::endl;
	}
	
	std::cout << "\n" << std::string(70, '=') << std::endl;
	
	// Test 3: Comparaison avancée
	std::cout << "\n⚔️  TEST 3: Comparaison avancée des comportements" << std::endl;
	std::cout << std::string(55, '-') << std::endl;
	{
		std::cout << "Création de plusieurs armes:" << std::endl;
		Weapon sword("sharp sword");
		Weapon axe("heavy battle axe");
		Weapon bow("elven longbow");
		
		std::cout << "- Épée: " << sword.getType() << std::endl;
		std::cout << "- Hache: " << axe.getType() << std::endl;
		std::cout << "- Arc: " << bow.getType() << std::endl;
		
		std::cout << "\nCréation d'Alice (HumanA) avec l'épée:" << std::endl;
		HumanA alice("Alice", sword);
		alice.attack();
		
		std::cout << "\nCréation de Charlie (HumanB) sans arme:" << std::endl;
		HumanB charlie("Charlie");
		charlie.attack();
		
		std::cout << "\nCharlie prend la hache:" << std::endl;
		charlie.setWeapon(axe);
		charlie.attack();
		
		std::cout << "\nCharlie change pour l'arc:" << std::endl;
		charlie.setWeapon(bow);
		charlie.attack();
		
		std::cout << "\nAlice utilise toujours la même épée (référence fixe):" << std::endl;
		alice.attack();
		
		std::cout << "\nModification de l'épée d'Alice:" << std::endl;
		sword.setType("legendary excalibur");
		alice.attack();
	}
	
	std::cout << "\n" << std::string(70, '=') << std::endl;
	
	// Test 4: Test de scope et durée de vie
	std::cout << "\n🔄 TEST 4: Test de scope et durée de vie" << std::endl;
	std::cout << std::string(55, '-') << std::endl;
	
	Weapon *globalWeapon = new Weapon("global weapon");
	HumanB david("David");
	
	{
		std::cout << "Dans un scope local:" << std::endl;
		Weapon localWeapon("local weapon");
		
		david.setWeapon(localWeapon);
		std::cout << "David utilise l'arme locale:" << std::endl;
		david.attack();
		
		std::cout << "Fin du scope local..." << std::endl;
	}
	
	std::cout << "Après la sortie du scope:" << std::endl;
	std::cout << "David essaie d'attaquer (arme locale détruite):" << std::endl;
	// david.attack(); // Ceci pourrait causer un problème car l'arme locale n'existe plus
	
	std::cout << "Attribution de l'arme globale:" << std::endl;
	david.setWeapon(*globalWeapon);
	david.attack();
	
	delete globalWeapon;
	
	std::cout << "\n✅ Tous les tests terminés avec succès!" << std::endl;
	std::cout << "\n💡 Enseignements clés:" << std::endl;
	std::cout << "   🔹 HumanA (référence): toujours armé, arme fixée à la construction" << std::endl;
	std::cout << "   🔹 HumanB (pointeur): peut être désarmé, arme changeable" << std::endl;
	std::cout << "   🔹 Référence: plus sûre, pas de vérification NULL nécessaire" << std::endl;
	std::cout << "   🔹 Pointeur: plus flexible, mais nécessite des vérifications" << std::endl;
	std::cout << "   🔹 Attention au scope des objets référencés/pointés!" << std::endl;
	
	return 0;
}
