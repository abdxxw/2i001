#include <stdio.h>
#include "arbre_lexicographique.h"
#include <stdlib.h>
#include <time.h>
int main(int argc, char **argv) {
  PNoeud l=lire_dico("french_za");
  char mot1[]="abcde";
  char mot2[]="marin";
  int i;

  clock_t start = clock();
  for (i=0;i<atoi(argv[1]);i++) {
    rechercher_mot(l,mot1);
    rechercher_mot(l,mot2);
  }

  clock_t end = clock();
  printf("time used is %f seconds\n",(float) (end-start)/CLOCKS_PER_SEC);
  return 0;
}
