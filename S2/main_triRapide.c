#include <stdio.h>
#include "utilitaires_tableaux.h"
#include "tri_rapide.h"
#define T 8



int main(){
	int tab[T];
	init_tab_alea(tab,T);
	afficher_tab(tab,T);
	printf("Sorting.....\n");
	triRapide(tab,T);
	afficher_tab(tab,T);
	if(tab_trie(tab,T)){printf("Sort Successfull\n");}
	else{printf("Sort Failed\n");}
	return 0;
}

