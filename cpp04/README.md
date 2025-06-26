# C++ Module 04 - Polymorphisme par sous-typage

[![Norme](https://img.shields.io/badge/Norme-C%2B%2B98-blue)](https://en.cppreference.com/w/cpp/98)
[![École](https://img.shields.io/badge/École-42-black)](https://42.fr/)
[![Statut](https://img.shields.io/badge/Statut-Validé-green)](https://github.com)

## ⚡ Quick Start (pour les pressés)

```bash
# Test rapide de tous les exercices
for i in {0..3}; do cd ex0$i && make && ./ex0$i && cd ..; done

# Lire le guide complet (1299 lignes)
code MODULE_04_GUIDE_COMPLET.cpp

# Tests spécialisés
cd ex00 && make test_polymorphism    # Polymorphisme en détail
cd ex01 && make test_deep_copy       # Copie profonde expliquée  
cd ex03 && make test_limits          # Cas limites et robustesse
```

## 🆘 Si vous êtes perdus

1. **Commencez par ex00** - Le polymorphisme de base
2. **Lisez les commentaires** dans les main.cpp améliorés
3. **Testez les exemples** du guide complet
4. **Comparez** avec les fichiers WrongAnimal pour voir la différence
5. **Utilisez Valgrind** pour vérifier la mémoire : `valgrind ./ex01`

## 📋 Description

Ce module introduit les concepts avancés de la programmation orientée objet en C++ :
- **Polymorphisme par sous-typage** avec méthodes virtuelles
- **Gestion mémoire avancée** et copie profonde
- **Classes abstraites** et méthodes pure virtuelles
- **Interfaces** et patterns de conception

## 🧠 Concepts expliqués simplement

### 🔄 Polymorphisme (ex00)
**Qu'est-ce que c'est ?** Le polymorphisme permet à un objet de se comporter différemment selon son type réel, même quand on le manipule via un pointeur vers sa classe de base.

**Exemple concret :** Un pointeur `Animal*` peut pointer vers un `Dog` ou un `Cat`. Avec le mot-clé `virtual`, appeler `makeSound()` exécutera la bonne méthode (`"Woof!"` ou `"Meow!"`) selon l'objet réel.

**Pourquoi important ?** Cela permet d'écrire du code générique qui fonctionne avec différents types sans connaître le type exact à l'avance.

### 🧠 Gestion mémoire et copie profonde (ex01)
**Qu'est-ce que c'est ?** Quand un objet contient des pointeurs, le copier ne copie que l'adresse, pas le contenu pointé. Deux copies partagent alors la même mémoire → problème !

**Exemple concret :** Si `Cat` a un `Brain*`, copier un `Cat` doit créer un nouveau `Brain`, pas partager le même. Sinon, détruire une copie détruit aussi le `Brain` de l'original.

**La règle des trois :** Si une classe gère des ressources (pointeurs), elle doit définir : destructeur, constructeur de copie, et opérateur d'affectation.

### 🚫 Classes abstraites (ex02)
**Qu'est-ce que c'est ?** Une classe qui ne peut pas être instanciée directement. Elle contient au moins une méthode "pure virtuelle" (= 0).

**Exemple concret :** `Animal` devient abstraite avec `virtual makeSound() = 0`. On ne peut plus faire `Animal a;` mais on peut créer des `Dog` et `Cat`.

**Pourquoi utile ?** Garantit que certaines méthodes doivent être implémentées dans les classes filles. C'est un "contrat" que les classes dérivées doivent respecter.

### 🎭 Interfaces (ex03)
**Qu'est-ce que c'est ?** Une classe où toutes les méthodes sont pure virtuelles. C'est un "contrat" pur que d'autres classes doivent implémenter.

**Exemple concret :** `ICharacter` définit `use()`, `equip()`, etc. La classe `Character` implémente ces méthodes. Cela permet d'avoir différents types de personnages qui respectent tous la même interface.

**Patterns utilisés :**
- **Strategy :** Différentes façons d'implémenter une interface
- **Prototype :** Cloner des objets avec `clone()`

## 🎯 Objectifs pédagogiques

### 🎓 Ce que vous allez apprendre

**Ex00 - Polymorphisme de base :**
- Comprendre pourquoi et quand utiliser `virtual`
- Voir la différence concrète entre comportement polymorphe et non-polymorphe
- Maîtriser les destructeurs virtuels (éviter les fuites mémoire)

**Ex01 - Gestion mémoire avancée :**
- Implémenter la "règle des trois" correctement
- Différencier copie superficielle vs copie profonde
- Gérer la mémoire dynamique sans fuites ni crashes

**Ex02 - Classes abstraites :**
- Créer des classes qui ne peuvent pas être instanciées
- Forcer l'implémentation de méthodes dans les classes filles
- Sécuriser l'architecture de votre code

**Ex03 - Interfaces et patterns :**
- Concevoir des contrats clairs avec les interfaces
- Implémenter le pattern Prototype (clone d'objets)
- Gérer des collections d'objets avec limites et contraintes

### 📈 Progression pédagogique

1. **Étape 1 :** Concepts de base du polymorphisme
2. **Étape 2 :** Gestion mémoire sécurisée  
3. **Étape 3 :** Architecture avec classes abstraites
4. **Étape 4 :** Conception avancée avec interfaces

## 📁 Structure du projet

```
cpp04/
├── README.md                     # Ce fichier
├── MODULE_04_GUIDE_COMPLET.cpp   # Guide complet (1299 lignes)
├── fr.subject.pdf               # Sujet en français
├── en.subject.pdf               # Sujet en anglais
├── fr.subject.txt               # Sujet texte français
│
├── ex00/                        # Polymorphisme de base
│   ├── main.cpp                 # Tests polymorphisme améliorés
│   ├── Animal.{cpp,hpp}         # Classe de base avec virtual
│   ├── Dog.{cpp,hpp}            # Classe dérivée
│   ├── Cat.{cpp,hpp}            # Classe dérivée
│   ├── WrongAnimal.{cpp,hpp}    # Contre-exemple sans virtual
│   ├── WrongCat.{cpp,hpp}       # Démontre polymorphisme cassé
│   ├── test_polymorphism.cpp    # Tests additionnels
│   └── Makefile
│
├── ex01/                        # Copie profonde et gestion mémoire
│   ├── main.cpp                 # Tests copie profonde améliorés
│   ├── Animal.{cpp,hpp}         # Classe de base (identique ex00)
│   ├── Dog.{cpp,hpp}            # Avec Brain* et règle des trois
│   ├── Cat.{cpp,hpp}            # Avec Brain* et règle des trois
│   ├── Brain.{cpp,hpp}          # Classe pour stockage d'idées
│   ├── test_deep_copy.cpp       # Tests spécifiques copie profonde
│   └── Makefile
│
├── ex02/                        # Classes abstraites
│   ├── main.cpp                 # Tests classe abstraite améliorés
│   ├── Animal.{cpp,hpp}         # Devenu abstraite (makeSound = 0)
│   ├── Dog.{cpp,hpp}            # Implémente makeSound
│   ├── Cat.{cpp,hpp}            # Implémente makeSound
│   ├── Brain.{cpp,hpp}          # Identique ex01
│   ├── test_abstract.cpp        # Test erreur compilation
│   └── Makefile
│
└── ex03/                        # Interfaces et patterns
    ├── main.cpp                 # Tests interfaces exhaustifs
    ├── AMateria.{cpp,hpp}       # Classe abstraite + pattern Prototype
    ├── Ice.{cpp,hpp}            # Materia concrète
    ├── Cure.{cpp,hpp}           # Materia concrète
    ├── ICharacter.hpp           # Interface personnage
    ├── Character.{cpp,hpp}      # Implémentation personnage
    ├── IMateriaSource.hpp       # Interface source de materia
    ├── MateriaSource.{cpp,hpp}  # Implémentation source
    ├── main_simple.cpp          # Version simplifiée pour debug
    ├── test_*.cpp               # Tests spécialisés (5 fichiers)
    └── Makefile
```

## 🚀 Compilation et exécution

### Compilation individuelle
```bash
# Ex00 - Polymorphisme
cd ex00 && make && ./ex00

# Ex01 - Copie profonde
cd ex01 && make && ./ex01

# Ex02 - Classes abstraites
cd ex02 && make && ./ex02

# Ex03 - Interfaces
cd ex03 && make && ./ex03
```

### Tests additionnels

Ces tests supplémentaires ont été créés pour approfondir la compréhension des concepts clés :

#### 📋 Tests par exercice

**Ex00 - `test_polymorphism.cpp`**
- **Objectif** : Démontrer la différence cruciale entre virtual et non-virtual
- **Contenu** : Tests côte-à-côte Animal vs WrongAnimal pour comprendre l'impact du mot-clé `virtual`
- **Apprentissage** : Visualiser concrètement comment fonctionne le polymorphisme

**Ex01 - `test_deep_copy.cpp`**
- **Objectif** : Valider la copie profonde et l'indépendance des objets
- **Contenu** : Tests d'adresses mémoire et modification d'un objet sans affecter sa copie
- **Apprentissage** : Comprendre la différence entre copie superficielle et profonde

**Ex02 - `test_abstract.cpp`**
- **Objectif** : Vérifier qu'une classe abstraite ne peut pas être instanciée
- **Contenu** : Code qui doit échouer à la compilation (commenté)
- **Apprentissage** : Saisir le concept de classe abstraite et pure virtual

**Ex03 - Tests spécialisés (5 fichiers)**

- **`test_pdf_exact.cpp`** : Reproduction exacte des tests du sujet PDF
- **`test_expected.cpp`** : Version standard attendue avec gestion basique
- **`test_limits.cpp`** : Tests des cas limites (inventaire plein, indices invalides)
- **`test_unequip.cpp`** : Tests de gestion mémoire lors du déséquipement
- **`main_simple.cpp`** : Version debug simplifiée pour traçage pas-à-pas

#### 🔧 **Correction majeure Ex03 - Fuite mémoire résolue**
Le `main.cpp` amélioré corrige une fuite mémoire critique lors du test `unequip()` :
- **Problème** : Les Materias déséquipées devenaient orphelines (40 bytes de fuite)
- **Solution** : Garder une référence avant `unequip()` et supprimer explicitement
- **Résultat** : Valgrind 100% clean, zéro fuite mémoire

```cpp
// ❌ Version originale (fuite)          // ✅ Version corrigée
me->equip(tmp);                        AMateria* unequipped = tmp;
me->unequip(2);                        me->equip(tmp);
// tmp devient orpheline              me->unequip(2);
                                       delete unequipped; // Nettoyer !
```

#### 🚀 Compilation des tests
```bash
# Test polymorphisme spécifique (ex00)
cd ex00 && c++ -Wall -Wextra -Werror -std=c++98 test_polymorphism.cpp *.cpp -o test && ./test

# Test copie profonde spécifique (ex01)
cd ex01 && c++ -Wall -Wextra -Werror -std=c++98 test_deep_copy.cpp *.cpp -o test && ./test

# Test classe abstraite (ex02) - ne compile pas volontairement
cd ex02 && c++ -Wall -Wextra -Werror -std=c++98 test_abstract.cpp *.cpp -o test

# Tests spécialisés ex03
cd ex03 && c++ -Wall -Wextra -Werror -std=c++98 test_pdf_exact.cpp *.cpp -o test && ./test
cd ex03 && c++ -Wall -Wextra -Werror -std=c++98 test_limits.cpp *.cpp -o test && ./test
cd ex03 && c++ -Wall -Wextra -Werror -std=c++98 test_unequip.cpp *.cpp -o test && ./test
cd ex03 && c++ -Wall -Wextra -Werror -std=c++98 main_simple.cpp *.cpp -o simple && ./simple
```

#### 💡 Utilité pédagogique

Ces tests permettent de :
- **Visualiser** les concepts abstraits avec des exemples concrets
- **Comprendre** les erreurs courantes et comment les éviter
- **Valider** la correctness des implémentations avec des cas limites
- **Déboguer** efficacement grâce aux versions simplifiées

### Nettoyage
```bash
# Nettoyer tous les exercices
for i in {0..3}; do cd ex0$i && make clean && cd ..; done
```

## 📚 Guide complet

Le fichier `MODULE_04_GUIDE_COMPLET.cpp` (1299 lignes) contient :

### 🔍 **Contenu théorique**
- **Polymorphisme** : vtable, liaison tardive, destructeurs virtuels
- **Gestion mémoire** : règle des trois, copie profonde vs superficielle
- **Classes abstraites** : méthodes pure virtuelles, sécurité conceptuelle
- **Interfaces** : patterns Strategy et Prototype, conception modulaire

### 🛠️ **Améliorations pratiques**
- **Tests exhaustifs** : cas limites, erreurs, vérifications d'adresses
- **Messages pédagogiques** : explications avant chaque test
- **Comparaisons** : comportements corrects vs incorrects
- **Debug facilité** : outputs détaillés, validation explicite

### ✅ **Checklists complètes**
- Polymorphisme (virtual, destructeurs, override)
- Gestion mémoire (new/delete, règle des trois)
- Classes abstraites (pure virtual, impossibilité d'instanciation)
- Interfaces (contrats clairs, implémentations multiples)

## 🎯 Concepts clés maîtrisés

### Ex00 - Polymorphisme : "Un pointeur, plusieurs comportements"
**🔑 Concept central :** Le polymorphisme permet qu'un même appel de méthode produise des comportements différents selon le type réel de l'objet.

**Exemple pratique :**
```cpp
Animal* animals[2] = {new Dog(), new Cat()};
animals[0]->makeSound(); // "Woof!" - même pointeur Animal*
animals[1]->makeSound(); // "Meow!" - mais comportements différents
```

✅ Méthodes virtuelles et liaison tardive
✅ Destructeurs virtuels obligatoires  
✅ Différence virtual vs non-virtual (WrongAnimal)
✅ vtable et coût du polymorphisme

### Ex01 - Gestion mémoire : "Copier sans casser"
**🔑 Concept central :** Quand un objet contient des pointeurs, le copier nécessite une attention particulière pour éviter les bugs mémoire.

**Problème illustré :**
```cpp
Cat original;
Cat copy = original;  // Si mal fait : même Brain* partagé
// Détruire 'copy' → double delete du Brain → CRASH
```

✅ Règle des trois (destructeur, constructeur copie, operator=)
✅ Copie profonde vs copie superficielle
✅ Gestion des pointeurs et ressources dynamiques
✅ Tests d'indépendance des copies

### Ex02 - Classes abstraites : "Forcer l'implémentation"
**🔑 Concept central :** Une classe abstraite ne peut pas être instanciée. Elle force les classes filles à implémenter certaines méthodes.

**Sécurité apportée :**
```cpp
// Animal animal;  ← ERREUR de compilation
// makeSound() = 0 → oblige Dog et Cat à l'implémenter
Dog dog;  // ✅ OK car Dog implémente makeSound()
```

✅ Méthodes pure virtuelles (= 0)
✅ Impossibilité d'instanciation directe
✅ Polymorphisme avec classes abstraites
✅ Sécurité conceptuelle

### Ex03 - Interfaces et patterns : "Contrats et clonage"
**🔑 Concept central :** Les interfaces définissent des "contrats" que les classes doivent respecter. Les patterns facilitent la conception.

**Pattern Prototype en action :**
```cpp
AMateria* ice = new Ice();
AMateria* clone = ice->clone();  // Nouvelle instance, même type
// Utile pour créer des copies sans connaître le type exact
```

✅ Interfaces pures (toutes méthodes virtual = 0)
✅ Pattern Prototype avec clone()
✅ Pattern Strategy avec interfaces
✅ Gestion d'inventaire avec limites
✅ Problématique des ressources orphelines

## 🚨 Pièges évités et explications

### 1. **Destructeur non virtuel** → Fuites mémoire garanties
**Piège :** Sans destructeur virtuel, seul le destructeur de la classe de base est appelé.
```cpp
class Base { ~Base() {} };           // ❌ Non virtuel
class Derived : public Base { ~Derived() { delete ptr; } };
Base* obj = new Derived();
delete obj;  // ❌ Seul ~Base() appelé → fuite de ptr
```
**Solution :** `virtual ~Base() {}` - Assure l'appel du bon destructeur.

### 2. **Copie superficielle** → Double delete et crashes
**Piège :** Le constructeur de copie par défaut copie les valeurs des pointeurs, pas ce qu'ils pointent.
```cpp
Cat cat1;           // cat1.brain pointe vers adresse X
Cat cat2 = cat1;    // cat2.brain pointe aussi vers X
// Quand cat1 et cat2 sont détruits → double delete de X → CRASH
```
**Solution :** Copie profonde - créer un nouveau Brain pour chaque Cat.

### 3. **Auto-affectation** → Comportements indéfinis
**Piège :** `obj = obj` peut causer des problèmes si mal géré.
```cpp
Cat& operator=(const Cat& other) {
    delete brain;           // ❌ On détruit notre propre brain
    brain = new Brain(*other.brain);  // ❌ other.brain est détruit !
}
```
**Solution :** Vérifier `if (this != &other)` avant toute opération.

### 4. **Index non vérifiés** → Accès mémoire invalides
**Piège :** Accéder à des éléments d'un tableau sans vérifier les limites.
```cpp
inventory[index] = materia;  // ❌ Et si index >= 4 ?
```
**Solution :** Toujours vérifier `if (index >= 0 && index < SIZE)`.

### 5. **Ressources orphelines** → Fuites mémoire subtiles (CORRIGÉ ✅)
**Piège :** Déséquiper une Materia sans la supprimer la laisse en mémoire.
```cpp
character.unequip(0);  // La Materia n'est plus dans l'inventaire...
// ...mais elle existe encore en mémoire → fuite !
```
**Solution appliquée dans le main ex03 :**
```cpp
// ✅ Approche correcte implémentée
AMateria* unequipped_materia = tmp;  // Garder référence
me->unequip(2);                      // Déséquiper
delete unequipped_materia;           // Nettoyer l'orpheline
```
**Résultat :** Valgrind clean, zéro fuite mémoire dans tous les exercices.

## 🔧 Bonnes pratiques appliquées

### ✅ Destructeurs virtuels systématiques
```cpp
class Animal {
    virtual ~Animal() {}  // ✅ Toujours virtual dans une hiérarchie
};
```

### ✅ Vérification des pointeurs avant utilisation
```cpp
if (brain != NULL) {
    brain->setIdea(0, "New idea");  // ✅ Sécurisé
}
```

### ✅ Gestion d'erreurs robuste avec index invalides
```cpp
void Character::equip(AMateria* m) {
    if (!m) return;  // ✅ Vérifier le pointeur
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {  // ✅ Trouver un slot libre
            inventory[i] = m;
            return;
        }
    }
    // ✅ Inventaire plein → gérer l'erreur
}
```

### ✅ Règle des trois complète
```cpp
class Cat {
    Brain* brain;
public:
    ~Cat() { delete brain; }                    // Destructeur
    Cat(const Cat& other) : brain(new Brain(*other.brain)) {}  // Copie
    Cat& operator=(const Cat& other) {          // Affectation
        if (this != &other) {
            delete brain;
            brain = new Brain(*other.brain);
        }
        return *this;
    }
};
```

### ✅ Messages de debug pour traçage mémoire
```cpp
std::cout << "Creating Cat with brain at: " << brain << std::endl;
```

### ✅ Tests Valgrind pour validation mémoire
```bash
valgrind --leak-check=full ./ex01
# ==12345== All heap blocks were freed -- no leaks are possible
```

## 📊 Statistiques

- **4 exercices** progressifs et complets
- **Guide de 1299 lignes** couvrant tous les concepts
- **Tests exhaustifs** avec cas limites et validation
- **Compilation sans warnings** avec flags stricts
- **Gestion mémoire** vérifiée avec Valgrind

## ✨ Fonctionnalités bonus

- **Tests additionnels** spécialisés par concept
- **Outputs pédagogiques** avec explications détaillées
- **Vérifications d'adresses** pour validation copie profonde
- **Tests de robustesse** avec paramètres invalides
- **Guide théorique complet** avec exemples concrets

---

**Note** : Ce module forme la base essentielle pour comprendre les patterns de conception avancés et l'architecture logicielle en C++. Tous les concepts sont implémentés de manière simple et pédagogique, parfaits pour un apprentissage progressif.
