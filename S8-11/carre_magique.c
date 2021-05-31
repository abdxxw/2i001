#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "liste.h"
#include "carre_magique.h"
#include "arbre_lexicographique_tab.h"
#include "mot_le_plus_long.h"



void remplir_carre(char **carre, int l, int pos, PNoeudTab dico) {

  if (l==pos){
    int i,j;
    for(i=0;i<l;i++){
     for(j=0;j<l;j++){
      printf("%c ",carre[i][j]);
     }
     printf("\n");
    }

     printf("\n");

  }else{

    char * temp = malloc((pos+1)*sizeof(char));
    memcpy(temp,carre[pos],pos);
    temp[pos]='\0';
    Lm_mot * pref = mots_commencant_par(temp,dico,l);
    free(temp);
    while(pref){
      int i;
      for(i=pos;i<l;i++){
        carre[i][pos] = carre[pos][i] = pref->mot[i];
      }
      remplir_carre(carre,l,pos+1,dico);
      pref = pref->suiv;
    }
  }
    
  
}

void carre_magique (Lm_mot *dico, int l) {

  PNoeudTab dicoLong=NULL;

  Lm_mot *temp = dico;
  while(temp){

      dicoLong=ajouter_mot(dicoLong,temp->mot);
      temp = temp->suiv;
  }

    char ** carre = malloc(l*sizeof(char*));
    int i;
    for(i=0;i<l;i++)
      *(carre+i) = malloc(l*sizeof(char));
  while(dico){
    for(i=0;i<l;i++){
      carre[i][0] = carre[0][i] = dico->mot[i];
    }
    printf("========================================\n");
    printf("%s\n", dico->mot);
    printf("========================================\n");

    remplir_carre(carre,l,1,dicoLong);
    dico = dico->suiv;
  }
  
    for(i=0;i<l;i++)
      free(*(carre+i));

    free(carre);
  
}
