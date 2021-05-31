#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include <time.h>

int main(int argc, char **argv)
{
  int i;
  Lm_mot * liste_m = lire_dico_Lmot("french_za");

  Lm_mot * in = chercher_Lm_mot(liste_m,"meditait");
  Lm_mot * notin = chercher_Lm_mot(liste_m,"hehehegeerge");

  if(in)
    printf("%s\n",in->mot);
  else
    printf("NOT FOUND\n");

  if(notin)
    printf("%s\n",in->mot);
  else
    printf("NOT FOUND\n");

 
  clock_t start = clock();
  for(i=0;i<atoi(argv[1]);i++){
    in = chercher_Lm_mot(liste_m,"meditait");
    notin = chercher_Lm_mot(liste_m,"hehehegeerge");
  }


  clock_t end = clock();

  printf("time used is %f seconds\n",(float) (end-start)/CLOCKS_PER_SEC);

  return 0;
}
