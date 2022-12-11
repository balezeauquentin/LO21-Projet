#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"

Population Initialisationpop(int taille) {

    Liste_individu new_individu;
    new_individu= (Liste_individu )malloc(sizeof (Individu));
    Population np; // nouvelle population
    int val_indiv;
    float qual_indiv;
    Listebit lb_indiv;
    for(int i=0;i<taille;i++) {

        lb_indiv = initialisation_liste_bits(8);
        val_indiv = valeur_lb(lb_indiv);
        qual_indiv = qualite_lb(val_indiv, 8);
        new_individu = ajout_fin_indiv(new_individu, lb_indiv, val_indiv, qual_indiv);

    }
    np.indivs=new_individu;
    //free(new_individu);
    return np;

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
        printf("Individu %d: valeur= %d qualite=%f\n", i,tempo->valeur,tempo->qualite);
        afficher_list_bit(tempo->liste_de_bit);
        tempo = tempo->next;
            i++;
        }
    printf("Individu %d: valeur= %d qualite=%f\n", i,tempo->valeur,tempo->qualite);
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

Liste_individu partition (Liste_individu start, Liste_individu end, double pivot){
    Liste_individu current = start;
    Liste_individu pivot_node = end;
    while (current != pivot_node){
        // Si la valeur du noeud courant est inférieure au pivot, on l'insère avant le pivot
        if (current->valeur < pivot)
        {
            // Si le noeud courant est la tête de la liste, on met à jour la tête
            if (current == start)
                start = current->next;

            // On insère le noeud courant avant le pivot et on met à jour ses liens
            current->next = pivot_node;
            pivot_node = current;

            // On avance le pointeur courant vers le prochain noeud
            current = current->next;
        }
    }
// Retourne le noeud pivot
    return pivot_node;
}
Population Quick_sort_population(Population pop) {
    double pivot;
    if (pop.indivs == NULL) {
        printf("Ne peux etre trie car liste vide");
        return pop;
    } else {
        Liste_individu head = pop.indivs;
        Liste_individu end = pop.indivs;
        while (end->next != NULL ){
            end = end->next;
        }
        pivot = pop.indivs->qualite;
        partition(head,end,pivot);
        pop.indivs = head;
    }

    return pop;
}