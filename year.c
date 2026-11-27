#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "year.h"

void lireFichier(const char *nom, YearStats tab[]) {
    FILE *f = fopen(nom, "r");
    if (f == NULL) {
        printf("Erreur ouverture du fichier\n");
        exit(1);
    }
    char ligne[256], vehicule[30], id[32], ancienId[32] = "";
    int annee, emplacement, type, gravite, genre, naissance, trajet;
    int ancienneAnnee = -1;

    // Ignorer l'en-tete.
    fgets(ligne, sizeof ligne, f);
    while (fgets(ligne, sizeof ligne, f) != NULL) {
        if (sscanf(ligne, "%d;%;%d;%d;%d;%d;%d;%d",
                   &annee, id, vehicule, &emplacement, &type,
                   &gravite, &genre, &naissance, &trajet) != 9) {
            printf("Erreur dans le format du fichier\n");
            fclose(f);
            exit(1);
        }
        if (annee >= 2005 && annee <= 2024) {
        int i = annee - 2005;
        if (id != ancienId || annee != ancienneAnnee) {
            tab[i].accidents++;
        }
        if (gravite == 1) {
            tab[i].indemnes++;
        }
        if (gravite == 2) {
            tab[i].morts++;
        }
        if (gravite == 3) {
            tab[i].blesses_graves++;
        }
        if (gravite == 4) {
            tab[i].blesses_legers++;
        }
        ancienId = id;
        ancienneAnnee = annee;
    }
}

fclose(f);
    }
    if (ferror(f)) {
        printf("Erreur de lecture\n");
        fclose(f);
        exit(1);
    }
    fclose(f);
}

void afficher(Annee tab[], int annee) {
    int i = annee - 2005;
    printf("\n--- Statistiques %d ---\n", annee);
    printf("Accidents : %d\n", tab[i].accidents);
    printf("Indemnes : %d\n", tab[i].indemnes);
    printf("Morts : %d\n", tab[i].morts);
    printf("Blesses graves : %d\n", tab[i].blessesGraves);
    printf("Blesses legers : %d\n", tab[i].blessesLegers);
}

void menu(Annee tab[]) {
    int choix = -1;
    while (choix != 0) {
        printf("\n===== CRASH TECH =====\n");
        printf("Choisir une annee (2005-2024)\n0 - Quitter\nVotre choix : ");
        if (scanf("%d", &choix) != 1) {
            printf("Saisie invalide\n");
            return;
        }
        if (choix >= 2005 && choix <= 2024)
            afficher(tab, choix);
        else if (choix != 0)
            printf("Annee invalide\n");
    }
}
