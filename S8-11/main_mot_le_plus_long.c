#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commun.h"
#include "mot_le_plus_long.h"

#include "arbre_lexicographique_tab.h"
#include "liste.h"
int main() {

  char * s=malloc(50*sizeof(char));
  int longeur=0;
  char * longest = malloc(50*sizeof(char));
	PNoeudTab abdow=lire_dico("french_za");


  printf("caractere a rechercher : ");
  scanf(" %s",s);
  printf("longeur (-1 pour plus long mot): ");
  scanf("%d",&longeur);
  if(longeur == -1){

    le_mot_le_plus_long(s,abdow,longest);
    printf("mot plus long : %s \n",longest);
  }else{

    Lm_mot * liste = mots_de_longueur_donnee(s,abdow,longeur);
    afficher_Lmot(liste);
  }
  return 0;
}
