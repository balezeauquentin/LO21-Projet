#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste.h"

Population Initialisationpop (int taille){
    srand(time(NULL));
    int i = 0;
    Stat_individu personeA;
    Stat_individu tempo;
    tempo = personeA;
    Listebit l;
    double valeur;
    while (i<taille){
        int longueur = rand() % 11;
        l = InitialisationIndiv(longueur);
        if(longueur == 0){
            personeA->liste_de_bit = NULL;
            personeA->valeur = 0;
            personeA->qualite = 0;
            personeA = personeA->next;
        }else{
            valeur = ValeurIndiv(l);
            personeA->valeur = valeur;
            personeA->qualite = QualiteIndiv(personeA->valeur,longueur);
            printf("test");
            personeA = personeA->next;
        }
        i++;
    }
    personeA->next = NULL;
    Population population_test;
    population_test.individu = tempo;
    return population_test;
}

Population Triliste(Population pop){
    if(pop.individu == NULL){
        printf("Ne peux etre trie car liste vide");
        return pop;
    }else{
        if (pop.individu->next->qualite < pop.individu->qualite){

        }
    }
}
