#include <stdlib.h>
#include "noyau.h"
#include <stdio.h>
#include <string.h>

#define TMP_STR_SIZE 128

noyau_t *creer_noyau(unsigned int dim)
	{
		noyau_t * temp = malloc(sizeof(noyau_t));
		temp->dim = dim;
		temp->coeffs = malloc(dim*dim*sizeof(int));
	return temp;
	}

void detruire_noyau(noyau_t *pn)
	{
		if(pn!=NULL){
			if(pn->coeffs != NULL)
				free(pn->coeffs);
			free(pn);
		}
	}

noyau_t *charger_noyau(char *nom_fichier)
	{
		unsigned int dim;
		
		noyau_t * temp = NULL;
		FILE * f = fopen(nom_fichier,"r");
		fscanf(f,"%u",&dim);
		if(dim % 2 == 0)
			fprintf(stderr,"INVALID DIM\n");
		else{
			temp = creer_noyau(dim);
			for(int i=0;i<dim;i++){
				for(int j =0;j<dim;j++)
					fscanf(f, " %d ", &(VAL_N(temp,i,j)));
			}
			

		}
		fclose(f);
	return temp;
	}
