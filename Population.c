#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"

Population Initialisationpop(int taille) {
    int i = 0;
    int longueur = rand() % 11 + 1;
    Liste_individu personeA;
    personeA = (Liste_individu) malloc(sizeof(Liste_individu));
    Liste_individu tempo = (Liste_individu) malloc(sizeof(Liste_individu));
    tempo = personeA;
    Listebit l;
    double valeur = 0;
    while (i < taille) {
        personeA = (Liste_individu) malloc(sizeof(Population));
        printf("%d",longueur);
        l = InitialisationIndiv(longueur);
        if (longueur == 0) {
            personeA->liste_de_bit = NULL;
            personeA->valeur = 0;
            personeA->qualite = 0;
            personeA = personeA->next;
        } else {
            valeur = valeur_lb(l);
            printf("test");
            personeA->valeur = valeur;
            //personeA->qualite = valeur_lb(personeA->valeur);
            personeA = personeA->next;
        }
        i++;
    }
    printf("\n\n%d\n\n",i);
    personeA->next = NULL;
    Population population_test;
    population_test.indivs = personeA;
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
    return pop;
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
    }
    return n_individus;
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
        printf("Individu %d: valeur= %f qualite=%f\n", i,tempo->valeur,tempo->qualite);
        afficher_list_bit(tempo->liste_de_bit);
        tempo = tempo->next;
            i++;
        }
    printf("Individu %d: valeur= %f qualite=%f\n", i,tempo->valeur,tempo->qualite);
    afficher_list_bit(tempo->liste_de_bit);
    }
}

Population Selection (Population pop, int tSelect){
    Population trier;
    Population copie = pop;
    int i = 0;
    while(i < tSelect){
        pop.indivs = pop.indivs->next;
        trier.indivs->qualite = pop.indivs->qualite;
        i++;
    }
    while(pop.indivs != NULL){
        pop.indivs = pop.indivs->next;
        trier.indivs->qualite = copie.indivs->qualite;
        copie.indivs = copie.indivs->next;
    }
    Afficher_population(pop);
    Afficher_population(trier);
    Afficher_population(copie);
    return trier;
}