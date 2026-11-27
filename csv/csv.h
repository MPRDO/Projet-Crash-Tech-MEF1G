#ifndef CSV_H
#define CSV_H

#include <stdio.h>

typedef struct {
    int annee;               
    long long cle_accident;  
    char id_vehicule[16];    
    int emplacement;         
    int type_usager;         
    int gravite;             
    int genre;               
    int age;                 
    int trajet;              
} LigneCsv;

FILE *ouvrir_csv(const char *nom_fichier);
int lire_ligne_csv(FILE *fichier, LigneCsv *donnee);

#endif