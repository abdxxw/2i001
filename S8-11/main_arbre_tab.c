#include <stdlib.h>
#include <stdio.h>
#include "arbre_lexicographique_tab.h"
#include <time.h>

int main(int argc, char **argv) {

	PNoeudTab abdow=lire_dico("french_za");
	char *mot1 = "abcde";
	char *mot2 = "marin";
	int i;
	int pm1;
	int pm2;
	int nbr;
	
	if (argc != 2)
		{
		fprintf(stderr, "Usage : main_arbre_tab nb_recherches\n");
		exit(1);
		}
	
	nbr = atoi(argv[1]);
	

	printf("-------- Arbre Lexico construit --------\n");
	afficher_dico(abdow);
    clock_t start = clock();
  
	for (i=0;i<nbr;i++) {
		pm1 = rechercher_mot(abdow,mot1);
		pm2 = rechercher_mot(abdow,mot2);
	}

  clock_t end = clock();

	if ((pm1 == 0) && (pm2 != 0))
	 	printf("Resultat recherche OK!\n");
	else
	 	printf("Resultat eronne KO!\n");

  	printf("time used is %f seconds\n",(float) (end-start)/CLOCKS_PER_SEC);
	detruire_dico(abdow);
	return 0;
}
