#include "ecosys.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_PROIES 20
#define NB_PREDATEURS 20

  /* Parametres globaux de l'ecosysteme (externes dans le ecosys.h)*/
float p_ch_dir=0.01;
float d_proie=1;
float d_predateur=1;
float p_manger=0.2;
float p_reproduce=0.01;
float energie=50;


int main(void) {

  srand(time(NULL));

  int i;
  Animal * liste_proie = NULL;
  for(i=0;i<NB_PROIES;i++)
   ajouter_animal((rand() % SIZE_X), (rand() % SIZE_Y), &liste_proie);

  Animal * liste_predateur = NULL;

  for(i=0;i<NB_PREDATEURS;i++)
   ajouter_animal((rand() % SIZE_X), (rand() % SIZE_Y), &liste_predateur);

  printf(" %d\n",compte_animal_rec(liste_proie));
  printf(" %d\n",compte_animal_it(liste_predateur));
  afficher_ecosys(liste_proie,liste_predateur);


  liberer_liste_animaux(liste_predateur);
  liberer_liste_animaux(liste_proie);
  
  return 0;
}
