
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"
#include <assert.h>

/* Pour utiliser la correction automatique:
cavecorrector 6-7 repertoire
 */

Animal *creer_animal(int x, int y, float energie) {
  Animal * a = malloc(sizeof(Animal));
  a->x = x;
  a->y = y;
  a->energie = energie;
  a->dir[0] = (rand() % 3) -1;
  a->dir[1] = (rand() % 3) -1;
  a->precedent = NULL;
  a->suivant = NULL;
  return a;
} 

Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  animal->suivant = liste;
  animal->precedent = NULL;
  if(liste)
    liste->precedent = animal;

  return animal;
}

void ajouter_animal(int x, int y, Animal **liste_animal) {
  if((x<0)||(y<0)||(x>=SIZE_X)||(y>=SIZE_Y))
    return;
  Animal * a = creer_animal(x,y,energie);
  (*liste_animal) = ajouter_en_tete_animal((*liste_animal),a);

}


void enlever_animal(Animal **liste, Animal *animal) {
  assert(animal);
  assert(*liste);
  if(animal->precedent)
    animal->precedent->suivant = animal->suivant;
  if(animal->suivant)
    animal->suivant->precedent = animal->precedent;
  if(animal->precedent == NULL)
    *liste = animal->suivant;

  free(animal);

}

unsigned int compte_animal_rec(Animal *la) {
  if(la)
    return 1+compte_animal_rec(la->suivant);
  return 0;
}

unsigned int compte_animal_it(Animal *la) {
  int s=0;
  while(la){
    s+=1;
    la=la->suivant;
  }

  return s;
}

void bouger_animaux(Animal *la) {

  while(la){

    la->x=la->x-la->dir[0];
    la->y=la->y-la->dir[1];
    if(la->x < 0)
      la->x = SIZE_X-1;
    if(la->y < 0)
      la->y = SIZE_Y-1;
    if(la->x > SIZE_X)
      la->x = 0;
    if(la->y > SIZE_Y)
      la->y = 0;
    if((rand()/(float)RAND_MAX) < p_ch_dir){
      la->dir[0] = (rand() % 3) -1;
      la->dir[1] = (rand() % 3) -1;
    }

    la=la->suivant;
  }

}

void reproduce(Animal **liste_animal) {
  Animal * ani = *liste_animal;
    while(ani){
      if((rand()/(float)RAND_MAX) < p_reproduce)
        ajouter_animal(ani->x,ani->y,liste_animal);
      ani=ani->suivant;
  
    }
}

void rafraichir_proies(Animal **liste_proie) {

    
   Animal * ani = *liste_proie;
  bouger_animaux(ani);
  while(ani){
    ani->energie -=d_proie;
    if(ani->energie < 0)
      enlever_animal(liste_proie,ani);
    ani=ani->suivant;
    }
    reproduce(liste_proie);


}

Animal *animal_en_XY(Animal *l, int x, int y) {
  
  Animal * p = l;
  while(p){
    if((p->x == x)&&(p->y == y))
      return p;
    p=p->suivant;
  }
  return NULL;
} 

void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
     
   Animal *proie,* ani = *liste_predateur;

  bouger_animaux(ani);
  while(ani){
    ani->energie -=d_predateur;
    if(ani->energie < 0)
      enlever_animal(liste_predateur,ani);
    proie = animal_en_XY(*liste_proie,ani->x,ani->y);
    if(proie)
      if((rand()/(float)RAND_MAX) < p_manger)
        enlever_animal(liste_proie,proie);
    ani=ani->suivant;
    }
    reproduce(liste_predateur);


}


void afficher_ecosys(Animal *liste_proie,Animal *liste_predateur) {
  char s[SIZE_X][SIZE_Y];
    for(int i=0;i<SIZE_X;i++)
      for(int j=0;j<SIZE_Y;j++)
        s[i][j]= ' ';

    while(liste_proie){
      s[liste_proie->x][liste_proie->y] = '*';
      liste_proie=liste_proie->suivant;
    }
    while(liste_predateur){
      if(s[liste_predateur->x][liste_predateur->y] == '*')
        s[liste_predateur->x][liste_predateur->y] = '@';
      else if(s[liste_predateur->x][liste_predateur->y] != '@')
        s[liste_predateur->x][liste_predateur->y] = 'O';
    
      liste_predateur=liste_predateur->suivant;
    }

for(int i=0;i<SIZE_Y;i++)
      printf(" =");

 printf("\n");

  for(int i=0;i<SIZE_X;i++){

    printf("|");
    for(int j=0;j<SIZE_Y;j++)
      printf(" %c",s[i][j]);

   printf("|\n");
  }

    
for(int i=0;i<SIZE_Y;i++)
      printf(" =");

 printf("\n");
      

}

void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}



void liberer_liste_animaux(Animal * liste) {
  Animal * np = liste;
  if(!liste) return;
  assert(!liste->precedent);

 do{
    np = liste->suivant;
    free(liste);
    liste = np;
  } while(liste);
}