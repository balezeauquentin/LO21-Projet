#include <stdlib.h>
#include <stdio.h>
#include "liste_bit.h"
#include "Individu.h"
#include <time.h>
#include <math.h>



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
        while (i < longeur_liste_bits) { //Répétition n fois de la boucle pour que la chaine soit de la bonne taille.
            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            i++; //Incrementation de la valeur i pour ne pas avoir une boucle infinie.
        }
        return l;
    }
}

Listebit reste_lb(Listebit l){
    return l->next;
}


// 1.Initialiser aléatoirement la liste de bits (version recursive)

Listebit initialisation_liste_bits_recursive(int longeur_liste_bits) {


    Listebit l = NULL;
    int i = 0;

    if (longeur_liste_bits == 0) {         //Si la longueur est égale à 0, renvoyé l vide.
        return l;
    } else if (longeur_liste_bits == 1) { //Si longueur égale à 1.
        Bit valeur = rand() % 2; //Initialisation de "valeur" avec un chiffre aléatoire entre 0 et 1.
        l = ajout_tete_bit(l, valeur); //Ajout en tête de liste la valeur.
        return l;
    } else {
            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            l->next=initialisation_liste_bits_recursive(longeur_liste_bits-1);
        return l;
    }
}






//Calcule la valeur d'un individu avec une liste de bit donnée.
int valeur_lb(Listebit l) {
    int taille = taille_liste_bit(l); //Recupération de la taille de la liste chainée.

    int value = 0;
    int i = 1;
    if (taille == 0) { //Cas ou la liste est NULL.
        return 0;
    } else {
        while (l != NULL) { //Tant que liste est différent de NULL on fait boucler, on parcourt la liste case par case.

            value = value + (l->bit * powf(2, taille - i)); //Calcule de la valeur bit par bit suivant
            // l'emplacement du bit et la taille de la chaine.
            //printf("----------------------\nvaleur de la chaine : %d valeur du bit : %d valeur de la taille : %d emplacement : %d\n",
            //       value, l->bit, taille - i, i);
            //printf("");
            l = l->next; //Passage à la case suivante.
            i++;
        }

        return value;
    }
}

//Calcule la qualité d'un individu, prend en parametre la valeur de l'individu et sa taille.
float qualite_lb(int valeur, int longIndiv) {

    float X;
    float Qualite;
    int A = -1, B = 1;
    X = (valeur / powf(2, longIndiv)) * (B - A) + A; //Calcule de X
    Qualite = -powf(X, 2); //Calcule de la fonction définie par f1(x) = -X^2

    return Qualite;
}

Listebit ajout_tete_bit(Listebit l, Bit new_value) {
    Listebit new = NULL;
    new = (Listebit) malloc (sizeof(Chaine_de_bit));
    new->bit= new_value;
    if (l == NULL) {
        new->next = NULL;
        return new;
    } else {
        new->next = l;
        return new;
    }
}

Listebit croise_lb(Listebit l1, Listebit l2, float pCroise) {
    float seuil = pCroise * 100;
    float proba;
    Bit tempo;
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    } else {
        while (l1 != NULL && l2 != NULL) {
            proba = rand() % 101;
            if (proba <= seuil) {
                tempo = l1->bit;
                l1->bit = l2->bit;
                l2->bit = tempo;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return l1;
    }
}



Listebit ajout_fin_bit(Listebit l, Bit new_value) {
    Listebit tempo;
    Listebit new;
    tempo = (Listebit) malloc(sizeof(Chaine_de_bit));
    new = (Listebit) malloc(sizeof(Chaine_de_bit));
    new->bit = new_value;
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
        printf("Liste vide ");
    }
    else {
        p=l;
        while (p->next != NULL) {
            printf("Bit %d \n", p->bit);
            p = p->next;
        }
        printf("Bit %d\n", p->bit);
    }
}

BOOL vide_lb(Listebit lb){
    if(lb->next==0||lb!=0||lb!=1){
        return true;
    }else{
        return false;
    }
}