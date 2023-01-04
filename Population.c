#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"

#define longIndiv 8
#define longIndivmanip 16

Population Initialisationpop(int taille) {
    Liste_individu new_individu;
    new_individu = NULL;
    Population np; // nouvelle population
    int val_indiv;
    double qual_indiv;
    Listebit lb_indiv;
    for (int i = 0; i < taille; i++) {
        lb_indiv = initialisation_liste_bits(longIndiv);
        val_indiv = valeur_lb(lb_indiv);
        qual_indiv = qualite_lb(val_indiv);
        new_individu = ajout_fin_indiv(new_individu, lb_indiv, val_indiv, qual_indiv);
    }
    np.indivs = new_individu;
    return np;
}
void Afficher_meilleur(Population pop) {

    if (pop.indivs == NULL) {
        printf("Liste vide\n");
    } else {
        printf("Meilleur individu: valeur= %d qualite=%f\n", pop.indivs->prop.valeur, pop.indivs->prop.qualite);
    }
}
void Afficher_population(Population pop) {
    int i = 1;
    Liste_individu tempo;
    if (pop.indivs == NULL) {
        printf("Liste vide");
    } else {
        tempo = pop.indivs;
        while (tempo != NULL) {
            printf("Individu %d: valeur= %d qualite=%f\n", i, tempo->prop.valeur, tempo->prop.qualite);
            tempo = tempo->next;
            i++;
        }
    }
}
//fonction selection qui selection les tslelect premier individu de la population et qui complète le reste de la population avec les individus les plus qualifiés

void Selection(Population pop, int tSelect) {
    Population temp = pop;
    Population curseur = pop;
    Population copie = pop;
    if(tSelect < taille_pop(pop)) {
        int i = 1;
        //On avance tSelect fois dans la liste
        while (i < tSelect) {
            temp.indivs = temp.indivs->next;
            curseur.indivs = curseur.indivs->next;
            i++;
        }
        temp.indivs = temp.indivs->next;
        while (curseur.indivs->next != NULL) {
            temp.indivs->prop.liste_de_bit = copie.indivs->prop.liste_de_bit;
            temp.indivs->prop.qualite = copie.indivs->prop.qualite;
            temp.indivs->prop.valeur = copie.indivs->prop.valeur;
            curseur.indivs = curseur.indivs->next;
            temp.indivs = temp.indivs->next;
            copie.indivs = copie.indivs->next;
        }
    }
}

//fonction partition d'un quicksort de liste simplement chainée qui est de type Liste_individu qui prend en paramètre le début et la fin de la liste et le pivot qui est un double
Liste_individu partition(Liste_individu start, Liste_individu end, double pivot) {
    //Vérfication des paramètres
    if (start == NULL || end == NULL || start == end) {
        return start;
    }
    // On initialise les variables
    Liste_individu new_start = start;
    Liste_individu pivot_node = start;
    Liste_individu temp = start;
    // On parcourt la liste tant que la qualité est differente du pivot
    while (pivot_node->prop.qualite != pivot) {
        pivot_node = pivot_node->next;
    }
    // On place le pivot à la fin de la liste
    int temp_valeur = pivot_node->prop.valeur;
    double temp_qualite = pivot_node->prop.qualite;
    Listebit temp_liste_de_bit = pivot_node->prop.liste_de_bit;

    pivot_node->prop.valeur = end->prop.valeur;
    pivot_node->prop.qualite = end->prop.qualite;
    pivot_node->prop.liste_de_bit = end->prop.liste_de_bit;

    end->prop.valeur = temp_valeur;
    end->prop.qualite = temp_qualite;
    end->prop.liste_de_bit = temp_liste_de_bit;
    // On parcourt la liste
    if (temp == NULL) {
        return NULL;
    } else {
        while (temp != end && temp != NULL) {
            // Si l'élément est inférieur au pivot, on le place au début de la liste
            if (temp->prop.qualite > pivot) {
                // On échange les valeurs
                temp_qualite = temp->prop.qualite;
                temp_valeur = temp->prop.valeur;
                temp_liste_de_bit = temp->prop.liste_de_bit;
                temp->prop.qualite = new_start->prop.qualite;
                temp->prop.valeur = new_start->prop.valeur;
                temp->prop.liste_de_bit = new_start->prop.liste_de_bit;
                new_start->prop.qualite = temp_qualite;
                new_start->prop.valeur = temp_valeur;
                new_start->prop.liste_de_bit = temp_liste_de_bit;
                // On avance le début de la liste
                new_start = new_start->next;
            }
            // On avance dans la liste
            temp = temp->next;
        }
        // On place le pivot à sa place
        if(new_start != NULL){
            temp_qualite = new_start->prop.qualite;
            temp_valeur = new_start->prop.valeur;
            temp_liste_de_bit = new_start->prop.liste_de_bit;
            new_start->prop.qualite = end->prop.qualite;
            new_start->prop.valeur = end->prop.valeur;
            new_start->prop.liste_de_bit = end->prop.liste_de_bit;
            end->prop.qualite = temp_qualite;
            end->prop.valeur = temp_valeur;
            end->prop.liste_de_bit = temp_liste_de_bit;
        }

    }

    // On retourne le pivot
    return new_start;
}


void quicksort(Liste_individu start, Liste_individu end) {
    // Si la liste est vide ou contient un seul élément, on retourne la liste
    if (start == NULL || end == NULL || start == end || start->next == end) {
        return;
    } else {
        // On choisit un pivot
        double pivot = start->prop.qualite;

        // On partitionne la liste autour du pivot
        Liste_individu pivot_node = partition(start, end, pivot);
        if(pivot_node != NULL){
            // On trie la liste des éléments supérieurs au pivot
            quicksort(start, pivot_node);

            // On trie la liste des éléments inférieurs au pivot
            quicksort(pivot_node->next, end);
        }

    }
}

Population croise_pop(Liste_individu l1) {
    Population new_pop;
    Liste_individu copie = l1;
    Liste_individu croise = l1;
    Liste_individu pointeur = croise;
    copie = copie->next;
    double qualite;
    int valeur;
    if (l1 == NULL) {
        new_pop.indivs = NULL;
        return new_pop;
    } else if (l1->next == NULL) {
        new_pop.indivs = l1;
        return new_pop;
    }
    while (copie != NULL || l1 != NULL) {
        if (copie == NULL) {
            croise->prop.liste_de_bit = l1->prop.liste_de_bit;
            croise->prop.valeur = valeur_lb(croise->prop.liste_de_bit);
            croise->prop.qualite = qualite_lb(croise->prop.valeur);
            croise->next = NULL;
            l1 = l1->next;
        } else if (l1 == NULL) {
            croise->prop.liste_de_bit = copie->prop.liste_de_bit;
            croise->prop.valeur = valeur_lb(croise->prop.liste_de_bit);
            croise->prop.qualite = qualite_lb(croise->prop.valeur);
            croise->next = NULL;
            copie = copie->next;
        } else {
            //croisement des listes de bits
            croise_lb(l1->prop.liste_de_bit, copie->prop.liste_de_bit);
            //calcul de la valeur et de la qualité pour la l'individu impaire
            valeur = valeur_lb(l1->prop.liste_de_bit);
            qualite = qualite_lb(valeur);
            //ajout de l'individu impaire à la nouvelle liste d'individu
            croise->prop.liste_de_bit = l1->prop.liste_de_bit;
            croise->prop.valeur = valeur;
            croise->prop.qualite = qualite;
            //on avance dans la liste
            croise = croise->next;
            //calcul de la valeur et de la qualité pour la l'individu paire
            valeur = valeur_lb(copie->prop.liste_de_bit);
            qualite = qualite_lb(valeur);
            //ajout de l'individu paire à la nouvelle liste d'individu
            croise->prop.liste_de_bit = copie->prop.liste_de_bit;
            croise->prop.valeur = valeur;
            croise->prop.qualite = qualite;
            //on avance dans les listes
            croise = croise->next;
            if (copie->next == NULL) {
                copie = copie->next;
            } else {
                copie = copie->next->next;
            }
            l1 = l1->next->next;
        }
    }
    new_pop.indivs = pointeur;
    return new_pop;
}

int taille_pop(Population pop){
    int i = 0;
    while(pop.indivs != NULL){
        i++;
        pop.indivs = pop.indivs->next;
    }
    return i;
}
void test (Population pop){
    double temp;
    while(pop.indivs != NULL){
        temp = pop.indivs->prop.qualite;
        pop.indivs = pop.indivs->next;
        if(temp>pop.indivs->prop.qualite){
            printf("erreur");
        }
        pop.indivs = pop.indivs->next;
    }
}