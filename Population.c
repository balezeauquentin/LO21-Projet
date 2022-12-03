#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"

Population Initialisationpop(int taille) {
    srand(time(NULL));
    int i = 0;
    Liste_individu personeA;
    personeA = (Liste_individu) malloc(sizeof(Population));
    Liste_individu tempo;
    tempo = personeA;
    Listebit l;
    double valeur;
    while (i < taille) {
        int longueur = rand() % 11;
        l = InitialisationIndiv(longueur);
        if (longueur == 0) {
            personeA->liste_de_bit = NULL;
            personeA->valeur = 0;
            personeA->qualite = 0;
            personeA = personeA->next;
        } else {
            valeur = ValeurIndiv(l);
            personeA->valeur = valeur;
            personeA->qualite = QualiteIndiv(personeA->valeur, longueur);
            printf("test");
            personeA = personeA->next;
        }
        i++;
    }
    personeA->next = NULL;
    Population population_test;
    population_test.indivs = tempo;
    return population_test;
}

Population Tri_liste(Population pop) {


    Liste_individu S1;
    Liste_individu S2;
    if (pop.indivs == NULL) {
        printf("Ne peux etre trie car liste vide");
        return pop;
    } else {
        if (taille_population(pop) % 2 == 0) {

        } else {

        }

    }
}

int taille_population(Population pop) {
    int n_individus;
    if (pop.indivs == NULL) {
        printf("Ne peux etre trie car liste vide");
        n_individus = 0;
    } else {
        Liste_individu point = pop.indivs;
        while (point->next != NULL) {
            n_individus = n_individus + 1;
            point = point->next;
        }
        return n_individus;
    }
}

void Afficher_population(Population pop){
    int i=1;
    Liste_individu tempo;
    if (pop.indivs==NULL){
        printf("Liste vide");
    }
    else {
        tempo=pop.indivs;
        while (tempo->next != NULL) {
        printf("Individu %d: valeur= %d qualite=%d\n", i,tempo->valeur,tempo->qualite);
        afficher_list_bit(tempo->liste_de_bit);
        tempo = tempo->next;
            i++;
        }
    printf("Individu %d: valeur= %d qualite=%d\n", i,tempo->valeur,tempo->qualite);
    afficher_list_bit(tempo->liste_de_bit);
    }

}