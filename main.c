#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.
    Population p1;
    p1=Initialisationpop(5);
    Afficher_population(p1);



    return 0;
}
