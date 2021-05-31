#ifndef _JEUX_DE_MOTS_H_
#define _JEUX_DE_MOTS_H_

#include "liste.h"
#include "arbre_lexicographique_tab.h"
Lm_mot *trouver_les_mots_rec(char *lettres, PNoeudTab dico,char mot_en_cours[LONGUEUR_MAX_MOT], int i,Lm_mot * res );
Lm_mot *trouver_les_mots(char *lettres, PNoeudTab dico);
void le_mot_le_plus_long(char *lettres, PNoeudTab dico, char *res);
Lm_mot *mots_de_longueur_donnee(char *lettres, PNoeudTab dico, int l);
//Lm_mot *mots_de_longueur_donnee_rec(char *lettres, PNoeudTab dico,char mot_en_cours[LONGUEUR_MAX_MOT], int index,Lm_mot * res,int l);

#endif
