#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.

    taille_population(Initialisationpop(8));


    return 0;
}
