# conan_practice
Projet C++ basique pour pratiquer l'usage de Conan et CMake
C'est juste un simple exécutable permettant d'afficher des traces grâce à la bibliothèque externe fmt (https://conan.io/center/recipes/fmt?version=11.0.2)
et de compresser des chaînes de caractères avec la bibliotèque externe LZ4 (https://conan.io/center/recipes/lz4?version=1.10.0)

## Prérequis

Avant de pouvoir construire ce projet, assurez-vous d'avoir les outils suivants installés sur votre machine :

- [CMake](https://cmake.org/) 
- [Conan](https://conan.io/)
  Installez Conan avec "pip" :

   ```bash
   pip install conan
   ```
- Un compilateur C++ (par exemple, GCC, Clang, MSVC)

## Installation

1. Clonez ce dépôt sur votre machine locale :

   ```bash
   git clone https://github.com/NetVince/conan_practice.git
   cd conan-practice
   ```

2. Avant de commencer, il est nécessaire de créer le profil Conan

   ```bash
   conan profile detect
   ```
   Vérifiez que les settings sont bons. Par la suite, on pourra créer de nouveaux profils pour build en mode Debug par exemple. Par défaut, on est en mode Release

3. Installez les dépendances du projet avec Conan :

   ```bash
   conan install . --output-folder=build --build=missing
   ```
   Cette commande télécharge toutes les dépendances listées dans le fichier `conanfile.txt` ou `conanfile.py` et les compile si nécessaire.
   De plus, on crée automatiquement le dossier de build


## Compilation

Pour compiler le projet, utilisez simplement `conan` à partir du répertoire de construction :

```bash
conan build -of=build .
```

Cette commande génère les exécutables et/ou les bibliothèques du projet dans le répertoire `build`.
> **⚠️ Attention :** Le build type semble obligatoire. J'ai eu des problèmes sans cette option. A voir


## Exécution

Une fois la compilation terminée, vous pouvez exécuter l'exécutable généré. Par exemple :

```bash
./conan_practice
```

## Packaging

Pour le moment, le packaging en RPM se fait grâce à 'make' :
```bash
make package .
```
depuis le dossier de build.

## Conanfile.py

Ressources : https://docs.conan.io/2/tutorial.html
Il existe beaucoup d'options pour le fichier conanfile.py
Pour l'instant le fichier est très succinct.
A l'avenir, il faut l'enrichir pour permettre :
    - de faire appel à CMake directement depuis Conan pour build le projet
    - de définir les chemins de build en fonction du type de release par exemple

## CMakeLists.txt

Ce fichier est classique, il permet de dire quelles sont les versions des libs externes à utiliser pour compiler.
Il permet aussi de définir le paquet RPM qui va être créé.

A l'avenir, il faudrait peut-être créer un script permettant de changer facilement les versions des libs dans ce fichier
pour faciliter le travail des devs pour éviter qu'il modifie manuellement le fichier à chaque changement de version.