
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_lexicographique_tab.h"
#include "liste.h"
#include "mot_le_plus_long.h"

 int existe(char *lettres,char mot_en_cours[LONGUEUR_MAX_MOT]){
	int i=0;
	int j=0;
	while(mot_en_cours[i]!='\0'){
		j=0;
		while(lettres[j]!='\0'){
			if(lettres[j]==mot_en_cours[i]){
				return 1;
			}
			j++;
		}
		i++;
	}
	return 0;
}


Lm_mot *trouver_les_mots_rec(char *lettres, PNoeudTab dico,char mot_en_cours[LONGUEUR_MAX_MOT], int index,Lm_mot * res)
{
  if(dico->fin_de_mot==fin) {
    mot_en_cours[index]='\0';
    if(existe(lettres,mot_en_cours))
      res = ajouter_Lmot(res, mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    if (dico->fils[i]!=NULL) {
      mot_en_cours[index] = dico->fils[i]->lettre;
      res = trouver_les_mots_rec(lettres,dico->fils[i],mot_en_cours,index+1,res);
      
    }
  }
  return res;
}


Lm_mot *trouver_les_mots(char *lettres, PNoeudTab dico) {
  Lm_mot *res=NULL;
	char mot_courant[LONGUEUR_MAX_MOT];
	if(dico==NULL) return NULL;
	res = trouver_les_mots_rec(lettres,dico,mot_courant,0,NULL);
	return res;
}

void le_mot_le_plus_long(char *lettres, PNoeudTab dico, char *res) {
  Lm_mot * liste = trouver_les_mots(lettres,dico);
  Lm_mot * temp = liste;
 while(temp){
    if(strlen(temp->mot) > strlen(res))
      strcpy(res,temp->mot);
    temp = temp->suiv;
  }
  detruire_Lmot(liste);
    
}

/*
Lm_mot *mots_de_longueur_donnee_rec(char *lettres, PNoeudTab dico,char mot_en_cours[LONGUEUR_MAX_MOT], int index,Lm_mot * res,int l)
{
  if(dico->fin_de_mot==fin) {
    mot_en_cours[index]='\0';
    if((existe(lettres,mot_en_cours))&&(strlen(mot_en_cours)==l))
      res = ajouter_Lmot(res, mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    if (dico->fils[i]!=NULL) {
      mot_en_cours[index] = dico->fils[i]->lettre;
      res = mots_de_longueur_donnee_rec(lettres,dico->fils[i],mot_en_cours,index+1,res,l);
      
    }
  }
  return res;
}


Lm_mot *mots_de_longueur_donnee(char *lettres, PNoeudTab dico, int l) {
  Lm_mot *res=NULL;
	char mot_courant[LONGUEUR_MAX_MOT];
	if(dico==NULL) return NULL;
	res = mots_de_longueur_donnee_rec(lettres,dico,mot_courant,0,NULL,l);
	return res;
}
*/

Lm_mot *mots_de_longueur_donnee(char *lettres, PNoeudTab dico, int l) {
  Lm_mot * liste = trouver_les_mots(lettres,dico);
  Lm_mot * temp = liste;
  Lm_mot * res = NULL;
  while(temp){
    if(strlen(temp->mot) == l)
      res = ajouter_Lmot(res,temp->mot);
    temp = temp->suiv;
  }
  detruire_Lmot(liste);
  return res;
}

