#include "liste_bit.h"

#ifndef LO21_PROJET_INDIVIDU_H
#define LO21_PROJET_INDIVIDU_H
typedef struct Individu {
    Listebit liste_de_bit;
    double valeur;
    double qualite;
    struct Individu *next;
} Individu;
typedef Individu *Liste_individu;

/*
 * InitailisationIdiv créé un individu avec une chaine de bit de longueur donnée.
 * La chaine de l'individu est de taille fixe mais les bits qui la compose ont une valeur
 * aléatoire entre 0 et 1. La fonction renvoie une liste de bit, cette liste de bit sera
 * utilisé pour définir notre individu.
 */
Listebit InitialisationIndiv(int longIndiv);

/*
 * La fonction ValeurIndiv prend la chaine de bit pour calculer sa valeur, c'est simplement
 * un changement de base 2 vers base 10. La fonction ValeurIndiv renvoie une valeur entiere.
 */
double ValeurIndiv(Listebit liste);

/*
 * QualiteIndiv prend en parametre la valeur de l'individu est la taille de sa chaine
 * de bit. Elle calcule la qualité d'un individu, la qualité d'un individu est définie
 * par la fonction suivante : f1(x) = -X^2 où X = (x/2^longIndiv )* (B−A)+ A, A=−1, B=1.
 */
double QualiteIndiv(double Valeur, int Taille);

Listebit Croise(Listebit l1, Listebit l2, float pCroise);

#endif //LO21_PROJET_INDIVIDU_H
