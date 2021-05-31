#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int val_max = 1000000;


void init_tab_alea(int tab[], int n)
	{
	int i;
	for (i = 0; i < n; i++)
		tab[i] = (int) (rand() % val_max);
	}

void afficher_tab(int tab[], int n)
	{
	int i;
	for (i = 0; i < n; i++)
		{
		printf("%6d ", tab[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
		}
	printf("\n");
	}

void copier_tab(int tabSrc[], int tabDest[], int n)
	{
	int i;
	for (i = 0; i < n; i++)
		tabDest[i] = tabSrc[i];
	}

void echanger_elem_tab(int tab[], int i, int j)
	{
	int t = tab[i];
	tab[i] = tab[j];
	tab[j] = t;
	}

int tab_trie(int tab[], int n)
	{
	int i;
	for (i = 1; i < n; i++)
		if( tab[i] < tab[i-1])
			return 0;
	return 1;
	}

int *nouveau_tableau(int n) {
  int *nt = malloc(sizeof(int)*n);
  if (nt==NULL) {
    printf("Erreur lors de la creation d'un tableau (taille=%d)\n",n);
    exit(1);
  }
  return nt;
}

void detruire_tableau(int *n) {
  free(n);
}
