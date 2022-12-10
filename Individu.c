#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Individu.h"
#include "liste_bit.h"

//Cette fonction permet de créer un individu de manière aléatoire et avec une longueur donnée.

void affiche_indiv(Liste_individu li) {
    afficher_list_bit(li->liste_de_bit);

}

int vide(Liste_individu li){
    if ((li->valeur==0)||(li->qualite=0)||(li->liste_de_bit=NULL)){
        return true;
    }else{
        return false;
    }

}






Liste_individu ajout_fin_indiv(Liste_individu l,Listebit lb,int valeur,float qualite) {

    Liste_individu tempo;
    Liste_individu ajout_indiv;
    ajout_indiv = (Liste_individu) malloc(sizeof(Individu));
    ajout_indiv->liste_de_bit=lb;
    ajout_indiv->valeur = valeur;
    ajout_indiv->qualite = qualite;
    ajout_indiv->next = NULL;
    if (l==NULL) {
        printf("liste vide ajout du dernier element en tete de liste");
        l=ajout_indiv;

    } else {
        tempo = l;
        while (tempo->next != NULL) {
            tempo = tempo->next;
        }
        tempo->next = ajout_indiv;
    }

    return l;
}



