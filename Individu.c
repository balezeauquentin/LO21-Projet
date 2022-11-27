#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "liste.h"

Listebit Initialisation(int longIndiv) {
    Listebit l = NULL;
    int i = 0;
    srand(time(NULL));
    if (longIndiv == 0) {
        return l;
    } else if (longIndiv == 1) {
        Bit valeur = rand() % 2;
        l = ajout_tete_bit(l, valeur);
        return l;
    } else {
        while (i < longIndiv) {
            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            i++;
        }
        return l;
    }
}
