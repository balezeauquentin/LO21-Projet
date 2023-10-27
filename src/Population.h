#include "liste_bit.h"
#include "Individu.h"

#ifndef INDIVIDU_H_POPULATION_H
#define INDIVIDU_H_POPULATION_H


typedef struct Population {
    Liste_individu indivs;
} Population;

Population Initialisationpop(int taille);

void Afficher_population(Population pop);

void Afficher_meilleur(Population pop);

void Selection(Population temp, int tSelect);

void quicksort(Liste_individu start, Liste_individu end);

Population croise_pop(Liste_individu l1);

int taille_pop(Population pop);

void test(Population pop);

#endif //INDIVIDU_H_POPULATION_H
