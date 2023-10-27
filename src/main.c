#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialisation du générateur aléatoire
    srand(time(NULL)); 

    Population pop, end;
    int taillePop = 0, tSelect = 0, nGen = 0;
    char fin = '0';
    do{

    
    // Saisie de la taille de la population avec validation
    do {
        printf("Taille de la population : \n");
        if (scanf("%d", &taillePop) != 1 || taillePop <= 0) {
            printf("Veuillez saisir une valeur valide et positive.\n");
            while (getchar() != '\n');  // Clear le buffer d'entrée
        }
    } while (taillePop <= 0);

    // Saisie du pourcentage d'individus sélectionnés avec validation
    do {
        printf("Nombre d'individus selectionnes (en pourcentage) : \n");
        if (scanf("%d", &tSelect) != 1 || tSelect < 0 || tSelect > 100) {
            printf("Veuillez saisir un pourcentage valide entre 0 et 100.\n");
            while (getchar() != '\n');  // Clear le buffer d'entrée
        }
    } while (tSelect < 0 || tSelect > 100);

    // Calcul du nombre d'individus sélectionnés en fonction du pourcentage
    tSelect = tSelect * taillePop / 100;

    // Saisie du nombre de générations avec validation
    do {
        printf("Nombre de generations : \n");
        if (scanf("%d", &nGen) != 1 || nGen <= 0) {
            printf("Veuillez saisir un nombre de générations valide et positif.\n");
            while (getchar() != '\n');  // Clear le buffer d'entrée
        }
    } while (nGen <= 0);

    // Initialisation de la population
    pop = Initialisationpop(taillePop);
    end = pop;

    // Boucle sur le nombre de générations
    for(int i = 0; i < nGen; i++){
        // Croisement de la population
        croise_pop(pop.indivs);

        // Déplacement du curseur pour avoir accès au dernier individu
        while(end.indivs->next != NULL){
            end.indivs = end.indivs->next;
        }

        // Trie de la population
        quicksort(pop.indivs, end.indivs);

        // Sélection des tSelect meilleurs individus
        Selection(pop, tSelect);
        i++;
    }

    // Affichage du meilleur individu
    Afficher_meilleur(pop);
    printf("Voulez-vous recommencer? (tapez '1' pour oui, autre chose pour non): ");
    scanf(" %c", &fin);
    }while(fin == '1');
    // Boucle jusqu'à ce que l'utilisateur décide de quitter

    return 0;
}