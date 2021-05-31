#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "csvl.h"


int main(){

	int i;
	char * s = "mot1 et mot2 et mot3";
	

	printf("%d\n",compte_mots_chaine(s));

	char ** tMots = decompose_chaine(s);
	/*char ** tMots =malloc(6*sizeof(char*));
		for(i=0;i<5;i++)
			tMots[i] = malloc(6*sizeof(char));

	tMots[0] = strcpy(tMots[0], "mot1");
	tMots[1] = strcpy(tMots[1], "et");
	tMots[2] = strcpy(tMots[2], "mot2");
	tMots[3] = strcpy(tMots[3], "et");
	tMots[4] = strcpy(tMots[4], "mot3");
	tMots[5] = NULL; */

	printf("%d\n",compte_mots(tMots));
	affiche_tab_mots(tMots);

	s= compose_chaine(tMots);
	printf("%s\n",s);
	tMots = reduit_tab_mots(tMots);
	affiche_tab_mots(tMots);

return 0;
}
