#include <malloc.h>
#include <stdio.h>
#include "liste_bit.h"
#include "Individu.h"


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