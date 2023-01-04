#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.
    Population pop;
    Population end;
    int taillePop = 0;
    int tSelect = 0;
    int nGen = 0;
    int fin = 1;
    printf("Taille de la population : \n");
    scanf("%d", &taillePop);
    printf("Nombre d'individus selectionnes (%) : \n");
    scanf("%d", &tSelect);
    tSelect = tSelect * taillePop / 100;
    printf("Nombre de generations : \n");
    scanf("%d", &nGen);
    pop = Initialisationpop(taillePop);
    end = pop;
    for(int i = 0; i < nGen; i++){
        //Croisement de la population
        croise_pop(pop.indivs);
        //déplacement du curseur pour avoir accès au dernier individu
        while(end.indivs->next != NULL){
            end.indivs = end.indivs->next;
        }
        //Trie de la population
        quicksort(pop.indivs, end.indivs);
        //Selection des tSelect meilleurs individus
        Selection(pop, tSelect);
        i++;
    }
    Afficher_meilleur(pop);
    while(fin != 0){
        printf("Voulez vous quittez ? Pressez 0\n");
        scanf("%d", &fin);
    }

    return 0;
}
