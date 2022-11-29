#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Individu.h"
#include "liste_bit.h"

//Cette fonction permet de créé un individu de manière aléatoire et avec une longueur donnée.
Listebit InitialisationIndiv(int longIndiv) {
    Listebit l = NULL;
    int i = 0;
    srand(time(NULL)); // initialisation du générateur aléatoire.
    if (longIndiv == 0) {         //Si la longueur est égale à 0, renvoyé l vide.
        return l;
    } else if (longIndiv == 1) { //Si longueur égale à 1.
        Bit valeur = rand() % 2; //Initialisation de "valeur" avec un chiffre aléatoire entre 0 et 1.
        l = ajout_tete_bit(l, valeur); //Ajout en tête de liste la valeur.
        return l;
    } else {
        while (i < longIndiv) { //Répétition n fois de la boucle pour que la chaine soit de la bonne taille.
            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            i++; //Incrementation de la valeur i pour ne pas avoir une boucle infinie.
        }
        return l;
    }
}

//Calcule la valeur d'un individu avec une liste de bit donnée.
double ValeurIndiv(Listebit l) {
    int taille = taille_liste_bit(l); //Recupération de la taille de la liste chainée.
    double value = 0;
    int i = 1;
    if (taille == 0) { //Cas ou la liste est NULL.
        return 0;
    } else {
        while (l != NULL) { //Tant que liste est différent de NULL on fait boucler, on parcourt la liste case par case.
            value = value + (l->valeur * pow(2, taille - i)); //Calcule de la valeur bit par bit suivant
            // l'emplacement du bit et la taille de la chaine.
            printf("valeur de la chaine : %f valeur du bit : %d valeur de la taille : %d emplacement : %d\n", value,
                   l->valeur, taille - i, i);
            l = l->next; //Passage à la case suivante.
            i++;
        }
        return value;
    }
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


Liste_individu ajout_fin_indiv(Liste_individu l, Bit new_value) {
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


