# Projet-Crash-Tech-MEF1G

Projet Crash Tech - MEF1G

Crash Tech est un projet réalisé en langage C.
Son objectif est d'analyser les données des accidents
de la route en France entre 2005 et 2024 à partir
d'un fichier CSV.

Les différents traitements
Le programme comporte trois modes de traitement :

YEAR_DATA : statistiques par année à l'aide d'un
tableau statique.
AGE_DATA : statistiques par âge à l'aide d'une
liste chaînée.
CRASH_DATA : recherche d'un accident à l'aide
d'un arbre AVL.

Organisation des fichiers
main.c : programme principal.
year.c : fonctions du traitement YEAR_DATA.
year.h : structures et prototypes des fonctions.
Makefile : compilation du programme.
exemple.csv : fichier de données permettant
de tester le programme.

Compilation
Pour compiler le programme, utiliser la commande :

make

Exécution:

Pour lancer le traitement YEAR_DATA :

./crashTech YEAR_DATA exemple.csv


L'utilisateur peut ensuite choisir une année entre
2005 et 2024 pour consulter :

Le nombre d'accidents.
Le nombre de personnes indemnes.
Le nombre de morts.
Le nombre de blessés graves.
Le nombre de blessés légers.

Pour quitter le programme, saisir 0.

Nettoyage
Pour supprimer les fichiers générés lors de la
compilation :

make clean

