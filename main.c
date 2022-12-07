#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.
    //Population pop1;
    //pop1=Initialisationpop(8);
    //Afficher_population(pop1);
    Listebit l1;
    l1= initialisation_liste_bits(7);
    afficher_list_bit(l1);
    printf("%f", ValeurIndiv(l1));
    return 0;
}
