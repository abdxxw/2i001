#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "abr.h"
#include <time.h>

int main(int argc, char **argv)
{
  
   int i;
  Lm_mot * liste_m = lire_dico_Lmot("french_za");
  Nd_mot * arbre_m = Lm2abr(liste_m);
  
  Nd_mot * in = chercher_Nd_mot(arbre_m,"meditait");
  Nd_mot * notin = chercher_Nd_mot(arbre_m,"hhehehehhgere");

  if(in)
    printf("%s\n",in->mot);
  else
    printf("NOT FOUND\n");

  if(notin)
    printf("%s\n",notin->mot);
  else
    printf("NOT FOUND\n");

  clock_t start = clock();
  for(i=0;i<atoi(argv[1]);i++){
    in = chercher_Nd_mot(arbre_m,"meditait");
    notin = chercher_Nd_mot(arbre_m,"hhehehehhgere");
  }

  clock_t end = clock();

  	printf("time used is %f seconds\n",(float) (end-start)/CLOCKS_PER_SEC);

    detruire_abr_mot(arbre_m);
  return 0;
}
