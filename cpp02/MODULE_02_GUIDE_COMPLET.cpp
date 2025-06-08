/*
===============================================================================
                    MODULE CPP02 - GUIDE COMPLET AVEC EXEMPLES
===============================================================================

===============================================================================
1. ORTHODOX CANONICAL FORM (FORME CANONIQUE ORTHODOXE)
===============================================================================

QU'EST-CE QUE C'EST ?
La forme canonique orthodoxe est un ensemble de 4 fonctions OBLIGATOIRES que
toute classe C++ bien conçue doit avoir. C'est comme les "règles de base" 
pour créer une classe solide.

POURQUOI C'EST IMPORTANT ?
- Évite les bugs de mémoire
- Permet de copier des objets en sécurité
- Assure un comportement prévisible

LES 4 FONCTIONS OBLIGATOIRES :
*/

class Fixed {
private:
    int _value;                    // Stocke notre nombre en format fixe
    static const int _bits = 8;    // Toujours 8 bits pour la partie décimale

public:
    // 1. CONSTRUCTEUR PAR DÉFAUT
    // Appelé quand on écrit : Fixed a;
    Fixed() : _value(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // 2. CONSTRUCTEUR DE COPIE  
    // Appelé quand on écrit : Fixed b(a); ou Fixed b = a;
    Fixed(const Fixed& other) : _value(other._value) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // 3. OPÉRATEUR D'AFFECTATION DE COPIE
    // Appelé quand on écrit : b = a; (si b existe déjà)
    Fixed& operator=(const Fixed& other) {
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other) {    // Protection contre l'auto-affectation (a = a)
            this->_value = other._value;
        }
        return *this;           // Retourne une référence pour permettre a = b = c
    }

    // 4. DESTRUCTEUR
    // Appelé automatiquement quand l'objet est détruit
    ~Fixed() {
        std::cout << "Destructor called" << std::endl;
    }

/*
===============================================================================
2. CONSTRUCTEURS AVEC PARAMÈTRES
===============================================================================

En plus des 4 fonctions de base, on peut ajouter d'autres constructeurs
pour créer nos objets de différentes manières.
*/

    // CONSTRUCTEUR AVEC UN ENTIER
    // Convertit un entier en nombre fixed-point
    Fixed(const int value) : _value(value << _bits) {
        std::cout << "Int constructor called" << std::endl;
        // Exemple : si value = 42
        // _value = 42 << 8 = 42 * 256 = 10752
        // On décale de 8 bits vers la gauche = multiplication par 256
    }

    // CONSTRUCTEUR AVEC UN FLOAT
    // Convertit un float en nombre fixed-point
    Fixed(const float value) : _value(static_cast<int>(roundf(value * (1 << _bits)))) {
        std::cout << "Float constructor called" << std::endl;
        // Exemple : si value = 42.42f
        // (1 << 8) = 256
        // 42.42 * 256 = 10859.52
        // roundf(10859.52) = 10860
        // _value = 10860
    }

/*
===============================================================================
3. FONCTIONS DE CONVERSION
===============================================================================

Ces fonctions permettent de récupérer notre nombre fixed-point sous forme
d'entier ou de float pour l'afficher ou l'utiliser.
*/

    // CONVERSION VERS FLOAT
    float toFloat(void) const {
        return static_cast<float>(this->_value) / (1 << _bits);
        // Exemple : si _value = 10860
        // 10860 / 256 = 42.421875 ≈ 42.42
    }

    // CONVERSION VERS INT (troncature de la partie décimale)
    int toInt(void) const {
        return this->_value >> _bits;
        // Exemple : si _value = 10860
        // 10860 >> 8 = 10860 / 256 = 42 (partie entière seulement)
    }

    // FONCTIONS D'ACCÈS AUX DONNÉES BRUTES
    int getRawBits(void) const {
        return this->_value;
    }

    void setRawBits(int const raw) {
        this->_value = raw;
    }

/*
===============================================================================
4. SURCHARGE D'OPÉRATEURS DE COMPARAISON
===============================================================================

La surcharge d'opérateurs permet d'utiliser les symboles habituels (+, -, ==, etc.)
avec nos objets personnalisés. C'est comme apprendre à la calculatrice 
comment additionner nos nouveaux nombres !
*/

    // OPÉRATEUR D'ÉGALITÉ (==)
    bool operator==(const Fixed& other) const {
        return this->_value == other._value;
        // Compare directement les valeurs brutes
        // Exemple : Fixed(42) == Fixed(42) retourne true
    }

    // OPÉRATEUR DE DIFFÉRENCE (!=)
    bool operator!=(const Fixed& other) const {
        return this->_value != other._value;
    }

    // OPÉRATEUR INFÉRIEUR (<)
    bool operator<(const Fixed& other) const {
        return this->_value < other._value;
        // Exemple : Fixed(5) < Fixed(10) retourne true
    }

    // OPÉRATEUR SUPÉRIEUR (>)
    bool operator>(const Fixed& other) const {
        return this->_value > other._value;
    }

    // OPÉRATEUR INFÉRIEUR OU ÉGAL (<=)
    bool operator<=(const Fixed& other) const {
        return this->_value <= other._value;
    }

    // OPÉRATEUR SUPÉRIEUR OU ÉGAL (>=)
    bool operator>=(const Fixed& other) const {
        return this->_value >= other._value;
    }

/*
===============================================================================
5. SURCHARGE D'OPÉRATEURS ARITHMÉTIQUES
===============================================================================

Ces opérateurs permettent de faire des calculs mathématiques avec nos nombres.
*/

    // ADDITION (+)
    Fixed operator+(const Fixed& other) const {
        Fixed result;
        result.setRawBits(this->_value + other._value);
        return result;
        // Addition simple des valeurs brutes
        // Le format fixed-point se conserve naturellement
    }

    // SOUSTRACTION (-)
    Fixed operator-(const Fixed& other) const {
        Fixed result;
        result.setRawBits(this->_value - other._value);
        return result;
    }

    // MULTIPLICATION (*)
    Fixed operator*(const Fixed& other) const {
        Fixed result;
        // ATTENTION : Protection contre les débordements !
        // On utilise long long pour éviter que le calcul déborde
        long long temp = static_cast<long long>(this->_value) * other._value;
        result.setRawBits(static_cast<int>(temp >> _bits));
        return result;
        // Pourquoi >> _bits ? 
        // Quand on multiplie deux fixed-point, on a trop de bits fractionnaires
        // Il faut diviser par 2^8 pour retrouver le bon format
    }

    // DIVISION (/)
    Fixed operator/(const Fixed& other) const {
        // PROTECTION CONTRE LA DIVISION PAR ZÉRO
        if (other._value == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return Fixed(0);
        }
        
        Fixed result;
        // Même principe : on utilise long long pour éviter les débordements
        long long temp = static_cast<long long>(this->_value) << _bits;
        result.setRawBits(static_cast<int>(temp / other._value));
        return result;
        // Pourquoi << _bits ?
        // On doit multiplier par 2^8 avant de diviser pour garder la précision
    }

/*
===============================================================================
6. OPÉRATEURS D'INCRÉMENTATION ET DÉCRÉMENTATION
===============================================================================

Ces opérateurs permettent d'augmenter ou diminuer la valeur d'une unité.
Il y a deux versions : pré-incrémentation (++a) et post-incrémentation (a++).
*/

    // PRÉ-INCRÉMENTATION (++a)
    Fixed& operator++() {
        this->_value++;              // Incrémente d'abord
        return *this;                // Retourne la nouvelle valeur
        // Exemple : 
        // Fixed a(5);
        // Fixed b = ++a;  // a devient 5.00390625, b vaut 5.00390625
    }

    // POST-INCRÉMENTATION (a++)
    Fixed operator++(int) {          // Le paramètre 'int' est juste pour différencier
        Fixed temp(*this);           // Sauvegarde l'ancienne valeur
        this->_value++;              // Incrémente après
        return temp;                 // Retourne l'ancienne valeur
        // Exemple :
        // Fixed a(5);
        // Fixed b = a++;  // a devient 5.00390625, b vaut 5
    }

    // PRÉ-DÉCRÉMENTATION (--a)
    Fixed& operator--() {
        this->_value--;
        return *this;
    }

    // POST-DÉCRÉMENTATION (a--)
    Fixed operator--(int) {
        Fixed temp(*this);
        this->_value--;
        return temp;
    }

/*
===============================================================================
7. FONCTIONS STATIQUES MIN/MAX
===============================================================================

Les fonctions statiques appartiennent à la classe, pas à un objet particulier.
On les appelle avec Fixed::min() au lieu de monObjet.min().

POURQUOI DEUX VERSIONS DE CHAQUE ?
- Une pour les objets modifiables (Fixed&)
- Une pour les objets constants (const Fixed&)
*/

    // VERSION NON-CONST : peut modifier les objets
    static Fixed& min(Fixed& a, Fixed& b) {
        if (a < b)
            return a;               // Retourne une référence vers le plus petit
        return b;
        // Exemple : Fixed::min(x, y) = 100;  // On peut modifier le résultat
    }

    // VERSION CONST : ne peut pas modifier les objets
    static const Fixed& min(const Fixed& a, const Fixed& b) {
        if (a < b)
            return a;
        return b;
        // Exemple : const Fixed result = Fixed::min(x, y);  // Lecture seule
    }

    // Même principe pour max
    static Fixed& max(Fixed& a, Fixed& b) {
        if (a > b)
            return a;
        return b;
    }

    static const Fixed& max(const Fixed& a, const Fixed& b) {
        if (a > b)
            return a;
        return b;
    }
};

/*
===============================================================================
8. OPÉRATEUR DE SORTIE (<<)
===============================================================================

Cet opérateur spécial permet d'afficher nos objets avec std::cout.
Il doit être défini EN DEHORS de la classe car le premier paramètre 
est std::ostream, pas notre classe.
*/

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();          // Convertit en float pour l'affichage
    return out;                      // Retourne le flux pour permettre les chaînes
    // Exemple : std::cout << a << " et " << b << std::endl;
}

/*
===============================================================================
9. EXEMPLES D'UTILISATION PRATIQUE
===============================================================================

Voici comment utiliser toutes ces fonctionnalités dans un programme :
*/

void exemples_utilisation() {
    std::cout << "\n=== EXEMPLES D'UTILISATION ===" << std::endl;

    // 1. CRÉATION D'OBJETS
    Fixed a;                         // Default constructor : a = 0
    Fixed b(42);                     // Int constructor : b = 42
    Fixed c(3.14f);                  // Float constructor : c = 3.14
    Fixed d(c);                      // Copy constructor : d = copie de c

    // 2. AFFICHAGE
    std::cout << "a = " << a << std::endl;  // Utilise operator<<
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    // 3. OPÉRATIONS ARITHMÉTIQUES
    Fixed somme = b + c;             // Addition
    Fixed produit = b * c;           // Multiplication
    Fixed quotient = b / c;          // Division

    std::cout << b << " + " << c << " = " << somme << std::endl;
    std::cout << b << " * " << c << " = " << produit << std::endl;
    std::cout << b << " / " << c << " = " << quotient << std::endl;

    // 4. COMPARAISONS
    if (b > c) {
        std::cout << b << " est plus grand que " << c << std::endl;
    }

    if (a == Fixed(0)) {
        std::cout << "a est égal à zéro" << std::endl;
    }

    // 5. INCRÉMENTATION
    std::cout << "Avant incrémentation : a = " << a << std::endl;
    Fixed pre = ++a;                 // Pré-incrémentation
    std::cout << "Après ++a : a = " << a << ", pre = " << pre << std::endl;

    Fixed post = a++;                // Post-incrémentation
    std::cout << "Après a++ : a = " << a << ", post = " << post << std::endl;

    // 6. FONCTIONS MIN/MAX
    Fixed minimum = Fixed::min(b, c);
    Fixed maximum = Fixed::max(b, c);
    std::cout << "Min(" << b << ", " << c << ") = " << minimum << std::endl;
    std::cout << "Max(" << b << ", " << c << ") = " << maximum << std::endl;

    // 7. CONVERSIONS
    float en_float = c.toFloat();
    int en_int = c.toInt();
    std::cout << c << " en float = " << en_float << std::endl;
    std::cout << c << " en int = " << en_int << std::endl;

    // 8. TEST DIVISION PAR ZÉRO
    Fixed zero(0);
    Fixed resultat = b / zero;       // Affichera un message d'erreur
    std::cout << "Résultat division par zéro : " << resultat << std::endl;
}

/*
===============================================================================
10. CONCEPTS AVANCÉS EXPLIQUÉS SIMPLEMENT
===============================================================================

A) POURQUOI FIXED-POINT AU LIEU DE FLOAT ?

Les nombres float ont une précision variable :
- Très précis près de 0
- Moins précis pour les grands nombres
- Calculs parfois approximatifs

Les nombres fixed-point ont une précision constante :
- Même précision partout
- Calculs exacts (dans la limite de la précision)
- Plus rapides sur certains processeurs

B) POURQUOI 8 BITS FRACTIONNAIRES ?

Avec 8 bits fractionnaires sur un int de 32 bits :
- 24 bits pour la partie entière : valeurs de -8388608 à 8388607
- 8 bits pour la partie fractionnaire : précision de 1/256 ≈ 0.0039

C'est un bon compromis entre plage de valeurs et précision.

C) QU'EST-CE QUE "const" ?

const signifie "ne modifie pas" :
- const Fixed& other : other ne sera pas modifié
- bool fonction() const : cette fonction ne modifie pas l'objet
- const Fixed& min() : retourne une référence non-modifiable

D) POURQUOI static_cast AU LIEU DE (int) ?

static_cast<int>() est plus sûr que (int) :
- Vérifications à la compilation
- Plus lisible et explicite
- Fait partie du C++ moderne

E) POURQUOI long long DANS LES CALCULS ?

int a 32 bits. Quand on multiplie deux int :
- Le résultat peut dépasser 32 bits (débordement)
- long long a 64 bits, assez pour le résultat
- On reconvertit en int après avoir ajusté la valeur

===============================================================================
11. ERREURS COURANTES À ÉVITER
===============================================================================
*/

//❌ MAUVAIS :
Fixed operator+(Fixed other) {          // Pas de const&, copie inutile
    return this->_value + other._value;  // Type de retour incorrect
}

//✅ BON :
Fixed operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return result;
}

//❌ MAUVAIS :
Fixed& operator=(Fixed other) {         // Pas de const&
    _value = other._value;
    return *this;                       // Pas de protection auto-affectation
}

//✅ BON :
Fixed& operator=(const Fixed& other) {
    if (this != &other) {              // Protection auto-affectation
        this->_value = other._value;
    }
    return *this;
}

//❌ MAUVAIS :
Fixed operator/(const Fixed& other) const {
    return this->_value / other._value;  // Division par zéro possible
}

//✅ BON :
Fixed operator/(const Fixed& other) const {
    if (other._value == 0) {
        std::cout << "Error: Division by zero!" << std::endl;
        return Fixed(0);
    }
    // ... calcul sécurisé
}

/*
===============================================================================
RÉSUMÉ DES NOTIONS CLÉS
===============================================================================

Ce module vous apprend :

1. **Orthodox Canonical Form** : Les 4 fonctions de base de toute classe
2. **Surcharge d'opérateurs** : Donner du sens aux symboles +, -, ==, etc.
3. **Fixed-point numbers** : Une alternative aux float avec précision constante
4. **Gestion des erreurs** : Protection division par zéro, débordements
5. **const correctness** : Utiliser const pour la sécurité et la clarté
6. **Fonctions statiques** : Fonctions de classe (min/max)
7. **Casts modernes** : static_cast au lieu des casts C
8. **Manipulation de bits** : Shifts pour multiplication/division rapide

Ces concepts sont fondamentaux pour créer des classes robustes et intuitives
à utiliser en C++. Maîtriser ce module vous donne des bases solides pour
le polymorphisme et la programmation orientée objet avancée !

===============================================================================
*/
