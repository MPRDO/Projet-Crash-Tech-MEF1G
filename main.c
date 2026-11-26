#include <stdio.h>
#include <string.h>
#include "year.h"

int main(int argc, char *argv[]) {
    Annee tab[20] = {0};
    if (argc != 3) {
        printf("Utilisation : ./crashTech YEAR_DATA data.csv\n");
        return 1;
    }
    if (strcmp(argv[1], "YEAR_DATA") == 0) {
        lireFichier(argv[2], tab);
        menu(tab);
    } else {
        printf("Mode non disponible dans ce prototype\n");
        return 1;
    }
    return 0;
}
