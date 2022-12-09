#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Individu.h"
#include "liste_bit.h"

//Cette fonction permet de créé un individu de manière aléatoire et avec une longueur donnée.
Listebit InitialisationIndiv(int longIndiv) {
    Listebit l = NULL;
    l = initialisation_liste_bits(longIndiv);
    return l;
}




//Calcule la qualité d'un individu, prend en parametre la valeur de l'individu et sa taille.
double QualiteIndiv(double valeur, int taille) {
    double X;
    double Qualite;
    int A = -1, B = 1;
    X = (valeur / pow(2, taille) * (B - A) + A); //Calcule de X
    Qualite = -pow(X, 2); //Calcule de la fonction définie par f1(x) = -X^2
    return Qualite;
}


/*
 * Liste_individu ajout_fin_indiv(Liste_individu l, Bit new_value) {
    Listebit tempo;
    Listebit new;
    new = (Listebit) malloc(sizeof(Chaine_de_bit));
    new->valeur = new_value;
    new->next = NULL;
    if (l == NULL) {
        printf("liste vide ajout du dernier element en tete de liste");
        return new;
    } else {
        tempo = l;
        while (tempo->next != NULL) {
            tempo = tempo->next;
        }
        tempo->next = new;
    }
    return l;
}
*/