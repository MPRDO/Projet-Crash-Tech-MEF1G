#ifndef YEAR_H
#define YEAR_H

typedef struct {
    int accidents;
    int indemnes;
    int morts;
    int blessesGraves;
    int blessesLegers;
} Annee;

void lireFichier(const char *nom, Annee tab[]);
void afficher(Annee tab[], int annee);
void menu(Annee tab[]);
#endif
