#ifndef _CARRE_MAGIQUE_H_
#define _CARRE_MAGIQUE_H_

#include "liste.h"
#include "arbre_lexicographique_tab.h"
#include "mot_le_plus_long.h"

void remplir_carre(char **carre, int l, int pos, PNoeudTab dico);
void carre_magique (Lm_mot *dico, int l);

#endif
