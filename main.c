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


    int option=0;

    /*
      do{
  
          printf("1) \n""Initialiser la Population\n");
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
                  printf("Mot a ajouter ");
                  p1=Initialisationpop(5);
                  Afficher_population(p1);
                  break;

              case 2:
                  printf("Mot a ajouter ");
                  l=insertion_queue(l);
                  break;

              case 3:
                  l= supprimer_tete(l);
                  break;

              case 4:
                  p1=
                  break;
              case 5:
                  p1= Quick_sort_population(p1);
                  break;
              case 6:
                  p1= Selection(p1,)
                  break;
              case 8:
                  l= supprimer_queue(l);
                  break;
          }

      }while(option!=7);


  */
    return 0;
}
