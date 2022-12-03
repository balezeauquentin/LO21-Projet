#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "liste_bit.h"
#include "Individu.h"


// 1.Initialiser aléatoirement la liste de bits (version iterative)
Listebit initialisation_liste_bits(int longeur_liste_bits) {
    Listebit l = NULL;
    int i = 0;

    if (longeur_liste_bits == 0) {         //Si la longueur est égale à 0, renvoyé l vide.
        return l;
    } else if (longeur_liste_bits == 1) { //Si longueur égale à 1.
        Bit valeur = rand() % 2; //Initialisation de "valeur" avec un chiffre aléatoire entre 0 et 1.
        l = ajout_tete_bit(l, valeur); //Ajout en tête de liste la valeur.
        return l;
    } else {
        srand(time(NULL)); // initialisation du générateur aléatoire.
        while (i < longeur_liste_bits) { //Répétition n fois de la boucle pour que la chaine soit de la bonne taille.

            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            i++; //Incrementation de la valeur i pour ne pas avoir une boucle infinie.
        }
        return l;
    }
}


Listebit ajout_tete_bit(Listebit l, Bit new_value) {
    Listebit new = NULL;
    new = (Listebit) malloc (sizeof(Chaine_de_bit));
    new->valeur = new_value;
    if (l == NULL) {
        new->next = NULL;
        return new;
    } else {
        new->next = l;
        return new;
    }
}

Listebit ajout_fin_bit(Listebit l, Bit new_value) {
    Listebit tempo;
    Listebit new;
    tempo = (Listebit) malloc(sizeof(Chaine_de_bit));
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

Listebit supp_tete_bit(Listebit l) {
    Listebit tempo;
    tempo = (Listebit) malloc(sizeof(Chaine_de_bit));
    if (l == NULL) {
        return l;
    } else {
        tempo = l->next;
        free(l);
        return tempo;
    }
}

Listebit supp_fin_bit(Listebit l) {
    Listebit temp;
    temp = (Listebit) malloc(sizeof(Chaine_de_bit));
    temp = l;
    if (l == NULL) {
        return l;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return l;
}

int taille_liste_bit(Listebit l) {
    int compte = 0;
    if (l == NULL) {
        return 0;
    } else {
        while (l != NULL) {
            l = l->next;
            compte++;
        }
        return compte;
    }
}

void afficher_list_bit(Listebit l){
    Listebit p;
    if (l==NULL){
        printf("Liste vide");
    }
    else {
        p=l;
        while (p->next != NULL) {
            printf("Bit %d \n", p->valeur);
            p = p->next;
        }
        printf("Bit %d\n", p->valeur);
    }
}