#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Individu.h"
#include "liste.h"

int main() {
    int taille;
    Listebit l;
    l = Initialisation(8);
    taille = taille_liste_bit(l);
    printf("%d", taille);
    return 0;
}
