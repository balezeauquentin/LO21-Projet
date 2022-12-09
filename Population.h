#include "liste_bit.h"
#include "Individu.h"
#ifndef INDIVIDU_H_POPULATION_H
#define INDIVIDU_H_POPULATION_H


typedef struct Population{
    Liste_individu indivs;
}Population;

Population Initialisationpop (int taille);

int taille_population(Population pop);
void Afficher_population(Population pop);
Population Selection (Population pop, int tSelect);
Population Tri_liste(Population pop);

#endif //INDIVIDU_H_POPULATION_H
