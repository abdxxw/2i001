#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "arbre_lexicographique_tab.h"


PNoeudTab creer_noeud(char lettre) {
    
  PNoeudTab pn=(PNoeudTab)malloc(sizeof(NoeudTab));
  if (pn==NULL) {
    printf("Impossible d'allouer un noeud\n");
    return NULL;
  }
 
  pn->lettre=lettre;
  pn->fin_de_mot=non_fin;
  for(int i =0; i<26;i++)
    pn->fils[i]=NULL;
  return pn;
  
}

PNoeudTab ajouter_mot(PNoeudTab racine, char *mot) {
  
  if(mot == NULL)
    return racine;
  if(racine == NULL)
    racine = creer_noeud('.');
  if(*mot != '\0'){
     
    if(racine->fils[*mot-'a'] == NULL)
      racine->fils[*mot-'a'] = creer_noeud(*mot);

    racine->fils[*mot-'a'] = ajouter_mot(racine->fils[*mot-'a'], mot+1);
  }
  if(*mot == '\0')
    racine->fin_de_mot=fin;
  
  return racine;
}

void afficher_mots(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], int index) {
  if (n==NULL)
    return;

  if(n->fin_de_mot==fin) {
    mot_en_cours[index]='\0';
    printf("%s\n",mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    // On affiche les fils
    if (n->fils[i]!=NULL) {
      mot_en_cours[index] = n->fils[i]->lettre;
      afficher_mots(n->fils[i],mot_en_cours,index+1);
    }
  }
}

void afficher_dico(PNoeudTab racine) {
  
  char mot_en_cours[LONGUEUR_MAX_MOT];
  afficher_mots(racine,mot_en_cours,0);
  
}

void detruire_dico(PNoeudTab dico) {
   if (dico!=NULL) {
     for(int i=0;i<26;i++){
      if(dico->fils[i] !=NULL){
        detruire_dico(dico->fils[i]);
      }
     }
        
    free(dico);
  }
  
}

int rechercher_mot(PNoeudTab dico, char *mot) {
  
  if(dico == NULL)
    return 0;
  if(mot == NULL)
    return 0;
  
  if(dico->fils[*mot-'a'] == NULL)
    return 0;
  
  if (strlen(mot)==1) 
    return dico->fils[*mot-'a']->fin_de_mot == fin;

  return rechercher_mot(dico->fils[*mot-'a'],mot+1);
}

PNoeudTab lire_dico(const char *nom_fichier) {
  
  FILE *f=fopen(nom_fichier,"r");
  if (f==NULL) {
    printf("Impossible d'ouvrir le fichier %s\n",nom_fichier);
    return NULL;
  }
  char ligne[LONGUEUR_MAX_MOT];
  PNoeudTab dico=NULL;

  while(!feof(f)) {
    if (!fgets(ligne,LONGUEUR_MAX_MOT, f)) {
      break;
    }
    ligne[strlen(ligne)-1]='\0'; // pour enlever le '\n' final
    if (strlen(ligne)>=1) {
      dico=ajouter_mot(dico,ligne);
    }
  }
  fclose(f);
  
  return dico;
}

Lm_mot *tous_les_mots_longueur_donnee_rec(PNoeudTab n, char mot_en_cours[LONGUEUR_MAX_MOT], 
                                                 int index, int l, Lm_mot *res) {
  
  if(n->fin_de_mot==fin) {
    mot_en_cours[index]='\0';
    if(strlen(mot_en_cours) == l)
      res = ajouter_Lmot(res, mot_en_cours);
  }

  int i;
  for(i=0;i<26;i++) {
    if (n->fils[i]!=NULL) {
      mot_en_cours[index] = n->fils[i]->lettre;
      res = tous_les_mots_longueur_donnee_rec(n->fils[i],mot_en_cours,index+1,l,res);
      
    }
  }
  return res;

}

Lm_mot *tous_les_mots_longueur_donnee(PNoeudTab racine, int l) {
  
   Lm_mot *res=NULL;
	char mot_courant[LONGUEUR_MAX_MOT];
	if(racine==NULL) return NULL;
	res = tous_les_mots_longueur_donnee_rec(racine,mot_courant,0,l,NULL);
	return res;

}

Lm_mot *mots_commencant_par(const char *mot_a_completer, PNoeudTab dico, int l) {


  Lm_mot * liste = tous_les_mots_longueur_donnee(dico,l);
  Lm_mot * temp = liste;
  Lm_mot * res = NULL;
  int x = strlen(mot_a_completer);
  while(temp){
    if(strncmp(temp->mot,mot_a_completer,x) == 0)
      res = ajouter_Lmot(res,temp->mot);
    temp = temp->suiv;
  }
  detruire_Lmot(liste);
  return res;

}
