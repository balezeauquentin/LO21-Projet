#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>

int main() {

/*
 * salut c'est moi c'est un test.
 */
    //test liste de bits
    srand(time(NULL)); // initialisation du générateur aléatoire.
    Listebit l= initialisation_liste_bits(6);
    afficher_list_bit(l);

    printf("liste 2");
    Listebit l2= initialisation_liste_bits(6);
    afficher_list_bit(l2);


    //Initialisationpop(4);

    //test liste d'individus

    //InitialisationIndiv()
    return 0;
}
