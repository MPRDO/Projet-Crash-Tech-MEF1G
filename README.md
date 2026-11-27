# Projet-Crash-Tech-MEF1G

# Crash Tech

Crash Tech est un programme développé en langage C permettant
d'analyser les données des accidents de la route survenus en
France entre 2005 et 2024.

Le programme utilise un fichier CSV contenant les informations
relatives aux accidents, aux véhicules et aux personnes impliquées.

Le projet est organisé en plusieurs fichiers afin de rendre
le code plus clair et plus facile à maintenir.

---

## Principe du programme

Le programme permet de consulter différentes statistiques
à partir des données du fichier CSV.

Trois modes de traitement sont prévus :

| Mode | Description | Structure utilisée |
|---|---|---|
| YEAR_DATA | Statistiques par année | Tableau statique |
| AGE_DATA | Statistiques par âge | Liste chaînée |
| CRASH_DATA | Recherche d'un accident | Arbre AVL |

---

## Fonctionnement de YEAR_DATA

Le programme commence par lire le fichier CSV et récupère
les informations nécessaires au calcul des statistiques.

Les données sont ensuite stockées dans un tableau de 20 cases,
chaque case correspondant à une année entre 2005 et 2024.

L'utilisateur choisit une année et peut consulter :

- Le nombre total d'accidents.
- Le nombre de personnes indemnes.
- Le nombre de personnes décédées.
- Le nombre de blessés graves.
- Le nombre de blessés légers.

L'utilisateur peut consulter plusieurs années sans relancer
le programme. Pour quitter le programme, il suffit de saisir 0.

---

## Fonctionnalités

- Lecture d'un fichier CSV.
- Stockage des statistiques dans un tableau.
- Comptage des accidents et des personnes impliquées.
- Consultation des statistiques par année.
- Gestion des erreurs d'ouverture du fichier.
- Vérification de l'année saisie.
- Programme structuré en plusieurs fichiers.

---

## Organisation du projet

| Fichier | Description |
|---|---|
| main.c | Programme principal |
| year.c | Fonctions du traitement YEAR_DATA |
| year.h | Structures et prototypes |
| Makefile | Compilation du programme |
| exemple.csv | Fichier de test |

---

## Compilation

Pour compiler le programme, exécuter la commande suivante
dans le terminal :

```bash
make
```

Si la compilation ne fonctionne pas correctement, supprimer
les anciens fichiers générés avec :

```bash
make clean
```

Puis relancer la compilation avec :

```bash
make
```

Une fois la compilation terminée, lancer le programme avec :

```bash
./crashTech YEAR_DATA exemple.csv



CE README N4EST PAS DEFINITIF IL évolue PROPORTIONNELLEMNT à NOTRE PROJET!!!!!

