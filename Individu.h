#include "liste_bit.h"
#define true 1;
#define false 0;


#ifndef LO21_PROJET_INDIVIDU_H
#define LO21_PROJET_INDIVIDU_H
typedef struct Individu {
    Listebit liste_de_bit;
    int valeur;
    float qualite;
    struct Individu *next;
} Individu;
typedef Individu *Liste_individu;

typedef int BOOL;
int vide(Liste_individu li);

/*
 * InitailisationIdiv créé un individu avec une chaine de bit de longueur donnée.
 * La chaine de l'individu est de taille fixe mais les bits qui la compose ont une valeur
 * aléatoire entre 0 et 1. La fonction renvoie une liste de bit, cette liste de bit sera
 * utilisé pour définir notre individu.
 */
Individu InitialisationIndiv(int longIndiv);
Liste_individu ajout_fin_indiv(Liste_individu l,Listebit lb,int valeur,float qualite);
/*
 * La fonction ValeurIndiv prend la chaine de bit pour calculer sa valeur, c'est simplement
 * un changement de base 2 vers base 10. La fonction ValeurIndiv renvoie une valeur entiere.
 */





#endif //LO21_PROJET_INDIVIDU_H
