#include <time.h>
#include <stdio.h>
//#include <stdlib.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"

#define longIndiv 8

Population Initialisationpop(int taille) {
    Liste_individu new_individu;
    new_individu = NULL;
    Population np; // nouvelle population
    int val_indiv;
    float qual_indiv;
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


int taille_population(Population pop) {
    int n_individus = 0;
    if (pop.indivs == NULL) {
        n_individus = 0;
    } else {

        while (pop.indivs != NULL) {
            n_individus = n_individus + 1;
            pop.indivs = pop.indivs->next;
        }
    }
    return n_individus;
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

Population Selection(Population pop, int tSelect) {
    Population trier;
    Population copie = pop;
    int i = 0;
    while (i < tSelect) {
        pop.indivs = pop.indivs->next;
        trier.indivs->prop.qualite = pop.indivs->prop.qualite;
        i++;
    }
    while (pop.indivs != NULL) {
        pop.indivs = pop.indivs->next;
        trier.indivs->prop.qualite = copie.indivs->prop.qualite;
        copie.indivs = copie.indivs->next;
    }
    Afficher_population(pop);
    Afficher_population(trier);
    Afficher_population(copie);
    return trier;
}

//fonction partition d'un quicksort de liste simplement chainée qui est de type Liste_individu qui prend en paramètre le début et la fin de la liste et le pivot qui est un double
Liste_individu partition(Liste_individu start, Liste_individu end, double pivot) {
    // On initialise les variables
    Liste_individu new_start = start;
    Liste_individu pivot_node = start;
    int i = 0;
    // On parcourt la liste tant que la qualité est differente du pivot
    while (pivot_node->prop.qualite != pivot) {
        pivot_node = pivot_node->next;
    }
    // On place le pivot à la fin de la liste
    int temp_valeur = pivot_node->prop.valeur;
    float temp_qualite = pivot_node->prop.qualite;
    Listebit temp_liste_de_bit = pivot_node->prop.liste_de_bit;

    pivot_node->prop.valeur = end->prop.valeur;
    pivot_node->prop.qualite = end->prop.qualite;
    pivot_node->prop.liste_de_bit = end->prop.liste_de_bit;

    end->prop.valeur = temp_valeur;
    end->prop.qualite = temp_qualite;
    end->prop.liste_de_bit = temp_liste_de_bit;
    printf("test 1");
    // On parcourt la liste
    while (start != end) {
        // Si l'élément est inférieur au pivot, on le place au début de la liste
        printf("test 1");
        if (start->prop.qualite < pivot) {
            printf("test 2");
            // On échange les valeurs
            temp_qualite = start->prop.qualite;
            temp_valeur = start->prop.valeur;
            temp_liste_de_bit = start->prop.liste_de_bit;
            start->prop.qualite = new_start->prop.qualite;
            start->prop.valeur = new_start->prop.valeur;
            start->prop.liste_de_bit = new_start->prop.liste_de_bit;
            new_start->prop.qualite = temp_qualite;
            new_start->prop.valeur = temp_valeur;
            new_start->prop.liste_de_bit = temp_liste_de_bit;
            // On avance le début de la liste
            new_start = new_start->next;
        }
        // On avance dans la liste
        if (start->next != NULL) {
            printf("reussi\n");
            start = start->next;
        } else {
            printf("aled\n");
            start = start->next;
        }
    }

    // On place le pivot à sa place
    temp_qualite = new_start->prop.qualite;
    temp_valeur = new_start->prop.valeur;
    temp_liste_de_bit = new_start->prop.liste_de_bit;
    new_start->prop.qualite = end->prop.qualite;
    new_start->prop.valeur = end->prop.valeur;
    new_start->prop.liste_de_bit = end->prop.liste_de_bit;
    end->prop.qualite = temp_qualite;
    end->prop.valeur = temp_valeur;
    end->prop.liste_de_bit = temp_liste_de_bit;

    // On retourne le pivot
    return new_start;
}


void quicksort(Liste_individu start, Liste_individu end) {
    // Si la liste est vide ou contient un seul élément, on retourne la liste

    printf("test 1");
    if (start == NULL || end == NULL || start == end || start->next == end) {
        return;
    }else if (start != NULL && start != end) {
        // On choisit un pivot
        double pivot = start->prop.qualite;

        // On partitionne la liste autour du pivot
        Liste_individu pivot_node = partition(start, end, pivot);

        // On trie la liste des éléments inférieurs au pivot
        quicksort(pivot_node->next, end);

        // On trie la liste des éléments supérieurs au pivot
        quicksort(start, pivot_node);
    }
}

Population croise_pop(Liste_individu l1) {
    int i = 0;
    Liste_individu copie = l1;
    copie = copie->next;
    Liste_individu croise = l1;
    Liste_individu pointeur = croise;
    Population new_pop;
    float qualite;
    int valeur;
    if(l1 == NULL) {
        new_pop.indivs = NULL;
        return new_pop;
    } else if (l1->next == NULL) {
        new_pop.indivs = l1;
        return new_pop;
    }
    while (copie != NULL || l1 != NULL) {

        if (copie == NULL) {
            printf("test 1");
            croise->prop.liste_de_bit = l1->prop.liste_de_bit;
            croise->prop.valeur = valeur_lb(croise->prop.liste_de_bit);
            croise->prop.qualite = qualite_lb(croise->prop.valeur);
            croise->next = NULL;
            croise = croise->next;
            l1 = l1->next;
        } else if (l1 == NULL) {
            printf("test 2");
            croise->prop.liste_de_bit = copie->prop.liste_de_bit;
            croise->prop.valeur = valeur_lb(croise->prop.liste_de_bit);
            croise->prop.qualite = qualite_lb(croise->prop.valeur);
            croise->next = NULL;
            croise = croise->next;
            copie = copie->next;
        } else {
            //croisement des listes de bits
            croise_lb(l1->prop.liste_de_bit, copie->prop.liste_de_bit, 0.5);
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
            if(copie->next == NULL){
               copie = copie->next;
            }else{
                copie = copie->next->next;
            }
            l1 = l1->next->next;
        }
    }
    new_pop.indivs = pointeur;
    return new_pop;
}


void programme(int n_generation) {
    Population pop;




}

void test(Liste_individu liste) {
    Liste_individu tempo = liste;
    int i = 1;
    while (tempo->next != NULL) {
        if (tempo->prop.qualite <= tempo->next->prop.qualite) {
            i++;
        }
        tempo = tempo->next;
    }
    if (i == 10) {
        printf("ok");
    } else {
        printf("pas ok");
    }
    printf("i = %d", i);

}