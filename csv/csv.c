#include "csv.h"
#include <stdlib.h>
#include <string.h>

FILE *ouvrir_csv(const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        fprintf(stderr, "Erreur : impossible d'ouvrir '%s'.\n", nom_fichier);
        exit(EXIT_FAILURE);
    }

    char entete[512];
    if (fgets(entete, sizeof(entete), fichier) == NULL) {
        fprintf(stderr, "Erreur : fichier vide.\n");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }
    return fichier;
}
int lire_ligne_csv(FILE *fichier, LigneCsv *donnee) {
    char ligne[512];

    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        return 0; 

    for (int i = 0; ligne[i] != '\0'; i++) {
        if (ligne[i] == '\n' || ligne[i] == '\r') {
            ligne[i] = '\0';
            break;
        }
    }

    char *col[9];
    char *debut = ligne;
    for (int i = 0; i < 9; i++) {
        col[i] = debut;
        char *sep = strchr(debut, ';');
        if (sep != NULL) {
            *sep = '\0';       
            debut = sep + 1;   
        } else if (i < 8) {
            return -1;         
        }
    }
    donnee->annee = atoi(col[0]);
    if (donnee->annee < 2000 || donnee->annee > 2100) {
        return -1;
    }

    while (col[1][0] == ' ') col[1]++;
    while (col[2][0] == ' ') col[2]++;

    char cle_texte[32];
    sprintf(cle_texte, "%d%s", donnee->annee, col[1]);
    donnee->cle_accident = atoll(cle_texte);

    if (col[2][0] == '\0') {
        strcpy(donnee->id_vehicule, "INCONNU");
    } else {
        strncpy(donnee->id_vehicule, col[2], 15);
        donnee->id_vehicule[15] = '\0';
    }
    donnee->emplacement = atoi(col[3]);
    donnee->type_usager = atoi(col[4]);
    donnee->gravite     = atoi(col[5]);
    donnee->genre       = atoi(col[6]);

    int naissance = atoi(col[7]);
    if (naissance > 1900 && naissance <= donnee->annee) {
        donnee->age = donnee->annee - naissance;
    } else {
        donnee->age = -1; 
    }
    if (col[8][0] == '\0') {
        donnee->trajet = -1;
    } else {
        donnee->trajet = atoi(col[8]);
    }
    return 1;
}