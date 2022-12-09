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





#endif //LO21_PROJET_INDIVIDU_H
