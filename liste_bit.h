#ifndef LO21_PROJET_LISTE_H
#define LO21_PROJET_LISTE_H

typedef unsigned char Bit;

typedef struct Chaine_de_bit {
    Bit valeur;
    struct Chaine_de_bit *next;
} Chaine_de_bit;
typedef Chaine_de_bit *Listebit ;

Listebit  initialisation_liste_bits(int longeur_liste_bites);

Listebit ajout_tete_bit(Listebit l, Bit new_value);

Listebit  ajout_fin_bit(Listebit l, Bit new_value);

Listebit  supp_tete_bit(Listebit l);

Listebit  supp_fin_bit(Listebit l);
int taille_liste_bit(Listebit l);
void afficher_list_bit(Listebit  l);

#endif //LO21_PROJET_LISTE_H
