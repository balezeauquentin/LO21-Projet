#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.

    Initialisationpop(3);

    return 0;
}
