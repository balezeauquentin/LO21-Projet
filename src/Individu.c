#include <stdio.h>
#include <stdlib.h>
#include "Individu.h"
#include "liste_bit.h"
#include "Population.h"
//Cette fonction permet de créer un individu de manière aléatoire et avec une longueur donnée.

Liste_individu ajout_fin_indiv(Liste_individu l, Listebit lb, int valeur, float qualite) {
    Liste_individu tempo;
    Liste_individu ajout_indiv;
    ajout_indiv = (Liste_individu) malloc(sizeof(Individu));
    ajout_indiv->prop.liste_de_bit = lb;
    ajout_indiv->prop.valeur = valeur;
    ajout_indiv->prop.qualite = qualite;
    ajout_indiv->next = NULL;
    if (l == NULL) {
        l = ajout_indiv;
    } else {
        tempo = l;
        while (tempo->next != NULL) {
            tempo = tempo->next;
        }
        tempo->next = ajout_indiv;
    }
    return l;
}




