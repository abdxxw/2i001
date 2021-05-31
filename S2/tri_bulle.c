#include "utilitaires_tableaux.h"

void triBulle(int tab[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(tab[j]>tab[j+1]){
				echanger_elem_tab(tab,j,j+1);
			}
		}
	}
}

void triBulleAmeliore(int tab[], int n)
{	
	int x=1;
	int i,j;
	for(i=0;(i<n-1)&&(x);i++){
		x=0;
		for(j=0;j<n-i-1;j++){
			if(tab[j]>tab[j+1]){
				echanger_elem_tab(tab,j,j+1);
				x=1;
			}
		}
	}
			
}

