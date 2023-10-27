#include <stdlib.h>
#include "liste_bit.h"
#include "Individu.h"
#include <math.h>

#define longIndiv 8
#define longIndivmanip 16
#define pCroise 0.5
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



// 1.Initialiser aléatoirement la liste de bits (version recursive)

Listebit initialisation_liste_bits_recursive(int longeur_liste_bits) {
    Listebit l = NULL;
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
    if (l == NULL) { //Cas ou la liste est NULL.
        return 0;
    } else {
        while (l != NULL) { //Tant que liste est différent de NULL on fait boucler, on parcourt la liste case par case.
            value = value + (l->bit * powf(2, taille - i)); //Calcule de la valeur bit par bit suivant
            l = l->next; //Passage à la case suivante.
            i++;
        }
        return value;
    }
}

//Calcule la qualité d'un individu, prend en parametre la valeur de l'individu et sa taille.
double qualite_lb(int valeur) {
    double X;
    double Qualite;
    int A = -1, B = 1;
    X = (valeur / powf(2, longIndiv)) * (B - A) + A; //Calcule de X
    Qualite = -powf(X, 2); //Calcule de la fonction définie par f1(x) = -X^2
    return Qualite;
}

double qualite_manipulation(int valeur) {
    double X;
    double Qualite;
    double A = 0.1;
    int B = 5;
    X = (valeur / pow(2, longIndivmanip)) * (B - A) + A; //Calcule de X
    Qualite = -log(X); //Calcule de la fonction définie par f1(x) = -X^2
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

Listebit croise_lb(Listebit l1, Listebit l2) {
    double seuil = pCroise * 100;
    double proba;
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


