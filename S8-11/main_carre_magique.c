
#include <stdio.h>
#include "carre_magique.h"
#include "liste.h"

int main() {


	PNoeudTab abdow=lire_dico("french_za");
  int x;
  printf("Taille : \n");
  scanf("%d",&x);
  Lm_mot * test = tous_les_mots_longueur_donnee(abdow,x);
  afficher_Lmot(test);
  carre_magique(test,x);
  
  return 0;
}
