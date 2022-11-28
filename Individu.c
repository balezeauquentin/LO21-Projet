#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Individu.h"
#include "liste.h"

Listebit InitialisationIndiv(int longIndiv) {
    Listebit l = NULL;
    int i = 0;
    srand(time(NULL));
    if (longIndiv == 0) {
        return l;
    } else if (longIndiv == 1) {
        Bit valeur = rand() % 2;
        l = ajout_tete_bit(l, valeur);
        return l;
    } else {
        while (i < longIndiv) {
            Bit valeur = rand() % 2;
            l = ajout_tete_bit(l, valeur);
            i++;
        }
        return l;
    }
}

double ValeurIndiv(Listebit l) {
    int taille = taille_liste_bit(l);
    double value = 0;
    int i = 1;
    if (taille == 0) {
        return 0;
    } else {
        while (l != NULL) {
            value = value + (l->valeur * pow(2, taille - i));
            printf("valeur de la chaine : %f valeur du bit : %d valeur de la taille : %d emplacement : %d\n", value,
                   l->valeur, taille - i, i);
            l = l->next;
            i++;
        }
        return value;
    }
}

double QualiteIndiv(double valeur, int taille) {
    double X;
    double Qualite;
    int A = -1, B = 1;
    X = (valeur / pow(2, taille) * (B-A) + A);
    Qualite = -pow(X,2);
    return Qualite;
}
