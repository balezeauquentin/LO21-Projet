#include <stdio.h>
#include "Population.h"
#include "Individu.h"
#include "liste_bit.h"
#include <stdlib.h>
#include <time.h>


int main() {
    srand(time(NULL)); // initialisation du générateur aléatoire.
    Population p1;
    p1=Initialisationpop(5);
   // Afficher_population(p1);
    Listebit list=NULL;
    list= initialisation_liste_bits_recursive(2);
    afficher_list_bit(list);
    int seuil;

    int option=0;
      do{
          printf("1) ""Initialiser la Population\n");
          printf("2) Répéter nGen fois\n");
          printf("3) Début \n");
          printf("4) Croiser la Population \n");
          printf("5) Trier la Population \n");
          printf("6) Sélectionner la Population \n");
          printf("7) Fin \n");
          printf("8) Afficher le meilleur Individu de la Population \n");
          printf("0) Quitter \n");
          scanf(" %d",&option);
          switch (option) {
              case 1:
                  printf("-------------Initialisation-------------\n");
                  p1=Initialisationpop(5);
                  Afficher_population(p1);
                  break;

              case 2:


                  printf("-------------Repetition nGen fois-------------\n");

                  break;

              case 3:
                  printf("-------------");
                  break;

              case 4:
                  printf("-------------Croisement de la population-------------");
                  break;
              case 5:

                  break;
              case 6:

                  printf("Seuil :");
                  printf("-------------Selection de la population-------------");
                  scanf("%d",&seuil);
                  Selection(p1,seuil);
                  break;
              case 8:
                  break;
          }

      }while(option!=0);
    return 0;
}
