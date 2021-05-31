#include "utilitaires_tableaux.h"
#include <stdlib.h>
#include <stdio.h>



void triRapide(int tab[], int n) {
	if(n<=1)return;
	int i;
	int *TP=nouveau_tableau(n-1),*TG=nouveau_tableau(n-1),nbTP=0,nbTG=0;
	for(i=1;i<n;i++){
		if(tab[i]<tab[0]){
			TP[nbTP]=tab[i];nbTP++;
		}else{
			TG[nbTG]=tab[i];nbTG++;
		}}
	triRapide(TP,nbTP);
	triRapide(TG,nbTG);
	TP[nbTP]=tab[0];
	for(i=0;i<n;i++){
		if(i<=nbTP){tab[i]=TP[i];}
		else{tab[i]=TG[nbTG-n+i];}
	}
	detruire_tableau(TP);
	detruire_tableau(TG);
}



int partitionner(int tab[], int s, int n)
	{
      int i,p = s;
		for(i=s+1;i<=n;i++){
			if(tab[i]<=tab[s]){
				p++;
				echanger_elem_tab(tab,i,p);
			}
		}
				echanger_elem_tab(tab,s,p);
      return p;
	}

void triRapideAmeliore(int tab[], int s, int n)
	{
	if(s>=n)return;

	int piv = partitionner(tab,s,n);
	triRapideAmeliore(tab,s,piv-1);
	triRapideAmeliore(tab,piv+1,n);

	}
